#ifndef __IMG_DLL_H
#define __IMG_DLL_H
///////////////////////////////////////////////////////////////////////////////
//
// Dll exporting
//
///////////////////////////////////////////////////////////////////////////////

#include "config/Dll.h"

#ifdef IMG_DLL
# define Dll_img Dll_export
#else
# define Dll_img Dll_import
#endif

#endif