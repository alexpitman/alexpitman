#ifndef __GEOMETRY_POINT_H
#define __GEOMETRY_POINT_H

#include "geometry/Vector.h"

#include "numeric/num.h"

#include <assert.h>

namespace geo
{
  template<typename T, unsigned int N, typename Derived>
  struct PointBase
  {
    // Per-element accessor.
    const T& operator[] (unsigned int Index) const
    {
      assert(Index < N);
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      return derived.data[Index];
    }
    T& operator[] (unsigned int Index)
    {
      assert(Index < N);
      Derived& derived = reinterpret_cast<Derived&>(*this);
      return derived.data[Index];
    }
    
    // Addition.
    Derived operator+(const Derived& Rhs) const
    {
      Derived point;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        point[i] = derived.data[i] + Rhs[i];
      }
      return point;
    }
    Derived& operator+=(const Derived& Rhs)
    {
      Derived& derived = reinterpret_cast<Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        derived.data[i] += Rhs[i];
      }
      return reinterpret_cast<Derived&>(*this);
    }
    
    // Subtraction.
    Derived operator-(const Derived& Rhs) const
    {
      Derived point;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        point[i] = derived.data[i] - Rhs[i];
      }
      return point;
    }
    Derived& operator-=(const Derived& Rhs)
    {
      Derived& derived = reinterpret_cast<Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        derived.data[i] -= Rhs[i];
      }
      return reinterpret_cast<Derived&>(*this);
    }
    
    // Multiplication by factor.
    Derived operator*(T Rhs) const
    {
      Derived point;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        point[i] = derived.data[i] * Rhs;
      }
      return point;
    }
    Derived& operator*=(T Rhs)
    {
      Derived& derived = reinterpret_cast<Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        derived.data[i] *= Rhs;
      }
      return reinterpret_cast<Derived&>(*this);
    }
    
    // Division by factor.
    Derived operator/(T Rhs) const
    {
      Derived point;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        point[i] = derived.data[i] / Rhs;
      }
      return point;
    }
    Derived& operator/=(T Rhs)
    {
      Derived& derived = reinterpret_cast<Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        derived.data[i] /= Rhs;
      }
      return reinterpret_cast<Derived&>(*this);
    }
    
    // Equality.
    bool operator==(const Derived& Rhs) const
    {
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        if (derived.data[i] != Rhs[i]) return false;
      }
      return true;
    }
    bool operator!=(const Derived& Rhs) const
    {
      return !operator==(Rhs);
    }

    // Comparator for use in STL containers.
    bool operator <(const Derived& Rhs) const
    {
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        if      (derived.data[i] < Rhs[i]) return true;
        else if (derived.data[i] > Rhs[i]) return false;
      }
      return false;
    }
    
    bool IsNull() const
    {
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        if (derived.data[i] != derived.data[i]) return true;
      }
      return false;
    }
  };

  template<typename T, unsigned int N>
  struct Point : public PointBase<T, N, Point<T, N>>
  {
    Point() {}

    T data[N];
  };
  
  template<typename T>
  struct Point<T, 2> : public PointBase<T, 2, Point<T, 2>>
  {
    Point() {}
    Point(T X, T Y) : x(X), y(Y) {}

    T& X() { return x; }
    T& Y() { return y; }
    const T& X() const { return x; }
    const T& Y() const { return y; }

    Vector2D ToVector() const { return Vector2D(x, y); }
    
    // Special points
    static const Point<T, 2>& Null()
    {
      static const Point<T, 2> p(num::NaN<T>(), num::NaN<T>());
      return p;
    }
    static const Point<T, 2>& Origin()
    {
      static const Point<T, 2> p(0, 0);
      return p;
    }

    // Unit vector positions
    static const Point<T, 2>& UnitX()
    {
      static const Point<T, 2> p(1, 0);
      return p;
    }
    static const Point<T, 2>& UnitY()
    {
      static const Point<T, 2> p(0, 1);
      return p;
    }
    
    union
    {
      T data[2];
      struct { T x, y; };
    };
  };
  
  template<typename T>
  struct Point<T, 3> : public PointBase<T, 3, Point<T, 3>>
  {
    Point() {}
    Point(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

    T& X() { return x; }
    T& Y() { return y; }
    T& Z() { return z; }
    const T& X() const { return x; }
    const T& Y() const { return y; }
    const T& Z() const { return z; }
    
    Vector3D ToVector() const { return Vector3D(x, y, z); }

    // Special points
    static const Point<T, 3>& Null()
    {
      static const Point<T, 3> p(num::NaN<T>(), num::NaN<T>(), num::NaN<T>());
      return p;
    }
    static const Point<T, 3>& Origin()
    {
      static const Point<T, 3> p(0, 0, 0);
      return p;
    }

    // Unit vector positions
    static const Point<T, 3>& UnitX()
    {
      static const Point<T, 3> p(1, 0, 0);
      return p;
    }
    static const Point<T, 3>& UnitY()
    {
      static const Point<T, 3> p(0, 1, 0);
      return p;
    }
    static const Point<T, 3>& UnitZ()
    {
      static const Point<T, 3> p(0, 0, 1);
      return p;
    }
    
    union
    {
      T data[3];
      struct { T x, y, z; };
    };
  };
  
  template<typename T>
  struct Point<T, 4> : public PointBase<T, 4, Point<T, 4>>
  {
    Point() {}
    Point(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W) {}

    T& X() { return x; }
    T& Y() { return y; }
    T& Z() { return z; }
    T& W() { return w; }
    const T& X() const { return x; }
    const T& Y() const { return y; }
    const T& Z() const { return z; }
    const T& W() const { return w; }

    union
    {
      T data[4];
      struct { T x, y, z, w; };
    };
  };
  
  typedef Point<double, 2> Point2D;
  typedef Point<double, 3> Point3D;
  typedef Point<double, 4> Point4D;
}
/*

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
  struct Dll_geo Point2D
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

    bool operator <(const Point2D& RHS) const;
    
    Vector2D ToVector() const;
    
    Vector2D operator -(const Point2D& RHS) const;
    Vector2D operator -=(const Point2D& RHS) const;

    bool IsNull() const;
    
    // Special points
    static Point2D& Null();
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
  struct Dll_geo Point3D
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

    bool operator <(const Point3D& RHS) const;
    
    Vector3D operator -(const Point3D& RHS) const;
    
    Vector3D ToVector() const;
    
    bool IsNull() const;

    // Special Points
    static Point3D& Null();
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
*/
#endif
