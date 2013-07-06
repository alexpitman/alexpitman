#ifndef __VXL_TERRAIN_DESCRIPTOR_H
#define __VXL_TERRAIN_DESCRIPTOR_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Voxel
// Inheritance    : Base class
// Desctription   : Stores information about a terrain that can be used to generate triangulations.
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Dll.H"

#include "geometry/Point.h"

#include "numeric/Fractal.h"
#include "numeric/Noise.h"

namespace vxl
{
  struct Dll_vxl TerrainDescriptor
  {
  public:
  
    TerrainDescriptor(bool EnableCaves);
  
    float Evaluate(const geo::Point3D& Point) const;
    float Evaluate(float X, float Y, float Z) const;
  
  private:
  
    // Ground
    num::Gradient myGradiant;
    num::Fractal myFBM;
    num::ScaleOffset myScaleOffset;
    num::ScaleDomain myScaleDomain;
    num::TranslateDomain myTranslateDomain;
    num::Cache myGroundDomainCache;
    num::Select myGroundSelect;
    
    // Caves
    num::Bias myCaveAttenuate;
    num::Fractal myCaveRM0;
    num::Fractal myCaveRM1;
    num::Combiner myCaveCombine;
    num::Fractal myCavePerturbFBM;
    num::ScaleOffset myCavePerturbScale;
    num::TranslateDomain myCavePerturb;
    num::Select myCaveSelect;
    
    mutable num::Combiner myOverallCombine;
  };
}

#endif
