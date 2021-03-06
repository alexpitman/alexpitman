#ifndef __CMR_CAMERA_H
#define __CMR_CAMERA_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Camera
// Inheritance    : Base class
// Desctription   : Representation of a basic camera
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/Dll.h"

#include "geometry/Point.h"
#include "geometry/Vector.h"

namespace cmr
{
  class Dll_cmr Camera
  {
  public:
    Camera();
  
    Camera( geo::Point3D Position,
            geo::Vector3D LookDirection,
            geo::Vector3D UpDirection );
    
    const geo::Point3D& Position() const;
    const geo::Vector3D& LookDirection() const;
    const geo::Vector3D& UpDirection() const;
    
    // Set the camera position.
    void SetPosition(const geo::Point3D& Position);
    
    // Set specific look/up directions.
    void SetLookDirection(const geo::Vector3D& Vector);
    void SetUpDirection(const geo::Vector3D& Vector);
    
    // Translate using an arbitrary vector.
    void Translate(const geo::Vector3D& Vector);
    
    // Translate relative to camera axes
    void Forward(double Distance);
    void Backward(double Distance);
    void StrafeLeft(double Distance);
    void StrafeRight(double Distance);
    void StrafeUp(double Distance);
    void StrafeDown(double Distance);
    
    // Rotate about static axes
    void RotateX(double Degrees);
    void RotateY(double Degrees);
    void RotateZ(double Degrees);
  
    // Rotate about camera relative axes
    void RotatePitch(double Degrees);
    void RotateRoll(double Degrees);
    void RotateYaw(double Degrees);
    
    
    
  
  private:
  
    geo::Point3D myPosition;
    geo::Vector3D myLookDirection;
    geo::Vector3D myUpDirection;
  
  };
}

#endif
