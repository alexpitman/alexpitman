///////////////////////////////////////////////////////////////////////////////
//
// Name           : Fractal
// Inheritance    : namespace
// Desctription   : Fractal helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Fractal.h"

/*
#include "numeric/Noise.h"
#include "numeric/num.h"

#include <assert.h>

num::Fractal::FBM::FBM(unsigned int OctaveCount)
: myOctaveCount(OctaveCount),
  myLacunarity(0.5f),
  myFrequency(2.0f)
{
  assert(myOctaveCount <= NUMK_MAX_OCTAVES);

  for (int i = 0; i < myOctaveCount; ++i)
  {
    myExponentArray[i] = Pow(myLacunarity, -i);
  }
}

float num::Fractal::FBM::Get(float x, float y) const
{
  float value = 0.0f;
  
  x *= myFrequency;
  y *= myFrequency;
  
  for (unsigned int i = 0; i < myOctaveCount; ++i)
  {
    value += myExponentArray[i] * Noise::Interpolated(x, y);
    x *= myLacunarity;
    y *= myLacunarity;
  }
  
  return value;
}
*/
