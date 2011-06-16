#ifndef __TPO_DLL_H
#define __TPO_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef TPO_DLL
# define Dll_tpo Dll_export
# define Dll_tpo_extern Dll_export
#else
# define Dll_tpo Dll_import
# define Dll_tpo_extern
#endif

#endif