///////////////////////////////////////////////////////////////////////////////
//
// Name           : TerrainDescriptor
// Inheritance    : None
// Desctription   : See header file
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/TerrainDescriptor.h"

#include "numeric/num.h"

vxl::TerrainDescriptor::TerrainDescriptor(bool EnableCaves)
: myGradiant(),
  myFBM(num::FractalTypes::FBM, num::BasisTypes::GRADIENT, num::InterpTypes::QUINTIC),
  myScaleOffset(0.5f, 0.0f),
  myScaleDomain(),
  myTranslateDomain(),
  myGroundDomainCache(),
  myGroundSelect(),
  
  myCaveAttenuate(0.5f),
  myCaveRM0(num::FractalTypes::RIDGEDMULTI, num::BasisTypes::GRADIENT, num::InterpTypes::QUINTIC),
  myCaveRM1(num::FractalTypes::RIDGEDMULTI, num::BasisTypes::GRADIENT, num::InterpTypes::QUINTIC),
  myCaveCombine(num::CombinerTypes::MULT),
  myCavePerturbFBM(num::FractalTypes::FBM, num::BasisTypes::GRADIENT, num::InterpTypes::QUINTIC),
  myCavePerturbScale(0.5f, 0.0f),
  myCavePerturb(),
  myCaveSelect(),
  
  myOverallCombine(num::CombinerTypes::MULT)
{
  // Ground level
  myGradiant.setGradient(0, 0, 0, 0, 1, 0);
  
  myFBM.setNumOctaves(4);
  myFBM.setFrequency(1.4f);
  
  myScaleOffset.setSource(&myFBM);
  
  myScaleDomain.setSource(&myScaleOffset);
  myScaleDomain.setZScale(0.0f);
  
  myTranslateDomain.setSource(&myGradiant);
  myTranslateDomain.setZAxisSource(&myScaleDomain);
  
  myGroundDomainCache.setSource(&myTranslateDomain);
  
  myGroundSelect.setLowSource(0.0f);
  myGroundSelect.setHighSource(1.0f);
  myGroundSelect.setControlSource(&myGroundDomainCache);
  myGroundSelect.setThreshold(0.5f);
  
  myOverallCombine.setSource(1, &myGroundDomainCache);
  
  if (EnableCaves)
  {
    // TODO SMOOTH CAVES
  
    // Caves
    myCaveAttenuate.setSource(&myGroundDomainCache);
    
    myCaveRM0.setNumOctaves(1);
    myCaveRM0.setFrequency(1.5f);
    myCaveRM1.setNumOctaves(1);
    myCaveRM1.setFrequency(1.5f);
    myCaveRM1.setSeed(5);
    
    myCaveCombine.setSource(0, &myCaveRM0);
    myCaveCombine.setSource(1, &myCaveAttenuate);
    myCaveCombine.setSource(2, &myCaveRM1);
    
    myCavePerturbFBM.setNumOctaves(6);
    myCavePerturbFBM.setFrequency(3.0f);
    
    myCavePerturbScale.setSource(&myCavePerturbFBM);
    
    myCavePerturb.setSource(&myCaveCombine);
    myCavePerturb.setYAxisSource(&myCavePerturbScale);
    
    myCaveSelect.setLowSource(1.0f);
    myCaveSelect.setHighSource(0.0f);
    myCaveSelect.setThreshold(0.48f);
    myCaveSelect.setFalloff(0.0f);
    myCaveSelect.setControlSource(&myCavePerturb);
    
    myOverallCombine.setSource(1, &myCaveSelect);
    //myOverallCombine.setSource(1, &myCavePerturb);
  }
}

float vxl::TerrainDescriptor::Evaluate(float X, float Y, float Z) const
{
  return myOverallCombine.get(X, Y, Z);
}
