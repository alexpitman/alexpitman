///////////////////////////////////////////////////////////////////////////////
//
// Name           : Interpolate
// Inheritance    : namespace
// Desctription   : Interpolation helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Interpolate.h"

#include "numeric/num.h"

double num::Interpolate::Cosine(double n1, double n2, double t)
{
  const double f = (1 - Cos(t * Pi())) * 0.5f;
  return n1 * (1-f) + n2*f;
}
