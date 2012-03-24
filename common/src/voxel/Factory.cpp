///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : None
// Desctription   : Random voxel creation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Factory.h"

#include "numeric/Noise.h"
#include "numeric/num.h"

#include <iostream>

template <unsigned short N>
vxl::SubBlock<N>* vxl::Factory::GenerateSubBlock()
{
  vxl::SubBlock<N>* subBlock = new vxl::SubBlock<N>();
  
  for (unsigned short x = 0; x < N; ++x)
  {
    for (unsigned short y = 0; y < N; ++y)
    {
      const double fbm =
        num::Noise::Perlin(x, y) / 20.0f +
        num::Noise::Perlin(x+23, x-y-419) / 20.0f;
        
      //std::cout << fbm << std::endl;
      for (unsigned short z = 0; z < N; ++z)
      {
        const float distance = z/float(N) + fbm;

        //std::cout << distance << std::endl;

        (*subBlock)(x, y, z) = Voxel(distance > 0.5f ? 0 : 1, distance);
      }
    }
  }
  
  return subBlock;
}

template <unsigned short N>
vxl::SubBlock<N>* vxl::Factory::GenerateSphere()
{
  vxl::SubBlock<N>* subBlock = new vxl::SubBlock<N>();
  
  for (unsigned short x = 0; x < N; ++x)
  {
    for (unsigned short y = 0; y < N; ++y)
    {
      for (unsigned short z = 0; z < N; ++z)
      {
        int cx = int(x) - 5;
        int cy = int(y) - 5;
        int cz = int(z) - 5;
        double distance = num::Sqrt(cx*cx + cy*cy + cz*cz) - 3.0f;
        //subBlock(x, y, z) = Voxel(z > N/2.0f ? 1 : 0, 0.0f);
        (*subBlock)(x, y, z) = Voxel(cx*cx + cy*cy + cz*cz > 9 ? 0 : 1, distance);
      }
    }
  }
  
  return subBlock;
}

// Explicit instantiations
template Dll_vxl vxl::SubBlock<10>* vxl::Factory::GenerateSubBlock<10>();
template Dll_vxl vxl::SubBlock<64>* vxl::Factory::GenerateSubBlock<64>();
template Dll_vxl vxl::SubBlock<256>* vxl::Factory::GenerateSubBlock<256>();
template Dll_vxl vxl::SubBlock<10>* vxl::Factory::GenerateSphere<10>();