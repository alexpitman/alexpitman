///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : None
// Desctription   : Random voxel creation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Factory.h"

template <unsigned short N>
vxl::SubBlock<N> vxl::Factory::GenerateSubBlock()
{
  vxl::SubBlock<N> subBlock;
  
  for (unsigned short x = 0; x < N; ++x)
  {
    for (unsigned short y = 0; y < N; ++y)
    {
      for (unsigned short z = 0; z < N; ++z)
      {
        //subBlock(x, y, z) = Voxel(z > N/2.0f ? 1 : 0, 0.0f);
        subBlock(x, y, z) = Voxel(x*x + y*y + z*z < 5*5 ? 1 : 0, 0.0f);
      }
    }
  }
  
  return subBlock;
}

// Explicit instantiations
template Dll_vxl vxl::SubBlock<10> vxl::Factory::GenerateSubBlock<10>();
template Dll_vxl vxl::SubBlock<256> vxl::Factory::GenerateSubBlock<256>();