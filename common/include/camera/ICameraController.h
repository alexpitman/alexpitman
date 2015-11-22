#ifndef __CMR_I_CAMERA_CONTROLLER_H
#define __CMR_I_CAMERA_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : CameraController
// Inheritance    : Base class 
// Description    : Camera manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/Camera.h"

#include <memory>

namespace cmr
{
  class ICameraController;
  
  typedef std::shared_ptr<ICameraController> T_CameraControllerPtr;
  
  class ICameraController
  {
  public:
    
    virtual const cmr::Camera& Camera() const = 0;
    
    // Translate using an arbitrary vector.
    virtual void Translate(const geo::Vector3D& Vector) = 0;
    
    // Translate relative to camera axes
    virtual void Forward(double Distance) = 0;
    virtual void Backward(double Distance) = 0;
    virtual void StrafeLeft(double Distance) = 0;
    virtual void StrafeRight(double Distance) = 0;
    virtual void StrafeUp(double Distance) = 0;
    virtual void StrafeDown(double Distance) = 0;
    
    // Rotate about static axes
    virtual void RotateX(double Degrees) = 0;
    virtual void RotateY(double Degrees) = 0;
    virtual void RotateZ(double Degrees) = 0;
  
    // Rotate about camera relative axes
    virtual void RotatePitch(double Degrees) = 0;
    virtual void RotateRoll(double Degrees) = 0;
    virtual void RotateYaw(double Degrees) = 0;
    
    virtual void ZoomToFit(const geo::Vector3D& LookDirection, const geo::Vector3D& UpDirection) = 0;
  };
}

#endif
