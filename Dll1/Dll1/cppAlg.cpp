#pragma once
#include "pch.h"
#include <utility>
#include <limits.h>
#include "cppAlg.h"


float truncate(int value) {
	if (value < 0) {
		return 0;
	}
	if (value > 255)
	{
		return 255;
	}
	return value;
}


void cppAlg(unsigned char* buf, unsigned char* part, int start, int end, float factor)
{
	int iZero = 0; // pierwszy iterator po skladowych piksela
	for (int i = start; i < end; i += 3) {
		// i - drugi iterator po skladowych piksela
		part[iZero] = truncate((float)(factor * (buf[i] - 128) + 128));
		part[iZero + 1] = truncate((float)(factor * (buf[i + 1] - 128) + 128));
		part[iZero + 2] = truncate((float)(factor * (buf[i + 2] - 128) + 128));


		iZero += 3;

	}
}