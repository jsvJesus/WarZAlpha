#include "r3dPCH.h"

#include <stdexcept>
#include <xstring>

namespace std
{
	void __cdecl _String_base::_Xran()
	{
		throw out_of_range("invalid string position");
	}

	void __cdecl _String_base::_Xlen()
	{
		throw length_error("string too long");
	}
}