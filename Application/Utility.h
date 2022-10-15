#pragma once
#include <iostream>
#include<string>
using namespace System;
using namespace Runtime::InteropServices;


//zamiana System::String na zwykly String
void MarshalString(String^ s, std::string& outputstring);