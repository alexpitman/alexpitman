#ifndef __TST_DLL_H
#define __TST_DLL_H

#include "config/Dll.h"

#ifdef TEST_DLL
# define Dll_tst Dll_export
#else
# define Dll_tst Dll_import
#endif

#endif