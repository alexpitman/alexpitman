///////////////////////////////////////////////////////////////////////////////
//
// Name           : Fractal
// Inheritance    : namespace
// Desctription   : Fractal helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Fractal.h"

#include "numeric/Noise.h"

double num::Fractal::FBM(
  double X,
  double Y,
  double Octaves,
  double Amplitude,
  double Frequency,
  double H)
{
  const double xFreq = X*Frequency;
  const double yFreq = Y*Frequency;
  
  double result = 0.0f;
  
  for (int i = 0; i < Octaves-1; ++i)
  {
    result += Noise::Basic(xFreq, yFreq) * Amplitude;
    Amplitude *= H;
  }
  
  return result;
}

