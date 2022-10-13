// Bitmap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>

#include <iostream>

typedef int(_stdcall* MyProc)(int, int);

HINSTANCE dllHandle = NULL;


int main()
{
    

    dllHandle = LoadLibrary(TEXT("JaAsm.dll"));
    MyProc procedura = (MyProc)GetProcAddress(dllHandle, "MyProc");
    std::cout << procedura(5,4);

}


