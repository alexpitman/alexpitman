#ifndef __NUM_NUM_H
#define __NUM_NUM_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : numeric name space
// Inheritance    : None
// Desctription   : Basic numeric operations
//
///////////////////////////////////////////////////////////////////////////////

#include <limits>

namespace num
{
  /////////////////////////////////////////////////////////////////////////////
  // Angle related
  double Sin(double Degrees);
  double Cos(double Degrees);
  
  double RadiansToDegrees(double Radians);
  double DegreesToRadians(double Degrees);
  
  /////////////////////////////////////////////////////////////////////////////
  // Limit related
  template<typename T> inline T NaN();
}

template<typename T> T
num::NaN()
{
  return std::numeric_limits<T>::quiet_NaN();
}

#endif