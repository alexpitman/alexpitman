#ifndef __NUM_FRACTAL_H
#define __NUM_FRACTAL_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Fractal
// Inheritance    : namespace
// Desctription   : Fractal helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include <anl.h>

#include <implicitinvert.h>

namespace num
{
  // Enums
  typedef anl::EBasisTypes BasisTypes;
  typedef anl::ECombinerTypes CombinerTypes;
  typedef anl::EFractalTypes FractalTypes;
  typedef anl::EInterpTypes InterpTypes;

  // Classes
  typedef anl::CImplicitBias Bias;
  typedef anl::CImplicitCache Cache;
  typedef anl::CImplicitCombiner Combiner;
  typedef anl::CImplicitFractal Fractal;
  typedef anl::CImplicitGradient Gradient;
  typedef anl::CImplicitInvert Invert;
  typedef anl::CImplicitScaleDomain ScaleDomain;
  typedef anl::CImplicitScaleOffset ScaleOffset;
  typedef anl::CImplicitSelect Select;
  typedef anl::CImplicitTranslateDomain TranslateDomain;
}

#endif