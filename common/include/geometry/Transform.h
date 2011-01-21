#ifndef __GEO_TRANSFORM_H
#define __GEO_TRANSFORM_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Transform
// Inheritance    : Base class
// Desctription   : Struct that represent a 3D transform matrix.
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Point.h"
#include "geometry/Vector.h"

namespace geo
{
  class Transform
  {
  public:
  
    Transform();
    
    Transform( double A0, double A1, double A2, double A3,
               double B0, double B1, double B2, double B3,
               double C0, double C1, double C2, double C3,
               double D0, double D1, double D2, double D3 );
    
    Point3D operator ^(const Point3D& RHS);
    Vector3D operator ^(const Vector3D& RHS);
    Transform operator ^(const Transform& RHS);
    
    static Transform RotateX(double Degrees);
    static Transform RotateY(double Degrees);
    static Transform RotateZ(double Degrees);
    
    static Transform& Identity();
    static Transform& Zero();
  
  private:
  
    double myMatrix[4][4];
  
  };
}

#endif
