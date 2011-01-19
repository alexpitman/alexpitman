#ifndef __GEO_VECTOR_H
#define __GEO_VECTOR_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Vector2D, Vector3D
// Inheritance    : Base class
// Desctription   : Structs that represent 2D and 3D vectors respectively.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Name: Vector2D
// Desctription: Memory storage and opperations for a 2D vector
//
///////////////////////////////////////////////////////////////////////////////

namespace geo
{
  struct Vector2D
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
  struct Vector3D
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

#endif
