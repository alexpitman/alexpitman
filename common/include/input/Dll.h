#ifndef __IN_DLL_H
#define __IN_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef INPUT_DLL
# define Dll_in Dll_export
#else
# define Dll_in Dll_import
#endif

#endif