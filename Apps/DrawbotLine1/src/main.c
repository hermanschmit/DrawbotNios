/*
 * main.c
 *
 *  Created on: May 28, 2014
 *      Author: herman
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "system.h"
#include "drawbot.h"
#include "drawbot_util.h"
#include "altera_avalon_pio_regs.h"

static void clear_mem(int image_size, float *image)
{
	int count;
	float *ptr;
	// Clear memory
	for (count = 0, ptr = image; count < image_size; count++, ptr++)
		*ptr = NAN;

}


int main()
{
	float xlim = 1.0f;
	//float SCALE = 0.6f; // This should be the right number
	float SCALE = 0.6f;
	// float SCALE = 0.72f; // As wide as possible
	// Assumes 25 inch base and 18 wide paper
	//float INCR = 0.0001f;
	float INCR = 0.000096f;
	float YOFFSET = 0.0f;


	float x_cur, y_cur, len_l, len_r;
	const alt_u8 StartButtonMask = 0x01; // 4 button
	const alt_u8 TestButtonMask = 0x02;
	const alt_u16 SwitchMask = 0xfff0;
	alt_u8 ButtonStatus;
	alt_u16 SwitchStatus,sw;

	int image_size = 1<<20;
	float *image;
	//image = (float *) malloc((image_size)*sizeof(float));
	image = malloc((image_size)*sizeof(float));
	IOWR_ALTERA_AVALON_PIO_DATA(
			BASEADDRESS_BASE,
			((int) image));

	//float center[4] = {0.0f, 0.0f, NAN, NAN};
	float center[2][2] = {{0.0f, 0.0f}, {NAN, NAN}};
	float tester[8][2] =
		{		{ 0.0f, 0.0f},
				{-1.0f,-1.0f},
				{ 1.0f,-1.0f},
				{ 1.0f, 1.0f},
				{-1.0f, 1.0f},
				{ 0.0f, 0.0f},
				{ NAN, NAN},
				{ NAN, NAN}
		};
	/*
	float tester[16];
	tester[0] = 0.0f;
	tester[1] = 0.0f;

	tester[2] = -1.0f;
	tester[3] = -1.0f;

	tester[4] = 1.0f;
	tester[5] = -1.0f;

	tester[6] = 1.0f;
	tester[7] = 1.0f;

	tester[8] = -1.0f;
	tester[9] = 1.0f;

	tester[10] = 0.0f;
	tester[11] = 0.0f;

	tester[12] = NAN;
	tester[13] = NAN;
*/

	int count;

	clear_mem(image_size,image);

	count = 0;
	while(isnan(*image)) {
		IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,(count>>19)&0x00000001);
		count++;
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,0x0);


	while(1) {

		init_DB();

		float y_center = 0.5f;
		float x_center = 0.5f;
		x_cur = x_center;
		y_cur = y_center;
		len_l = sqrtf(x_cur * x_cur + y_cur * y_cur);
		len_r = len_l;

		int startbutton = 0, testbutton = 0;
		count = 0;
		while (!startbutton && !testbutton){
			ButtonStatus = IORD(KEY_BASE, 0);
			SwitchStatus = IORD(SWITCH_BASE,0);
			startbutton = ((ButtonStatus & StartButtonMask) != StartButtonMask);
			testbutton  = ((ButtonStatus & TestButtonMask)  != TestButtonMask);
			sw = (SwitchStatus & SwitchMask) >> 4;

			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,(count>>19)&0x000003);
			count++;
		}

		if (startbutton) {
			int delay = 5000 + sw*1000;
			Shape(((point *) image),
					SCALE,
					x_center,y_center,
					&x_cur, &y_cur,
					xlim,
					&len_l, &len_r,
					INCR, YOFFSET,
					delay
			);
		} else if (testbutton) {
			int delay = 5000 + sw*1000;

			init_DB();
			Shape(tester,
						SCALE,
						x_center,y_center,
						&x_cur, &y_cur,
						xlim,
						&len_l, &len_r,
						INCR, YOFFSET,
						delay
				);

		}

		// wait for button
		ButtonStatus = StartButtonMask;
		count = 0;
		while((ButtonStatus & StartButtonMask) == StartButtonMask){
			ButtonStatus = IORD(KEY_BASE, 0);
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,(count>>19)&0x000001);
			count++;
		}

		// return to 0.5 0.5
		Shape(center,
				SCALE,
				x_center,y_center,
				&x_cur, &y_cur,
				xlim,
				&len_l, &len_r,
				INCR, YOFFSET,
				10000
		);

	}


	return 0;
}

