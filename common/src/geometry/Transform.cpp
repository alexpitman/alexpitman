///////////////////////////////////////////////////////////////////////////////
//
// Name           : Transform
// Inheritance    : Base class
// Desctription   : Struct that represent a 3D transform matrix.
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Transform.h"

#include "numeric/num.h"

geo::Transform::Transform()
{
}
    
geo::Transform::Transform( double A0, double A1, double A2, double A3,
                      double B0, double B1, double B2, double B3,
                      double C0, double C1, double C2, double C3,
                      double D0, double D1, double D2, double D3 )
{
  myMatrix[0][0] = A0;
  myMatrix[0][1] = A1;
  myMatrix[0][2] = A2;
  myMatrix[0][3] = A3;
  myMatrix[1][0] = B0;
  myMatrix[1][1] = B1;
  myMatrix[1][2] = B2;
  myMatrix[1][3] = B3;
  myMatrix[2][0] = C0;
  myMatrix[2][1] = C1;
  myMatrix[2][2] = C2;
  myMatrix[2][3] = C3;
  myMatrix[3][0] = D0;
  myMatrix[3][1] = D1;
  myMatrix[3][2] = D2;
  myMatrix[3][3] = D3;
}

geo::Point3D
geo::Transform::operator ^(const Point3D& RHS)
{
  const double x = RHS.X();
  const double y = RHS.Y();
  const double z = RHS.Z();
  const double w = 1.0;

  double xc = x*myMatrix[0][0] + y*myMatrix[0][1] + z*myMatrix[0][2] + w*myMatrix[0][3];
  double yc = x*myMatrix[1][0] + y*myMatrix[1][1] + z*myMatrix[1][2] + w*myMatrix[1][3];
  double zc = x*myMatrix[2][0] + y*myMatrix[2][1] + z*myMatrix[2][2] + w*myMatrix[2][3];
  double wc = x*myMatrix[3][0] + y*myMatrix[3][1] + z*myMatrix[3][2] + w*myMatrix[3][3];
  
  if ( wc == 1.0 ) return Point3D(xc, yc, zc);
  // ASSERT(wc != 0.0);
  return Point3D(xc/wc, yc/wc, zc/wc);
}

geo::Vector3D
geo::Transform::operator ^(const Vector3D& RHS)
{
  const double x = RHS.X();
  const double y = RHS.Y();
  const double z = RHS.Z();
  const double w = 1.0;

  double xc = x*myMatrix[0][0] + y*myMatrix[0][1] + z*myMatrix[0][2] + w*myMatrix[0][3];
  double yc = x*myMatrix[1][0] + y*myMatrix[1][1] + z*myMatrix[1][2] + w*myMatrix[1][3];
  double zc = x*myMatrix[2][0] + y*myMatrix[2][1] + z*myMatrix[2][2] + w*myMatrix[2][3];
  double wc = x*myMatrix[3][0] + y*myMatrix[3][1] + z*myMatrix[3][2] + w*myMatrix[3][3];
  
  if ( wc == 1.0 ) return Vector3D(xc, yc, zc);
  // ASSERT(wc != 0.0);
  return Vector3D(xc/wc, yc/wc, zc/wc);
}

geo::Transform
geo::Transform::operator ^(const Transform& RHS)
{
  // TODO
  return Identity();
}

geo::Transform
geo::Transform::RotateX(double Degrees)
{
  const double cos = num::Cos(Degrees);
  const double sin = num::Sin(Degrees);

  return Transform(   1,   0,   0,   0,
                      0, cos,-sin,   0,
                      0, sin, cos,   0,
                      0,   0,   0,   1 );
}

geo::Transform
geo::Transform::RotateY(double Degrees)
{
  const double cos = num::Cos(Degrees);
  const double sin = num::Sin(Degrees);

  return Transform( cos,   0, sin,   0,
                      0,   1,   0,   0,
                   -sin,   0, cos,   0,
                      0,   0,   0,   1 );
}

geo::Transform
geo::Transform::RotateZ(double Degrees)
{
  const double cos = num::Cos(Degrees);
  const double sin = num::Sin(Degrees);

  return Transform( cos,-sin,   0,   0,
                    sin, cos,   0,   0,
                      0,   0,   1,   0,
                      0,   0,   0,   1 );
}
    
geo::Transform&
geo::Transform::Identity()
{
  static Transform identity(1, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1 );
  return identity;
}

geo::Transform&
geo::Transform::Zero()
{
  static Transform zero(0, 0, 0, 0,
                        0, 0, 0, 0,
                        0, 0, 0, 0,
                        0, 0, 0, 0 );
  return zero;
}

