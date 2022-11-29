#include "pch.h"
#include "startAsm.h"


	typedef void(_fastcall* AsmAlg)(unsigned char*, unsigned char*, int, int, float);
	HINSTANCE dllHandle = LoadLibrary(TEXT("JaAsm.dll"));
	AsmAlg procedura = (AsmAlg)GetProcAddress(dllHandle, "AsmAlg");

	void startAsm(unsigned char* buf, unsigned char* part, int start, int end, float factor) {
		procedura(buf, part, start, end, factor);
	}


