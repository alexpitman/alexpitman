#include "geometry/Extent.h"
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Extent3D
// Inheritance    : Base struct
// Desctription   : See header.
//
///////////////////////////////////////////////////////////////////////////////

geo::Extent3D::Extent3D()
{
  myMin = Point3D::Empty();
  myMax = Point3D::Empty();
}

geo::Extent3D::Extent3D( const Extent3D& Extent3D )
{
  myMin = Extent3D.Min();
  myMax = Extent3D.Max();
}

///////////////////////////////////////////////////////////////////////////////
geo::Extent3D 
geo::Extent3D::operator +(const Point3D& RHS) const
{
  Extent3D Extent3D( *this );
  Extent3D += RHS;
  return Extent3D;
}

///////////////////////////////////////////////////////////////////////////////
geo::Extent3D& 
geo::Extent3D::operator +=(const Point3D& RHS)
{
  if ( myMin.IsEmpty() && myMax.IsEmpty() )
  {
    myMin = RHS;
    myMax = RHS;
  }
  else
  {
    if ( myMin.X() > RHS.X() ) myMin.X() = RHS.X();
    else if ( myMax.X() < RHS.X() ) myMax.X() = RHS.X();
    
    if ( myMin.Y() > RHS.Y() ) myMin.Y() = RHS.Y();
    else if ( myMax.Y() < RHS.Y() ) myMax.Y() = RHS.Y();
    
    if ( myMin.Z() > RHS.Z() ) myMin.Z() = RHS.Z();
    else if ( myMax.Z() < RHS.Z() ) myMax.Z() = RHS.Z();
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D 
geo::Extent3D::Min() const
{
  return myMin;
}

///////////////////////////////////////////////////////////////////////////////
geo::Point3D 
geo::Extent3D::Max() const
{
  return myMax;
}

///////////////////////////////////////////////////////////////////////////////
geo::Vector3D
geo::Extent3D::Span() const
{
  return myMax.ToVector() - myMin.ToVector();
}