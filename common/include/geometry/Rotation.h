#ifndef __GEO_ROTATION_H
#define __GEO_ROTATION_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Rotation
// Inheritance    : Base class
// Desctription   : Struct that represents a 3D rotation.
//                  http://en.wikipedia.org/wiki/Quaternion
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Vector.h"
#include "geometry/Transform.h"

namespace geo
{
  struct Dll_geo Rotation
  {
  public:
    // Default constructor (identity)
    Rotation();
    
    Rotation(double A, double B, double C, double D);
    
    // Rotation about a vector.
    Rotation(const geo::Vector3D& Vector, double Degrees);
    
    // Rotation specified in roll/pitch/yaw
    Rotation(double Roll, double Pitch, double Yaw);
    
    Rotation operator +(const Rotation& RHS) const;
    Rotation operator *(const Rotation& RHS) const;
    
    // Inverse (opposite rotation)
    Rotation operator ~() const;
    
    void Normalise();
    
    Transform ToTransform() const;
    
    // Special rotations
    static Rotation& Identity();
  
  private:
  
    // H = a + bi + cj + dk
    double myA;
    double myB;
    double myC;
    double myD;
  
  };
}

#endif
