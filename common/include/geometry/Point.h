#ifndef __GEOMETRY_POINT_H
#define __GEOMETRY_POINT_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Point2D, Point3D, Point4D
// Description    : Template struct that represents points in different dimensions.
//
///////////////////////////////////////////////////////////////////////////////

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
    
    // Addition with a vector.
    Derived operator+(const Vector<T, N>& Rhs) const
    {
      Derived point;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        point[i] = derived.data[i] + Rhs[i];
      }
      return point;
    }
    Derived& operator+=(const Vector<T, N>& Rhs)
    {
      Derived& derived = reinterpret_cast<Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        derived.data[i] += Rhs[i];
      }
      return reinterpret_cast<Derived&>(*this);
    }
    
    // Subtraction with a vector.
    Derived operator-(const Vector<T, N>& Rhs) const
    {
      Derived point;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        point[i] = derived.data[i] - Rhs[i];
      }
      return point;
    }
    Derived& operator-=(const Vector<T, N>& Rhs)
    {
      Derived& derived = reinterpret_cast<Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        derived.data[i] -= Rhs[i];
      }
      return reinterpret_cast<Derived&>(*this);
    }
    
    // Unary minus.
    Derived operator-() const
    {
      Derived point;
      Derived& derived = reinterpret_cast<Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        point[i] = -derived.data[i];
      }
      return point;
    }
    
    // Subtraction with a point (resulting in a vector).
    Vector<T, N> operator-(const Derived& Rhs) const
    {
      Vector<T, N> vector;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        vector[i] = derived.data[i] - Rhs[i];
      }
      return vector;
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
    
    // Check for NaN point.
    bool IsNull() const
    {
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        if (derived.data[i] != derived.data[i]) return true;
      }
      return false;
    }
    
    // Reinterpret a point as a vector.
    const Vector<T, N>& ToVector() const
    {
      return reinterpret_cast<const Vector<T, N>&>(*this);
    }
    Vector<T, N>& ToVector()
    {
      return reinterpret_cast<Vector<T, N>&>(*this);
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

#endif
