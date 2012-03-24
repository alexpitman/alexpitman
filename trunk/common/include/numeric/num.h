#ifndef __NUM_NUM_H
#define __NUM_NUM_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : numeric name space
// Inheritance    : None
// Desctription   : Basic numeric operations
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Dll.h"

#include <limits>

#undef min
#undef max

namespace num
{
  /////////////////////////////////////////////////////////////////////////////
  // Angle related
  Dll_num double Pi();
  
  Dll_num double Sin(double Degrees);
  Dll_num double Cos(double Degrees);
  Dll_num double Tan(double Degrees);
  
  Dll_num double RadiansToDegrees(double Radians);
  Dll_num double DegreesToRadians(double Degrees);
  
  /////////////////////////////////////////////////////////////////////////////
  // General math related
  Dll_num double Sqrt(double Num);
  
  Dll_num double Abs(double Num);
  
  Dll_num double Pow(double Num, double Exponent);
  
  /////////////////////////////////////////////////////////////////////////////
  // Limit related
  template<typename T> inline Dll_num T NaN();
	template<typename T> inline Dll_num T Lower();
	template<typename T> inline Dll_num T Upper();
	
}

///////////////////// INLINE DECLARATIONS /////////////////////////////////////
template<typename T> T
num::NaN()
{
  return std::numeric_limits<T>::quiet_NaN();
}

template<typename T> T
num::Lower()
{
  return std::numeric_limits<T>::min();
}

template<typename T> T
num::Upper()
{
  return std::numeric_limits<T>::max();
}

#endif