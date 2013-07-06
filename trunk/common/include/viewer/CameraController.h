#ifndef __VWR_CAMERA_CONTROLLER_H
#define __VWR_CAMERA_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : CameraController
// Inheritance    : Base class 
// Description    : Camera manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/Dll.h"

#include "camera/Camera.h"

#include <memory>

namespace vwr
{
  class CameraController;
  class View;
  
  typedef std::shared_ptr<CameraController> T_CameraControllerPtr;
  
  class Dll_vwr CameraController
  {
  public:
    
    CameraController(vwr::View* ViewPtr);
    
    const cmr::Camera& Camera() const;
    
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
  
    vwr::View* myViewPtr;
  
  };
}

#endif
