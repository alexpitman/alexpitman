#ifndef __NUM_INTERPOLATE_H
#define __NUM_INTERPOLATE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Interpolate
// Inheritance    : Base class
// Desctription   : Interpolation helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Dll.h"

namespace num
{
  namespace Interpolate
  {
    Dll_num double Cosine(double n1, double n2, double x);
  }
}

#endif