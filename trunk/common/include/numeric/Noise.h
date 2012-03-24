#ifndef __NUM_NOISE_H
#define __NUM_NOISE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Noise
// Inheritance    : namespace
// Desctription   : Noise helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Dll.h"

namespace num
{
  namespace Noise
  {
    Dll_num float Basic(int x, int y);
    Dll_num float Smooth(float x, float y);
    Dll_num float Interpolated(float x, float y);
    Dll_num float Perlin(float x, float y);
  }
}

#endif