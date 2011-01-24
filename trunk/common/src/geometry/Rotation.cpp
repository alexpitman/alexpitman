///////////////////////////////////////////////////////////////////////////////
//
// Name           : Rotation
// Inheritance    : Base class
// Desctription   : Struct that represents a 3D rotation.
//                  http://en.wikipedia.org/wiki/Quaternion
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Rotation.h"

#include "numeric/num.h"

geo::Rotation::Rotation()
: myA(1),
  myB(0),
  myC(0),
  myD(0)
{
}

geo::Rotation::Rotation(double A, double B, double C, double D)
: myA(A),
  myB(B),
  myC(C),
  myD(D)
{
}

geo::Rotation::Rotation(const geo::Vector3D& Vector, double Degrees)
{
  // http://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
  // A = cos(angle/2)
  // B = sin(angle/2) * cos(vector_angle_x)
  // C = sin(angle/2) * cos(vector_angle_y)
  // D = sin(angle/2) * cos(vector_angle_z)
  myA = num::Cos(Degrees/2);
  
  const double sin = num::Sin(Degrees/2);
  const double length = Vector.Length();
  
  // Note: cos(angle) = adjacent/hypotenuse
  myB = sin * Vector.X() / length;
  myC = sin * Vector.Y() / length;
  myD = sin * Vector.Z() / length;
}

geo::Rotation::Rotation(double Roll, double Pitch, double Yaw)
{
  // http://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
  const double cosR = num::Cos(Roll/2);
  const double cosP = num::Cos(Pitch/2);
  const double cosY = num::Cos(Yaw/2);
  const double sinR = num::Sin(Roll/2);
  const double sinP = num::Sin(Pitch/2);
  const double sinY = num::Sin(Yaw/2);
  
  myA = cosR*cosP*cosY + sinR*sinP*sinY;
  myB = sinR*cosP*cosY - cosR*sinP*sinY;
  myC = cosR*sinP*cosY + sinR*cosP*sinY;
  myD = cosR*cosP*sinY - sinR*sinP*cosY;
}

geo::Rotation
geo::Rotation::operator +(const Rotation& RHS) const
{
  return Rotation( myA + RHS.myA, myA + RHS.myB, myA + RHS.myC, myA + RHS.myD );
}

geo::Rotation
geo::Rotation::operator *(const Rotation& RHS) const
{
  return Rotation(
    myA*RHS.myA - myB*RHS.myB - myC*RHS.myC - myD*RHS.myD,
    myA*RHS.myB + myB*RHS.myA + myC*RHS.myD - myD*RHS.myC,
    myA*RHS.myC - myB*RHS.myD + myC*RHS.myA + myD*RHS.myB,
    myA*RHS.myD + myB*RHS.myC - myC*RHS.myB + myD*RHS.myA );
}

geo::Rotation
geo::Rotation::operator ~() const
{
  return Rotation(myA, -myB, -myC, -myD);
}

void
geo::Rotation::Normalise()
{
  const double lengthSquared = myA*myA + myB*myB + myC*myC + myD*myD;
  if ( lengthSquared == 1.0 ) return;

  const double length = num::Sqrt(lengthSquared);
  myA = myA / length;
  myB = myB / length;
  myC = myC / length;
  myD = myD / length;
}

geo::Transform
geo::Rotation::ToTransform() const
{
/*  return Transform( myA, myB, myC, myD,
                   -myB, myA,-myD, myC,
                   -myC, myD, myA,-myB,
                   -myD,-myC, myB, myA );*/
  
  const double bb2 = 2*myB*myB;
  const double cc2 = 2*myC*myC;
  const double dd2 = 2*myD*myD;
  
  const double ab2 = 2*myA*myB;
  const double ac2 = 2*myA*myC;
  const double ad2 = 2*myA*myD;
  const double bc2 = 2*myB*myC;
  const double bd2 = 2*myB*myD;
  const double cd2 = 2*myC*myD;
  
  return Transform(
    1 - cc2 - dd2, bc2 - ad2,     bd2 + ac2,     0,
    bc2 + ad2,     1 - bb2 - dd2, cd2 - ab2,     0,
    bd2 - ac2,     cd2 + ab2,     1 - bb2 - cc2, 0,
    0,             0,             0,             1 );
}

geo::Rotation&
geo::Rotation::Identity()
{
  static Rotation rotation(1, 0, 0, 0);
  return rotation;
}