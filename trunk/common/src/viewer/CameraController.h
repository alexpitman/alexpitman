#ifndef __VWR_CAMERA_CONTROLLER_H
#define __VWR_CAMERA_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : CameraController
// Inheritance    : Base class 
// Description    : Camera manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/ICameraController.h"
#include "camera/Camera.h"

#include <memory>

namespace vwr
{
  class View;
  
  class CameraController : public cmr::ICameraController
  {
  public:
    
    CameraController(vwr::View* ViewPtr);
    
    const cmr::Camera& Camera() const override;
    
    // Translate using an arbitrary vector.
    void Translate(const geo::Vector3D& Vector) override;
    
    // Translate relative to camera axes
    void Forward(double Distance) override;
    void Backward(double Distance) override;
    void StrafeLeft(double Distance) override;
    void StrafeRight(double Distance) override;
    void StrafeUp(double Distance) override;
    void StrafeDown(double Distance) override;
    
    // Rotate about static axes
    void RotateX(double Degrees) override;
    void RotateY(double Degrees) override;
    void RotateZ(double Degrees) override;
  
    // Rotate about camera relative axes
    void RotatePitch(double Degrees) override;
    void RotateRoll(double Degrees) override;
    void RotateYaw(double Degrees) override;
  
  private:
  
    vwr::View* myViewPtr;
  
  };
}

#endif
