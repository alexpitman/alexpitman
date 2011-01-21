///////////////////////////////////////////////////////////////////////////////
//
// Name           : numeric name space
// Inheritance    : None
// Desctription   : Basic numeric operations
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/num.h"

#include <math.h>

#define PI 3.14159265

double
num::Sin(double Degrees)
{
  return sin( DegreesToRadians(Degrees) );
}

double
num::Cos(double Degrees)
{
  return cos( DegreesToRadians(Degrees) );
}

double
num::RadiansToDegrees(double Radians)
{
  return Radians*180/PI;
}

double
num::DegreesToRadians(double Degrees)
{
  return Degrees*PI/180;
}
