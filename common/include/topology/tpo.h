#ifndef __TPO_H
#define __TPO_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : tpo
// Description    : tpo namespace functions
//
///////////////////////////////////////////////////////////////////////////////

#include "topology/Dll.h"

#include "numeric/num.h"

namespace tpo
{
	typedef unsigned long T_Index;
	
	Dll_tpo_extern T_Index NullIndex = num::Upper<tpo::T_Index>();
}

#endif