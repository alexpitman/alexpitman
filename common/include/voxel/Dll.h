#ifndef __VXL_DLL_H
#define __VXL_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef VOXEL_DLL
# define Dll_vxl Dll_export
#else
# define Dll_vxl Dll_import
#endif

#endif