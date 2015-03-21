/*
 * main.c
 *
 *  Created on: May 28, 2014
 *      Author: herman
 */

#include <stdio.h>
#include <math.h>
#include "system.h"
#include "drawbot.h"
#include "drawbot_util.h"
#include "altera_avalon_pio_regs.h"

int main()
{
	float xlim = 1.0f,
			ylim = 1.0f;
	float SCALE = 0.4f;
	//float INCR = 0.0001f;
	float INCR = 0.000096f;


	float x_cur, y_cur, len_l, len_r;
	const alt_u8 StartButtonMask = 0x01; // 4 button
	const alt_u8 TestButtonMask = 0x02;
	alt_u8 Status,ButtonStatus;

	int image_size = 1<<20;
	float *image, *ptr;
	image = (float *) malloc((image_size)*sizeof(float));
	IOWR_ALTERA_AVALON_PIO_DATA(BASEADDRESS_BASE,image);

	float center[4];

	center[0] = 0.0f;
	center[1] = 0.0f;
	center[2] = NAN;
	center[3] = NAN;

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

	int count;

	while(1) {

		init_DB();

		float y_center = 0.5f;
		float x_center = 0.5f;
		x_cur = x_center;
		y_cur = y_center;
		len_l = sqrtf(x_cur * x_cur + y_cur * y_cur);
		len_r = len_l;

		// Clear memory
		for (count = 0, ptr = image; count < image_size; count++, ptr++)
			*ptr = NAN;

		// Wait until memory is set
		count = 0;
		while(isnan(*image)) {
			IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,(count>>19)&0x00000001);
			count++;
		}
		IOWR_ALTERA_AVALON_PIO_DATA(LEDR_BASE,0x0);

		int startbutton = 0, testbutton = 0;
		count = 0;
		while (!startbutton && !testbutton){
			ButtonStatus = IORD(KEY_BASE, 0);
			startbutton = ((ButtonStatus & StartButtonMask) != StartButtonMask);
			testbutton  = ((ButtonStatus & TestButtonMask)  != TestButtonMask);
			IOWR_ALTERA_AVALON_PIO_DATA(LEDG_BASE,(count>>19)&0x000011);
			count++;
		}

		if (startbutton) {
			Shape(image,
					SCALE,
					x_center,y_center,
					&x_cur, &y_cur,
					xlim,
					&len_l, &len_r,
					INCR
			);
		} else if (testbutton) {
			init_DB();

			Shape(tester,
						SCALE,
						x_center,y_center,
						&x_cur, &y_cur,
						xlim,
						&len_l, &len_r,
						INCR
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
				INCR
		);

	}


	return 0;
}

