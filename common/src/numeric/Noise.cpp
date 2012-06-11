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
#include "numeric/num.h"

#include <iostream>

namespace local
{
  static num::Random r(0);
}

float num::Noise::Basic(int x, int y)
{
  int n = x + y * 57;
  n = (n<<13) ^ n;
  return 1.0f - ((n * (n*n*15731 + 789221) + 1376312589) & 0x7FFFFFFF) / 2147483647.0f;//1073741824.0f;
}

float num::Noise::Smooth(float x, float y)
{
  return
    Basic(x, y) / 4.0f +
    (Basic(x-1, y) + Basic(x+1, y) + Basic(x, y-1) + Basic(x, y+1)) / 8.0f +
    (Basic(x-1, y-1) + Basic(x-1, y+1) + Basic(x+1, y-1) + Basic(x+1, y+1)) / 16.0f;
}

float num::Noise::Interpolated(float x, float y)
{
  const int intX = int(x);
  const int intY = int(y);

  const float fractX = x - intX;
  const float fractY = y - intY;
  
  const float v1 = Smooth(intX, intY);
  const float v2 = Smooth(intX+1, intY);
  const float v3 = Smooth(intX, intY+1);
  const float v4 = Smooth(intX+1, intY+1);
  
  const float i1 = Interpolate::Cosine(v1, v2, fractX);
  const float i2 = Interpolate::Cosine(v3, v4, fractX);
  return Interpolate::Cosine(i1, i2, fractY);
}

float num::Noise::Perlin(float x, float y)
{
  float total = 0.0f;
  
  const float w = 0.5f;
  const short octaves = 6;
  const float s = 2.0f;
  
  for (short i = 1; i <= octaves; ++i)
  {
    const float sToI = Pow(s, i);
    const float wToI = Pow(w, i);
    
    total += wToI * Interpolated(x*sToI, y*sToI);
  }
  return total;
}
