///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : None
// Desctription   : Random voxel creation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Factory.h"

#include "geometry/Vector.h"

#include "numeric/Fractal.h"
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
  
  const float centre = N/2;
  const float radius = centre * 0.9;
  const float radiusSquared = radius*radius;
  
  for (unsigned short x = 0; x < N; ++x)
  {
    for (unsigned short y = 0; y < N; ++y)
    {
      for (unsigned short z = 0; z < N; ++z)
      {
        float cx = (float(x) - centre);
        float cy = (float(y) - centre);
        float cz = (float(z) - centre);
        double distance = num::Sqrt(cx*cx + cy*cy + cz*cz) - radius;
        (*subBlock)(x, y, z) = Voxel(cx*cx + cy*cy + cz*cz > radiusSquared ? 0 : 1, distance);
      }
    }
  }
  
  return subBlock;
}

template <unsigned short N>
vxl::SubBlock<N>* vxl::Factory::GeneratePlanet(float Radius)
{
  vxl::SubBlock<N>* subBlock = new vxl::SubBlock<N>();
  
  const float centre = N/2;
  const float radiusSquared = Radius*Radius;
  
  for (unsigned short x = 0; x < N; ++x)
  {
    for (unsigned short y = 0; y < N; ++y)
    {
      for (unsigned short z = 0; z < N; ++z)
      {
        float cx = (float(x) - centre);
        float cy = (float(y) - centre);
        float cz = (float(z) - centre);
        
        geo::Vector3D dirVector(cx, cy, cz);
        dirVector.Normalise();
        
        float radiusSquaredInDir = radiusSquared + 3.0f * num::Noise::Perlin(dirVector.X()/5.0f, (dirVector.Z() - dirVector.Y())/3.0f);
        float radialDistanceToPosition = cx*cx + cy*cy + cz*cz;
        
        (*subBlock)(x, y, z) = Voxel(radialDistanceToPosition > radiusSquaredInDir ? 0 : 1, radialDistanceToPosition - radiusSquaredInDir);
      }
    }
  }
  
  return subBlock;
}

template <unsigned short N>
vxl::SubBlock<N>* vxl::Factory::GenerateTerrain(
  const vxl::TerrainDescriptor& Descriptor,
  const geo::Vector3D& Offset)
{
  vxl::SubBlock<N>* subBlock = new vxl::SubBlock<N>(Offset);

  for (unsigned short x = 0; x < N; ++x)
  {
    const float pX = Offset.X() + x / float(N);
    
    for (unsigned short y = 0; y < N; ++y)
    {
      const float pY = Offset.Y() + y / float(N);
      
      for (unsigned short z = 0; z < N; ++z)
      {
        const float pZ = Offset.Z() + z / float(N);
        
        const float number = Descriptor.Evaluate(pX, pY, pZ);
        (*subBlock)(x, y, z) = Voxel(number > 0.5f ? 1 : 0, number - 0.5f);
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
template Dll_vxl vxl::SubBlock<64>* vxl::Factory::GenerateSphere<64>();
template Dll_vxl vxl::SubBlock<256>* vxl::Factory::GenerateSphere<256>();
template Dll_vxl vxl::SubBlock<10>* vxl::Factory::GeneratePlanet<10>(float Radius);
template Dll_vxl vxl::SubBlock<64>* vxl::Factory::GeneratePlanet<64>(float Radius);
template Dll_vxl vxl::SubBlock<256>* vxl::Factory::GeneratePlanet<256>(float Radius);
template Dll_vxl vxl::SubBlock<10>* vxl::Factory::GenerateTerrain<10>(const vxl::TerrainDescriptor& Descriptor, const geo::Vector3D& Offset);
template Dll_vxl vxl::SubBlock<64>* vxl::Factory::GenerateTerrain<64>(const vxl::TerrainDescriptor& Descriptor, const geo::Vector3D& Offset);
template Dll_vxl vxl::SubBlock<256>* vxl::Factory::GenerateTerrain<256>(const vxl::TerrainDescriptor& Descriptor, const geo::Vector3D& Offset);