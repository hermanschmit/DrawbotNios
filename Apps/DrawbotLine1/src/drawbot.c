#include <stdio.h>
#include <math.h>
#include "drawbot.h"
#include "drawbot_util.h"

// xlim: total width of base relative to increment
static float XLIM = 1.0f;

// SCALE is portion of total base width used by the drawbot
// 0.6 fits on width of 18" paper with 25" base
// 0.72 as wide as possible
static float SCALE = 0.75f;
// Assumes 25 inch base and 18 wide paper

// MICROSTEP 0-3
static int MICROSTEP = 0x0;

// INCR increment using MICROSTEP of 3 --> factor of 8
/* Measurement: 5000 ticks in 12", base 25", 10416 ticks -> 0.000096 */
/* Measurement: 5000 ticks in 12", base 25", carriage 2", 9583 ticks -> 0.000104 */
/* 0.000104 * 8 = 0.000832 */
// float INCR = 0.000832 / ((float) (1 << MICROSTEP));
static float INCRBASE = 0.000832;
static float INCR     = 0.000832;

static float YOFFSET = 0.09f;

// int DELAYCOUNT = 40000 >> MICROSTEP;
// 40000 is slow
// 15000 is nice
static int DELAYCOUNTBASE = 15000;
static int DELAYCOUNT     = 15000;

static float MAX_RATIO = 20.0f;

static float SPOOL_RATIO = 0.1f;
//static float SPOOL_RATIO = 0.04f;
//static float SPOOL_RATIO = 0.1f;
//static float SPOOL_RATIO = 0.2f;

//static float SPOOL_RATIO = 0.0198f;
// Spool is 1" diameter, 3.14" circumf
// String is 1/16"
// Ratio = String width / circumf

static float DLIM = 1.4128f;
static float W2P1; // = (SPOOL_RATIO*SPOOL_RATIO+1);
static float D2W2; // = DLIM*DLIM*SPOOL_RATIO*SPOOL_RATIO;
static float DW2; // = DLIM*SPOOL_RATIO*SPOOL_RATIO;


/*
static void updateNextLoc(float ll, float lr, float xlim, float *x_next, float *y_next, float y_offset)
{
	*x_next = (ll * ll - lr * lr + xlim * xlim) / (2 * xlim);
	*y_next = sqrtf(ll * ll - *x_next * *x_next) - y_offset;
}
*/

static void updateNextLoc(float f, float g, float xlim, float *x_next, float *y_next)
{
	//float w2p1 = (SPOOL_RATIO*SPOOL_RATIO+1);
	//float d2w2 = DLIM*DLIM*SPOOL_RATIO*SPOOL_RATIO;
	*x_next =
			(2.f * DW2 * (sqrtf(f*f*W2P1 - D2W2) -
			              sqrtf(g*g*W2P1 - D2W2)) +
			(f * f - g * g) * W2P1 +
			xlim * xlim * W2P1 * W2P1) /
			(2.f * xlim * W2P1 * W2P1);
	float tmp = DW2 + sqrtf(f*f*W2P1-D2W2);
	*y_next =
			sqrtf((tmp*tmp)/(W2P1*W2P1) - *x_next * *x_next) - YOFFSET;
}

void updateLen(float *f, float *g, float xlim, float x, float y)
{
	float y2 = y + YOFFSET;
	*f = sqrtf(D2W2 + W2P1*x*x + W2P1*y2*y2 - 2.0f * DW2 * sqrtf(x*x+y2*y2));
	float x2 = xlim-x;
	*g = sqrtf(D2W2 + W2P1*x2*x2 + W2P1*y2*y2 - 2.0f * DW2 * sqrtf(x2*x2+y2*y2));
}


static float delta(int del, float increment) {
	if (del > 0)       return ( 1.0F * increment);
	else if (del < 0)  return (-1.0F * increment);
	else               return (0.0F);
}

