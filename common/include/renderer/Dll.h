#ifndef __REE_DLL_H
#define __REE_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef REE_DLL
# define Dll_ree Dll_export
#else
# define Dll_ree Dll_import
#endif

#endif