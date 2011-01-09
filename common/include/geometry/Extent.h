#ifndef __GEOMETRY_EXTENT_H
#define __GEOMETRY_EXTENT_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Extent2D, Extent3D
// Inheritance    : Struct
// Desctription   : Structs that represent 2D and 3D extents respectively.
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Point.h"
#include "geometry/Vector.h"

///////////////////////////////////////////////////////////////////////////////
//
// Name: Extent2D
// Desctription: Memory storage and opperations for a 2D extent
//
///////////////////////////////////////////////////////////////////////////////

// TODO

///////////////////////////////////////////////////////////////////////////////
//
// Name: Extent3D
// Desctription: Memory storage and opperations for a 3D extent
//
///////////////////////////////////////////////////////////////////////////////

struct Extent3D
{
public:
  Extent3D();
  
  Extent3D( const Extent3D& Extent3D );
  
  Extent3D operator +(const Point3D& RHS) const;
  
  Extent3D& operator +=(const Point3D& RHS);
  
  Point3D Min() const;
  Point3D Max() const;
  
  Vector3D Span() const;

private:
  Point3D myMin;
  Point3D myMax;
};

#endif