static void move(
		int del_l, int del_r, int commit,
		float increment,
		float *len_l, float *len_r,
		float *x_cur, float *y_cur,
		float *x_next, float *y_next,
		float xlim,
		int delay
)
{
	float delta_r,delta_l;
	float lr, ll;

	if (del_r>1 || del_r<-1) {
		printf("UhOh R: %d\n",del_r);
		if (del_r > 1) del_r = 1;
		else del_r = -1;
		//return;
	}
	if (del_l>1 || del_l<-1) {
		printf("UhOh L: %d\n",del_l);
		if (del_l > 1) del_l = 1;
		else del_l = -1;
		//return;
	}

	delta_r = delta(del_r,increment);
	delta_l = delta(del_l,increment);

	lr = *len_r + delta_r;
	ll = *len_l + delta_l;

	updateNextLoc(ll, lr, xlim, x_next, y_next);

	if (commit)
	{
		*x_cur = *x_next;
		*y_cur = *y_next;
		*len_l = ll;
		*len_r = lr;
		move_DB(del_l,del_r,delay);
	}
}

static float delay_ratio(float r, float inc) {
	float STEPS = 400;
	float r1 = r/inc;
	float r2 = (1.0f-r)/inc;
	float r_min = (r1<r2) ? r1:r2;
	if (r_min > STEPS) return 1.0f;
	r_min = (r_min<=0.f)?1.0f:r_min;
	float d1 = 1.0f/sqrtf(r_min/STEPS);
	d1 = (d1>MAX_RATIO)?MAX_RATIO:d1;
	return d1;
}

static int moveTarget2(
		float x0, float y0,
		float xn, float yn,
		float *x_cur, float *y_cur,
		float *x_next, float *y_next,
		float xlim,
		float *len_l, float *len_r,
		float increment,
		int delay) {

	int len_l_i = (int) roundf(*len_l/increment);
	int len_r_i = (int) roundf(*len_r/increment);

	float delta_x = (xn-x0);
	float delta_y = (yn-y0);

	float r_steps = 2.0f * ((fabsf(delta_x) > fabsf(delta_y)) ? (fabsf(delta_x)/increment) : (fabsf(delta_y)/increment));
	float r_inc = 1.0f/r_steps;
	float r;
	for(r = 0.0; r <= 1.0; r+=r_inc) {
		float y1 = (delta_y * r + y0);
		float x1 = (delta_x * r + x0);

		float f,g;
		updateLen(&f,&g,xlim,x1,y1);
		//float f = sqrtf(x1*x1 + y1*y1);
		//float g = sqrtf(x2*x2 + y1*y1);

		int f_i = (int) round(f/increment);
		int g_i = (int) round(g/increment);
		//int f3_i = (int) round(f3/increment);
		//int g3_i = (int) round(g3/increment);
		//printf("%d %d   %d %d\n",f_i,f3_i,g_i,g3_i);

		int del_f = f_i-len_l_i;
		int del_g = g_i-len_r_i;

		int d = delay * delay_ratio(r,r_inc);

		if (fabsf(del_f) > 0 || fabsf(del_g) > 0) {
			// should only equal +1 or -1
			// commit
			move(del_f,
					del_g,
					1,
					increment,
					len_l, len_r,
					x_cur, y_cur,
					x_next, y_next,
					xlim,
					d);
			len_l_i = f_i;
			len_r_i = g_i;

		}

	}
	return 0;

}

void ZeroDB(int ms) {
	MICROSTEP = ms;
	INCR = INCRBASE / ((float) (1 << MICROSTEP));
	DELAYCOUNT = DELAYCOUNTBASE >> MICROSTEP;
	W2P1 = (SPOOL_RATIO*SPOOL_RATIO+1);
	D2W2 = DLIM*DLIM*SPOOL_RATIO*SPOOL_RATIO;
	DW2 = DLIM*SPOOL_RATIO*SPOOL_RATIO;

	init_DB(MICROSTEP);
}

void Shape(
		point *shape_array,
		float x_center, float y_center,
		float *x_cur, float *y_cur,
		float *len_l, float *len_r
		)
{
	point *pt = shape_array;

	float x0 = *x_cur;
	float y0 = *y_cur;
	float y_next,x_next;

	while (!isnan((*pt)[0])) {
		float tx = (*pt)[0] * SCALE/2 + x_center;
		float ty = (*pt)[1] * SCALE/2 + y_center;
		while (moveTarget2(
					x0,y0,
					tx,ty,
					x_cur, y_cur,
					&x_next, &y_next,
					XLIM,
					len_l, len_r,
					INCR,
					DELAYCOUNT));
		x0 = *x_cur;
		y0 = *y_cur;
		pt++;
	}

}
