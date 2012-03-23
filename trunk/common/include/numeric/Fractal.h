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

namespace num
{
  namespace Fractal
  {
    Dll_num double FBM(
      double X,
      double Y,
      double Octaves,
      double Amplitude,
      double Frequency,
      double H);
  }
}

#endif