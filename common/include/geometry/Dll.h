#ifndef __GEO_DLL_H
#define __GEO_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef GEOMETRY_DLL
# define Dll_geo Dll_export
#else
# define Dll_geo Dll_import
#endif

#endif