#ifndef __VWR_DLL_H
#define __VWR_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef VIEWER_DLL
# define Dll_vwr Dll_export
#else
# define Dll_vwr Dll_import
#endif

#endif