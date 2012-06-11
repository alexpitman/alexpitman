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
        //float distance = num::Sqrt(cx*cx + cy*cy + cz*cz) - Radius*(1.0f + num::Noise::Perlin(cx/3.0f, (cy-cz)/3.0f)*2.0f);
        
        geo::Vector3D dirVector(cx, cy, cz);
        dirVector.Normalise();
        
        float radiusSquaredInDir = radiusSquared + 3.0f * radiusSquared * num::Noise::Perlin(dirVector.X()/5.0f, (dirVector.Z() - dirVector.Y())/3.0f);
        float radialDistanceToPosition = cx*cx + cy*cy + cz*cz;
        
        (*subBlock)(x, y, z) = Voxel(radialDistanceToPosition > radiusSquaredInDir ? 0 : 1, radialDistanceToPosition - radiusSquaredInDir);
      }
    }
  }
  
  return subBlock;
}

template <unsigned short N>
vxl::SubBlock<N>* vxl::Factory::GenerateTerrain()
{
  vxl::SubBlock<N>* subBlock = new vxl::SubBlock<N>();

  num::Gradient gradient;
  gradient.setGradient(0, 0, 0, 0, 0, 1);
  
  num::Fractal fbm(num::FractalTypes::FBM, num::BasisTypes::GRADIENT, num::InterpTypes::QUINTIC);
  fbm.setNumOctaves(4);
  fbm.setFrequency(1.4f);
  
  num::ScaleOffset scaleOffset(0.5f, 0.0f);
  scaleOffset.setSource(&fbm);
  
  num::ScaleDomain scaleDomain;
  scaleDomain.setSource(&scaleOffset);
  scaleDomain.setZScale(0.0f);
  
  num::TranslateDomain translateDomain;
  translateDomain.setSource(&gradient);
  translateDomain.setZAxisSource(&scaleDomain);
  
  for (unsigned short x = 0; x < N; ++x)
  {
    const float pX = x / float(N);
    
    for (unsigned short y = 0; y < N; ++y)
    {
      const float pY = y / float(N);
      
      for (unsigned short z = 0; z < N; ++z)
      {
        const float pZ = z / float(N);
        
        const float number = translateDomain.get(pX, pY, pZ);
        (*subBlock)(x, y, z) = Voxel(number > 0.5f ? 0 : 1, number - 0.5f);
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
template Dll_vxl vxl::SubBlock<10>* vxl::Factory::GeneratePlanet<10>(float Radius);
template Dll_vxl vxl::SubBlock<64>* vxl::Factory::GeneratePlanet<64>(float Radius);
template Dll_vxl vxl::SubBlock<256>* vxl::Factory::GeneratePlanet<256>(float Radius);
template Dll_vxl vxl::SubBlock<10>* vxl::Factory::GenerateTerrain<10>();
template Dll_vxl vxl::SubBlock<64>* vxl::Factory::GenerateTerrain<64>();
template Dll_vxl vxl::SubBlock<256>* vxl::Factory::GenerateTerrain<256>();