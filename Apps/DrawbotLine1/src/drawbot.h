/*
 * drawbot.h
 *
 *  Created on: Jan 8, 2014
 *      Author: herman
 */

#ifndef DRAWBOT_H_
#define DRAWBOT_H_

typedef float point[2];

void Shape(point *,
		float, float,
		float *, float *,
		float *, float *
);

void ZeroDB(int);

void updateLen(float *, float *, float , float , float );

#endif /* DRAWBOT_H_ */
