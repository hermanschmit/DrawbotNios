#include <stdio.h>
#include <math.h>
#include "drawbot.h"
#include "drawbot_util.h"




static void updateNextLoc(float ll, float lr, float xlim, float *x_next, float *y_next, float y_offset)
{
	*x_next = (ll * ll - lr * lr + xlim * xlim) / (2 * xlim);
	*y_next = sqrtf(ll * ll - *x_next * *x_next) - y_offset;
}

static float delta(int del, float increment) {
	if (del > 0)       return ( 1.0F * increment);
	else if (del < 0)  return (-1.0F * increment);
	else               return (0.0F);
}

static void move(
		int del_l, int del_r, int commit,
		float increment, float y_offset,
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
		printf("UhOh R\n");
	}
	if (del_l>1 || del_l<-1) {
		printf("UhOh L\n");
	}

	delta_r = delta(del_r,increment);
	delta_l = delta(del_l,increment);

	lr = *len_r + delta_r;
	ll = *len_l + delta_l;

	updateNextLoc(ll, lr, xlim, x_next, y_next, y_offset);

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
		float y_offset,
		int delay) {

	int len_l_i = (int) roundf(*len_l/increment);
	int len_r_i = (int) roundf(*len_r/increment);

	float delta_x = (xn-x0);
	float delta_y = (yn-y0);

	float r_steps = 2.0f * ((fabsf(delta_x) > fabsf(delta_y)) ? (fabsf(delta_x)/increment) : (fabsf(delta_y)/increment));
	float r_inc = 1.0f/r_steps;
	float r;
	for(r = 0.0; r <= 1.0; r+=r_inc) {
		float y1 = (delta_y * r + y0) + y_offset;
		float x1 = (delta_x * r + x0);
		float x2 = xlim - x1;

		float f = sqrtf(x1*x1 + y1*y1);
		float g = sqrtf(x2*x2 + y1*y1);

		int f_i = (int) round(f/increment);
		int g_i = (int) round(g/increment);

		int del_f = f_i-len_l_i;
		int del_g = g_i-len_r_i;

		int d = delay * delay_ratio(r,r_inc);

		if (fabsf(del_f) > 0 || fabsf(del_g) > 0) {
			// should only equal +1 or -1
			// commit
			move(del_f,
					del_g,
					1,
					increment, y_offset,
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


void Shape(
		point *shape_array,
		float scale,
		float x_center, float y_center,
		float *x_cur, float *y_cur,
		float xlim,
		float *len_l, float *len_r,
		float increment, float y_offset,
		int delay
)
{
	point *pt = shape_array;

	float x0 = *x_cur;
	float y0 = *y_cur;
	float y_next,x_next;

	while (!isnan((*pt)[0])) {
		float tx = (*pt)[0] * scale/2 + x_center;
		float ty = (*pt)[1] * scale/2 + y_center;
		while (moveTarget2(
					x0,y0,
					tx,ty,
					x_cur, y_cur,
					&x_next, &y_next,
					xlim,
					len_l, len_r,
					increment, y_offset,
					delay));
		x0 = *x_cur;
		y0 = *y_cur;
		pt++;
	}

}