#ifndef __ATT_DLL_H
#define __ATT_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef ATTRIBUTE_DLL
# define Dll_att Dll_export
#else
# define Dll_att Dll_import
#endif

#endif