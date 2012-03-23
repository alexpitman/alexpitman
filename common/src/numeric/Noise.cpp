///////////////////////////////////////////////////////////////////////////////
//
// Name           : Noise
// Inheritance    : namespace
// Desctription   : Noise helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Noise.h"

#include "numeric/Random.h"
#include "numeric/Interpolate.h"

namespace local
{
  static num::Random r(0);
}

double num::Noise::Basic(double x, double y)
{
  const double xFract = x - int(x);
  const double yFract = y - int(y);
  const double i1 = Interpolate::Cosine(local::r.NegOneToOne(), local::r.NegOneToOne(), xFract);
  const double i2 = Interpolate::Cosine(local::r.NegOneToOne(), local::r.NegOneToOne(), xFract);
  return Interpolate::Cosine(i1, i2, yFract);
}
