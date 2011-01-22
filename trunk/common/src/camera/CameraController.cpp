///////////////////////////////////////////////////////////////////////////////
//
// Name           : CameraController
// Inheritance    : Base class 
// Desctription   : Camera manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/CameraController.h"

#include "viewer/View.h"

cmr::CameraController::CameraController()
: myViewPtr(NULL)
{
}

cmr::CameraController::CameraController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr)
{
}
    
const cmr::Camera&
cmr::CameraController::Camera() const
{
  return myViewPtr->myCamera;
}

void
cmr::CameraController::Translate(const geo::Vector3D& Vector)
{
  myViewPtr->myCamera.Translate(Vector);
}