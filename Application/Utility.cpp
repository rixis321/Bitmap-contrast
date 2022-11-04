#include "pch.h"
#include"Utility.h"







/* Funkcja zamieniajaca system stringa na zwyklego stringa */
void MarshalString(System::String^ s, std::string& outputstring)
{
    const char* kPtoC = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s)).ToPointer();
    outputstring = kPtoC;
    System::Runtime::InteropServices::Marshal::FreeHGlobal(System::IntPtr((void*)kPtoC));
}

