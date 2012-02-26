#ifndef __VXL_FACTORY_H
#define __VXL_FACTORY_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : None
// Desctription   : Random voxel creation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/SubBlock.h"

namespace vxl
{
  namespace Factory
  {
    template <unsigned short N>
    Dll_vxl SubBlock<N>* GenerateSubBlock();
  }
}

#endif