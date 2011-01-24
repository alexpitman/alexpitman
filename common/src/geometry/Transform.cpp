///////////////////////////////////////////////////////////////////////////////
//
// Name           : Transform
// Inheritance    : Base class
// Desctription   : Struct that represent a 3D transform matrix.
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Transform.h"

#include "geometry/Rotation.h"

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
geo::Transform::operator ^(const Point3D& RHS) const
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
geo::Transform::operator ^(const Vector3D& RHS) const
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
geo::Transform::operator ^(const Rotation& RHS) const
{
  return *this ^ RHS.ToTransform();
}

geo::Transform
geo::Transform::operator ^(const Transform& RHS) const
{
  const double la0 = myMatrix[0][0];
  const double la1 = myMatrix[0][1];
  const double la2 = myMatrix[0][2];
  const double la3 = myMatrix[0][3];
  const double lb0 = myMatrix[1][0];
  const double lb1 = myMatrix[1][1];
  const double lb2 = myMatrix[1][2];
  const double lb3 = myMatrix[1][3];
  const double lc0 = myMatrix[2][0];
  const double lc1 = myMatrix[2][1];
  const double lc2 = myMatrix[2][2];
  const double lc3 = myMatrix[2][3];
  const double ld0 = myMatrix[3][0];
  const double ld1 = myMatrix[3][1];
  const double ld2 = myMatrix[3][2];
  const double ld3 = myMatrix[3][3];

  const double ra0 = RHS.myMatrix[0][0];
  const double ra1 = RHS.myMatrix[0][1];
  const double ra2 = RHS.myMatrix[0][2];
  const double ra3 = RHS.myMatrix[0][3];
  const double rb0 = RHS.myMatrix[1][0];
  const double rb1 = RHS.myMatrix[1][1];
  const double rb2 = RHS.myMatrix[1][2];
  const double rb3 = RHS.myMatrix[1][3];
  const double rc0 = RHS.myMatrix[2][0];
  const double rc1 = RHS.myMatrix[2][1];
  const double rc2 = RHS.myMatrix[2][2];
  const double rc3 = RHS.myMatrix[2][3];
  const double rd0 = RHS.myMatrix[3][0];
  const double rd1 = RHS.myMatrix[3][1];
  const double rd2 = RHS.myMatrix[3][2];
  const double rd3 = RHS.myMatrix[3][3];

  return Transform(
    la0*ra0 + la1*rb0 + la2*rc0 + la3*rd0,
    la0*ra1 + la1*rb1 + la2*rc1 + la3*rd1,
    la0*ra2 + la1*rb2 + la2*rc2 + la3*rd2,
    la0*ra3 + la1*rb3 + la2*rc3 + la3*rd3,
    lb0*ra0 + lb1*rb0 + lb2*rc0 + lb3*rd0,
    lb0*ra1 + lb1*rb1 + lb2*rc1 + lb3*rd1,
    lb0*ra2 + lb1*rb2 + lb2*rc2 + lb3*rd2,
    lb0*ra3 + lb1*rb3 + lb2*rc3 + lb3*rd3,
    lc0*ra0 + lc1*rb0 + lc2*rc0 + lc3*rd0,
    lc0*ra1 + lc1*rb1 + lc2*rc1 + lc3*rd1,
    lc0*ra2 + lc1*rb2 + lc2*rc2 + lc3*rd2,
    lc0*ra3 + lc1*rb3 + lc2*rc3 + lc3*rd3,
    ld0*ra0 + ld1*rb0 + ld2*rc0 + ld3*rd0,
    ld0*ra1 + ld1*rb1 + ld2*rc1 + ld3*rd1,
    ld0*ra2 + ld1*rb2 + ld2*rc2 + ld3*rd2,
    ld0*ra3 + ld1*rb3 + ld2*rc3 + ld3*rd3 );
}

geo::Transform
geo::Transform::Translate(const geo::Vector3D Vector)
{
  return Transform( 1, 0, 0, Vector.X(),
                    0, 1, 0, Vector.Y(),
                    0, 0, 1, Vector.Z(),
                    0, 0, 0, 1 );
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

geo::Transform
geo::Transform::Rotate(const Point3D& Position,
                       const Vector3D& Direction,
                       double Degrees)
{
  // Taken from: "Rotation about an arbitrary line"
  // http://inside.mines.edu/~gmurray/ArbitraryAxisRotation/ArbitraryAxisRotation.html
  const double cos = num::Cos(Degrees);
  const double sin = num::Sin(Degrees);
  const double mcos1 = 1-cos;
  const double msin1 = 1-sin;
  
  const double a = Position.X();
  const double b = Position.Y();
  const double c = Position.Z();
  
  const double u = Direction.X();
  const double v = Direction.Y();
  const double w = Direction.Z();
  
  const double uu = u*u;
  const double vv = v*v;
  const double ww = w*w;
  
  const double uv = u*v;
  const double uw = u*w;
  const double vw = v*w;
  
  const double au = a*u;
  const double av = a*v;
  const double aw = a*w;
  const double bu = b*u;
  const double bv = b*v;
  const double bw = b*w;
  const double cu = c*u;
  const double cv = c*v;
  const double cw = c*w;
  
  const double LL = uu + vv + ww;
  const double L = num::Sqrt(LL);
  
  return Transform(
    (uu + (vv + ww)*cos) / LL,
    (uv*mcos1 - w*L*sin) / LL,
    (uw*mcos1 + v*L*sin) / LL,
    (a*(vv+ww) - u*(bv+cw) + (u*(bv+cw) - a*(vv+ww))*cos + (bw-cv)*L*sin) / LL,
    (uv*mcos1 + w*L*sin) / LL,
    (vv + (uu + ww)*cos) / LL,
    (vw*mcos1 - u*L*sin) / LL,
    (b*(uu+ww) - v*(au+cw) + (v*(au+cw) - b*(uu+ww))*cos + (cu-aw)*L*sin) / LL,
    (uw*mcos1 - v*L*sin) / LL,
    (vw*mcos1 + u*L*sin) / LL,
    (ww + (uu + vv)*cos) / LL,
    (c*(uu+vv) - w*(au+bv) + (w*(au+bv) - c*(uu+vv))*cos + (av-bu)*L*sin) / LL,
    0, 0, 0, 1 );
    
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

