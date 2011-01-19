#ifndef __GEOMETRY_POINT_H
#define __GEOMETRY_POINT_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Point2D, Point
// Inheritance    : Base class
// Desctription   : Structs that represent 2D and 3D points respectively.
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Vector.h"

///////////////////////////////////////////////////////////////////////////////
//
// Name: Point2D
// Desctription: Memory storage and opperations for a 2D point
//
///////////////////////////////////////////////////////////////////////////////

namespace geo
{
  struct Point2D
  {
  public:
    // Default constructor.
    Point2D();

    // Standard constructor.
    Point2D( const double X, const double Y);

    Point2D& operator =(const Point2D& RHS);

    inline double X() const;
    inline double Y() const;
    
    inline double& X();
    inline double& Y();

    inline double operator[] (unsigned short int Index) const;
    inline double& operator[] (unsigned short int Index);
    
    Point2D operator +(const Vector2D& RHS) const;
    Point2D operator -(const Vector2D& RHS) const;

    Point2D& operator +=(const Vector2D& RHS);
    Point2D& operator -=(const Vector2D& RHS);

    bool operator ==(const Point2D& RHS) const;
    bool operator !=(const Point2D& RHS) const;

    Vector2D ToVector() const;
    
    Vector2D operator -(const Point2D& RHS) const;
    Vector2D operator -=(const Point2D& RHS) const;

    // Special points
    static Point2D& Origin();

    // Unit vector positions
    static Point2D& UnitX();
    static Point2D& UnitY();

  private:
    double myX;
    double myY;
  };
}

///////////////////// INLINE DECLARATIONS /////////////////////////////////////
double geo::Point2D::X() const { return myX; }
double geo::Point2D::Y() const { return myY; }

double& geo::Point2D::X() { return myX; }
double& geo::Point2D::Y() { return myY; }

///////////////////////////////////////////////////////////////////////////////
double 
geo::Point2D::operator[] (unsigned short int Index) const
{
  switch ( Index )
  {
  case 0:
    return myX;
  case 1:
    return myY;
  default:
    // ASSERT_UNREACHABLE();
    return myX;
  }
}
double& 
geo::Point2D::operator[] (unsigned short int Index)
{
  switch ( Index )
  {
  case 0:
    return myX;
  case 1:
    return myY;
  default:
    // ASSERT_UNREACHABLE();
    return myX;
  }
}

///////////////////////////////////////////////////////////////////////////////
//
// Name: Point3D
// Desctription: Memory storage and opperations for a 3D point
//
///////////////////////////////////////////////////////////////////////////////

namespace geo
{
  struct Point3D
  {
  public:
    // Default constructor.
    Point3D();

    // Standard constructor.
    Point3D(double X, double Y, double Z);

    inline double X() const;
    inline double Y() const;
    inline double Z() const;
    
    inline double& X();
    inline double& Y();
    inline double& Z();

    inline double operator[] (unsigned short int Index) const;
    inline double& operator[] (unsigned short int Index);

    Point3D& operator =(const Point3D& RHS);

    Point3D operator +(const Vector3D& RHS) const;
    Point3D operator -(const Vector3D& RHS) const;
    Point3D operator *(double RHS) const;
    Point3D operator /(double RHS) const;

    Point3D& operator +=(const Vector3D& RHS);
    Point3D& operator -=(const Vector3D& RHS);

    bool operator ==(const Point3D& RHS) const;
    bool operator !=(const Point3D& RHS) const;

    Vector3D operator -(const Point3D& RHS) const;
    
    Vector3D ToVector() const;
    
    bool IsEmpty() const;

    // Special Points
    static Point3D& Empty();
    static Point3D& Origin();

    // Unit vector positions
    static Point3D& UnitX();
    static Point3D& UnitY();
    static Point3D& UnitZ();

  private:
    double myX;
    double myY;
    double myZ;
  };
}

///////////////////// INLINE DECLARATIONS /////////////////////////////////////
double geo::Point3D::X() const { return myX; }
double geo::Point3D::Y() const { return myY; }
double geo::Point3D::Z() const { return myZ; }

///////////////////////////////////////////////////////////////////////////////
double& geo::Point3D::X() { return myX; }
double& geo::Point3D::Y() { return myY; }
double& geo::Point3D::Z() { return myZ; }

///////////////////////////////////////////////////////////////////////////////
double 
geo::Point3D::operator[] (unsigned short int Index) const
{
  switch ( Index )
  {
  case 0:
    return myX;
  case 1:
    return myY;
  case 2:
    return myZ;
  default:
    // ASSERT_UNREACHABLE();
    return myX;
  }
}

double& 
geo::Point3D::operator[] (unsigned short int Index)
{
  switch ( Index )
  {
  case 0:
    return myX;
  case 1:
    return myY;
  case 2:
    return myZ;
  default:
    // ASSERT_UNREACHABLE();
    return myX;
  }
}

#endif
