#ifndef __GEO_VECTOR_H
#define __GEO_VECTOR_H

#include "numeric/num.h"

#include <assert.h>

namespace geo
{
  template<typename T, unsigned int N, typename Derived>
  struct VectorBase
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
      Derived vector;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        vector[i] = derived.data[i] + Rhs[i];
      }
      return vector;
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
      Derived vector;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        vector[i] = derived.data[i] - Rhs[i];
      }
      return vector;
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
      Derived vector;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        vector[i] = derived.data[i] * Rhs;
      }
      return vector;
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
      Derived vector;
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        vector[i] = derived.data[i] / Rhs;
      }
      return vector;
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
    
    // Check for NaN vector.
    bool IsNull() const
    {
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      for (unsigned int i = 0; i < N; ++i)
      {
        if (derived.data[i] != derived.data[i]) return true;
      }
      return false;
    }
    
    // Calculate length of vector.
    T Length() const
    {
      return num::Sqrt(LengthSquared());
    }
    
    // Calculate length squared of vector.
    T LengthSquared() const
    {
      const Derived& derived = reinterpret_cast<const Derived&>(*this);
      
      T sum = 0;
      for (unsigned int i = 0; i < N; ++i)
      {
        sum += derived.data[i] * derived.data[i];
      }
      return sum;
    }
    
    // Normalise the vector.
    void Normalise()
    {
      const T length = Length();
      const T one = 1;
      
      if (length != one)
      {
        const T factor = one / length;
        
        Derived& derived = reinterpret_cast<Derived&>(*this);
        for (unsigned int i = 0; i < N; ++i)
        {
          derived.data[i] *= factor;
        }
      }
    }
  };

  template<typename T, unsigned int N>
  struct Vector : public VectorBase<T, N, Vector<T, N>>
  {
    Vector() {}

    T data[N];
  };
  
  template<typename T>
  struct Vector<T, 2> : public VectorBase<T, 2, Vector<T, 2>>
  {
    Vector() {}
    Vector(T X, T Y) : x(X), y(Y) {}

    T& X() { return x; }
    T& Y() { return y; }
    const T& X() const { return x; }
    const T& Y() const { return y; }
    
    // Special vectors
    static const Vector<T, 2>& Null()
    {
      static const Vector<T, 2> p(num::NaN<T>(), num::NaN<T>());
      return p;
    }
    static const Vector<T, 2>& Zero()
    {
      static const Vector<T, 2> p(0, 0);
      return p;
    }

    // Unit vector positions
    static const Vector<T, 2>& UnitX()
    {
      static const Vector<T, 2> p(1, 0);
      return p;
    }
    static const Vector<T, 2>& UnitY()
    {
      static const Vector<T, 2> p(0, 1);
      return p;
    }
    
    union
    {
      T data[2];
      struct { T x, y; };
    };
  };
  
  template<typename T>
  struct Vector<T, 3> : public VectorBase<T, 3, Vector<T, 3>>
  {
    Vector() {}
    Vector(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

    T& X() { return x; }
    T& Y() { return y; }
    T& Z() { return z; }
    const T& X() const { return x; }
    const T& Y() const { return y; }
    const T& Z() const { return z; }

    // Bring in operator* here so that it is a contender in overload resolution.
    using VectorBase<T, 3, Vector<T, 3>>::operator*;
    // TODO: Should we be using operator* for the cross product?
    
    // Cross product
    Vector<T, 3> operator*(const Vector<T, 3>& Rhs) const
    {
      return Vector<T, 3>(y*Rhs.Z() - z*Rhs.Y(),
                          z*Rhs.X() - x*Rhs.Z(),
                          x*Rhs.Y() - y*Rhs.X());
    }
    
    // Special vectors
    static const Vector<T, 3>& Null()
    {
      static const Vector<T, 3> p(num::NaN<T>(), num::NaN<T>(), num::NaN<T>());
      return p;
    }
    static const Vector<T, 3>& Zero()
    {
      static const Vector<T, 3> p(0, 0, 0);
      return p;
    }

    // Unit vector positions
    static const Vector<T, 3>& UnitX()
    {
      static const Vector<T, 3> p(1, 0, 0);
      return p;
    }
    static const Vector<T, 3>& UnitY()
    {
      static const Vector<T, 3> p(0, 1, 0);
      return p;
    }
    static const Vector<T, 3>& UnitZ()
    {
      static const Vector<T, 3> p(0, 0, 1);
      return p;
    }
    
    union
    {
      T data[3];
      struct { T x, y, z; };
    };
  };
  
  template<typename T>
  struct Vector<T, 4> : public VectorBase<T, 4, Vector<T, 4>>
  {
    Vector() {}
    Vector(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W) {}

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
  
  typedef Vector<double, 2> Vector2D;
  typedef Vector<double, 3> Vector3D;
  typedef Vector<double, 4> Vector4D;
}

/*
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Vector2D, Vector3D
// Inheritance    : Base class
// Desctription   : Structs that represent 2D and 3D vectors respectively.
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Dll.h"

///////////////////////////////////////////////////////////////////////////////
//
// Name: Vector2D
// Desctription: Memory storage and opperations for a 2D vector
//
///////////////////////////////////////////////////////////////////////////////

namespace geo
{
  struct Dll_geo Vector2D
  {
  public:
    // Default constructor.
    Vector2D();

    // Standard constructor.
    Vector2D(double X, double Y);

    inline double X() const;
    inline double Y() const;

    inline double operator[] (unsigned short int Index) const;

    Vector2D& operator =(const Vector2D& RHS);

    Vector2D operator +(const Vector2D& RHS) const;
    Vector2D operator -(const Vector2D& RHS) const;

    Vector2D& operator +=(const Vector2D& RHS);
    Vector2D& operator -=(const Vector2D& RHS);

    bool operator ==(const Vector2D& RHS) const;
    bool operator !=(const Vector2D& RHS) const;

    double Length() const;
    double LengthSquared() const;
    
    void Normalise();
    
    static Vector2D& Zero();
    static Vector2D& Null();
    static Vector2D& UnitX();
    static Vector2D& UnitY();

  private:
    double myX;
    double myY;
  };
}

///////////////////// INLINE DECLARATIONS /////////////////////////////////////
double geo::Vector2D::X() const { return myX; }
double geo::Vector2D::Y() const { return myY; }

///////////////////////////////////////////////////////////////////////////////
double 
geo::Vector2D::operator[] (unsigned short int Index) const
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
// Name: Vector3D
// Desctription: Memory storage and opperations for a 3D vector
//
///////////////////////////////////////////////////////////////////////////////

namespace geo
{
  struct Dll_geo Vector3D
  {
  public:
    // Default constructor.
    Vector3D();

    // Standard constructor.
    Vector3D(double X, double Y, double Z);

    inline double X() const;
    inline double Y() const;
    inline double Z() const;

    inline double operator[] (unsigned short int Index) const;

    Vector3D& operator =(const Vector3D& RHS);

    Vector3D operator +(const Vector3D& RHS) const;
    Vector3D operator -(const Vector3D& RHS) const;
    Vector3D operator *(double RHS) const;
    Vector3D operator /(double RHS) const;
    
    Vector3D& operator +=(const Vector3D& RHS);
    Vector3D& operator -=(const Vector3D& RHS);
    
    bool operator ==(const Vector3D& RHS) const;
    bool operator !=(const Vector3D& RHS) const;

    Vector3D operator -() const;
    
    // Cross product
    Vector3D operator *(const Vector3D& RHS) const;

    double Length() const;
    double LengthSquared() const;
    
    void Normalise();

    static Vector3D& Zero();
    static Vector3D& Null();
    static Vector3D& UnitX();
    static Vector3D& UnitY();
    static Vector3D& UnitZ();
    
  private:
    double myX;
    double myY;
    double myZ;
  };
}

///////////////////// INLINE DECLARATIONS /////////////////////////////////////
double geo::Vector3D::X() const { return myX; }
double geo::Vector3D::Y() const { return myY; }
double geo::Vector3D::Z() const { return myZ; }

///////////////////////////////////////////////////////////////////////////////
double 
geo::Vector3D::operator[] (unsigned short int Index) const
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
