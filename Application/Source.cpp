#include "Source.h"
#include "pch.h"
#include <windows.h>
#include <iostream>
HINSTANCE dllHandle = NULL;
typedef int(_stdcall* MyProc)(int, int);
typedef double(_stdcall* FloatProc)(double, double);


int write() {
	dllHandle = LoadLibrary(TEXT("JaAsm.dll"));
	MyProc procedura = (MyProc)GetProcAddress(dllHandle, "MyProc");
	 int map = procedura(3, 1);
	 return map;
}
