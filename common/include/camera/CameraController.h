#ifndef __CMR_CAMERA_CONTROLLER_H
#define __CMR_CAMERA_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : CameraController
// Inheritance    : Base class 
// Desctription   : Camera manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/Camera.h"

#include "boost/shared_ptr.hpp"

namespace vwr
{
  class View;
}

namespace cmr
{
  class CameraController;
  
  typedef boost::shared_ptr<CameraController> T_CameraControllerPtr;
  
  class CameraController
  {
  public:
  
    CameraController();
    
    CameraController(vwr::View* ViewPtr);
    
    const Camera& Camera() const;
    
    void Translate(const geo::Vector3D& Vector);
  
  private:
  
    vwr::View* myViewPtr;
  
  };
}

#endif
