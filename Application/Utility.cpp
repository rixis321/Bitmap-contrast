#include "pch.h"
#include"Utility.h"

void MarshalString(String^ s, std::string& outputstring)
{
    const char* kPtoC = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    outputstring = kPtoC;
    Marshal::FreeHGlobal(IntPtr((void*)kPtoC));
}