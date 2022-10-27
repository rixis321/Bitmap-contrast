#pragma once
#include "pch.h"
#include <utility>
#include <limits.h>
#include "cppAlg.h"

/* Funkcja sprawdzajaca czy bajt piksela (RGB) nalezy do przedzialu od 0 do 255,
* Jesli piksel nalezy do danego przedzialu to zostaje zwrocony. 
*/
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
	int iZero = 0; // iterator po skladowych piksela czesci bitmapy
	for (int i = start; i < end; i += 3) { // iterator po skladowych piksela bitmapy 
		// 
		part[iZero] = truncate((float)(factor * (buf[i] - 128) + 128));
		part[iZero + 1] = truncate((float)(factor * (buf[i + 1] - 128) + 128));
		part[iZero + 2] = truncate((float)(factor * (buf[i + 2] - 128) + 128));


		iZero += 3; // przejscie do kolejnego piksela 

	}
}