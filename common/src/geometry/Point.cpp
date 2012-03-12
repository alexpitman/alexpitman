#include "geometry/Point.h"

#include "numeric/num.h"

///////////////////////////////////////////////////////////////////////////////
//
// Name           : Point2D
// Inheritance    : Base struct
// Desctription   : See header.
//
///////////////////////////////////////////////////////////////////////////////

geo::Point2D::Point2D() {}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D::Point2D(double X, double Y)
{
  myX = X;
  myY = Y;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D&
geo::Point2D::operator =(const Point2D& RHS)
{
  myX = RHS.X();
  myY = RHS.Y();
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D 
geo::Point2D::operator +(const Vector2D& RHS) const
{
  return Point2D( myX + RHS.X(), myY + RHS.Y() );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D 
geo::Point2D::operator -(const Vector2D& RHS) const
{
  return Point2D( myX - RHS.X(), myY - RHS.Y() );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D& 
geo::Point2D::operator +=(const Vector2D& RHS)
{
  myX += RHS.X();
  myY += RHS.Y();
  return *this; 
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D& 
geo::Point2D::operator -=(const Vector2D& RHS)
{
  myX -= RHS.X();
  myY -= RHS.Y();
  return *this;   
}

///////////////////////////////////////////////////////////////////////////////
bool 
geo::Point2D::operator ==(const Point2D& RHS) const
{
  return ( myX == RHS.X() && myY == RHS.Y() );
}

///////////////////////////////////////////////////////////////////////////////
bool 
geo::Point2D::operator !=(const Point2D& RHS) const
{
  return !operator==(RHS);
}

///////////////////////////////////////////////////////////////////////////////
bool
geo::Point2D::operator <(const Point2D& RHS) const
{
  if (myX < RHS.myX) return true;
  if (myX > RHS.myX) return false;
  return myY < RHS.myY;
}

///////////////////////////////////////////////////////////////////////////////
geo::Vector2D
geo::Point2D::ToVector() const
{
  return Vector2D(myX, myY);
}

///////////////////////////////////////////////////////////////////////////////
geo::Vector2D 
geo::Point2D::operator -(const Point2D& RHS) const
{
  return Vector2D( myX - RHS.X(), myY - RHS.Y() );
}

///////////////////////////////////////////////////////////////////////////////
geo::Vector2D 
geo::Point2D::operator -=(const Point2D& RHS) const
{
  return Vector2D( myX - RHS.X(), myY - RHS.Y() );
}

///////////////////////////////////////////////////////////////////////////////
bool 
geo::Point2D::IsNull() const
{
  return ( myX != myX || myY != myY );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D& 
geo::Point2D::Null()
{
  static Point2D pt( num::NaN<double>(),
                     num::NaN<double>() );
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D& 
geo::Point2D::Origin()
{
  static Point2D pt(0, 0);
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D& 
geo::Point2D::UnitX()
{
  static Point2D pt(1, 0);
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point2D& 
geo::Point2D::UnitY()
{
  static Point2D pt(0, 1);
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
//
// Name           : Point3D
// Inheritance    : Base struct 
// Desctription   : See header.
//
///////////////////////////////////////////////////////////////////////////////

geo::Point3D::Point3D() {};

///////////////////////////////////////////////////////////////////////////////
geo::Point3D::Point3D(double X, double Y, double Z)
{
  myX = X;
  myY = Y;
  myZ = Z;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D&
geo::Point3D::operator =(const Point3D& RHS)
{
  myX = RHS.X();
  myY = RHS.Y();
  myZ = RHS.Z();
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D
geo::Point3D::operator +(const Vector3D& RHS) const
{
  return Point3D( myX + RHS.X(), myY + RHS.Y(), myZ + RHS.Z() );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D
geo::Point3D::operator -(const Vector3D& RHS) const
{
  return Point3D( myX - RHS.X(), myY - RHS.Y(), myZ - RHS.Z() );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D 
geo::Point3D::operator *(double RHS) const
{
  return Point3D( myX*RHS, myY*RHS, myZ*RHS );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D 
geo::Point3D::operator /(double RHS) const
{
  return Point3D( myX/RHS, myY/RHS, myZ/RHS );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D& 
geo::Point3D::operator +=(const Vector3D& RHS)
{
  myX += RHS.X();
  myY += RHS.Y();
  myZ += RHS.Z();
  return *this; 
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D& 
geo::Point3D::operator -=(const Vector3D& RHS)
{
  myX -= RHS.X();
  myY -= RHS.Y();
  myZ -= RHS.Z();
  return *this;   
}

///////////////////////////////////////////////////////////////////////////////
bool 
geo::Point3D::operator ==(const Point3D& RHS) const
{
  return ( myX == RHS.X() && myY == RHS.Y() && myZ == RHS.Z() );
}

///////////////////////////////////////////////////////////////////////////////
bool 
geo::Point3D::operator !=(const Point3D& RHS) const
{
  return !operator==(RHS);
}

///////////////////////////////////////////////////////////////////////////////
bool
geo::Point3D::operator <(const Point3D& RHS) const
{
  if (myX < RHS.myX) return true;
  if (myX > RHS.myX) return false;
  if (myY < RHS.myY) return true;
  if (myY > RHS.myY) return false;
  return myZ < RHS.myZ;
}

///////////////////////////////////////////////////////////////////////////////
geo::Vector3D 
geo::Point3D::operator -(const Point3D& RHS) const
{
  return Vector3D( myX-RHS.X(), myY-RHS.Y(), myZ-RHS.Z());
}

///////////////////////////////////////////////////////////////////////////////
geo::Vector3D
geo::Point3D::ToVector() const
{
  return Vector3D(myX, myY, myZ);
}

///////////////////////////////////////////////////////////////////////////////
bool 
geo::Point3D::IsNull() const
{
  return ( myX != myX || myY != myY || myZ != myZ );
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D& 
geo::Point3D::Null()
{
  static Point3D pt( num::NaN<double>(),
                     num::NaN<double>(), 
                     num::NaN<double>() );
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D& 
geo::Point3D::Origin()
{
  static Point3D pt(0, 0, 0);
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D& 
geo::Point3D::UnitX()
{
  static Point3D pt(1, 0, 0);
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D& 
geo::Point3D::UnitY()
{
  static Point3D pt(0, 1, 0);
  return pt;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D& 
geo::Point3D::UnitZ()
{
  static Point3D pt(0, 0, 1);
  return pt;
}
