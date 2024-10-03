#pragma once

#include <iostream>
#include <windows.h>

namespace InetFW
{
	bool setRule(const wchar_t* rule, const wchar_t* filename);
	bool setUnblock(const wchar_t* rule);
}