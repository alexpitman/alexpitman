#ifndef __CMR_CAMERA_H
#define __CMR_CAMERA_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Camera
// Inheritance    : Base class
// Desctription   : Representation of a basic camera
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Point.h"
#include "geometry/Vector.h"

namespace cmr
{
  class Camera
  {
  public:
    Camera();
  
    Camera( geo::Point3D Position,
            geo::Vector3D LookDirection,
            geo::Vector3D UpDirection );
    
    const geo::Point3D& Position() const;
    const geo::Vector3D& LookDirection() const;
    const geo::Vector3D& UpDirection() const;
    
    void SetCamera() const;
    
    void Translate(const geo::Vector3D& Vector);
    
    // Rotate about static axes
    void RotateX(double Degrees);
    void RotateY(double Degrees);
    void RotateZ(double Degrees);
  
    // Rotate about camera relative axes
    void RotatePitch(double Degrees);
    void RotateRoll(double Degrees); // Around look direction
    void RotateYaw(double Degrees);
  
  private:
  
    geo::Point3D myPosition;
    geo::Vector3D myLookDirection;
    geo::Vector3D myUpDirection;
  
  };
}

#endif
