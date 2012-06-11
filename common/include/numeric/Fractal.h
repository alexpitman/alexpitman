#ifndef __NUM_FRACTAL_H
#define __NUM_FRACTAL_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Fractal
// Inheritance    : namespace
// Desctription   : Fractal helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Dll.h"

#include <anl.h>

//#define NUMK_MAX_OCTAVES 16

namespace num
{
  // Enums
  typedef anl::EFractalTypes FractalTypes;
  typedef anl::EBasisTypes BasisTypes;
  typedef anl::EInterpTypes InterpTypes;
  
  // Classes
  typedef anl::CImplicitFractal Fractal;
  typedef anl::CImplicitGradient Gradient;
  typedef anl::CImplicitScaleDomain ScaleDomain;
  typedef anl::CImplicitScaleOffset ScaleOffset;
  typedef anl::CImplicitTranslateDomain TranslateDomain;
  /*
  namespace Fractal
  {
    
  
    
    class Dll_num FBM
    {
    public:
    
      FBM(unsigned int OctaveCount);
      
      float Get(float x, float y) const;
      
    private:
    
      float myFrequency;
      float myLacunarity;
      float myExponentArray[NUMK_MAX_OCTAVES];
      unsigned int myOctaveCount;
    };
  }
  */
}

#endif