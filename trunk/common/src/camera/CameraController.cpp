///////////////////////////////////////////////////////////////////////////////
//
// Name           : CameraController
// Inheritance    : Base class 
// Desctription   : Camera manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/CameraController.h"

#include "viewer/View.h"

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

void
cmr::CameraController::Forward(double Distance)
{
  myViewPtr->myCamera.Forward(Distance);
}

void cmr::CameraController::Backward(double Distance)
{
  myViewPtr->myCamera.Backward(Distance);
}

void cmr::CameraController::StrafeLeft(double Distance)
{
  myViewPtr->myCamera.StrafeLeft(Distance);
}

void cmr::CameraController::StrafeRight(double Distance)
{
  myViewPtr->myCamera.StrafeRight(Distance);
}

void cmr::CameraController::StrafeUp(double Distance)
{
  myViewPtr->myCamera.StrafeUp(Distance);
}

void cmr::CameraController::StrafeDown(double Distance)
{
  myViewPtr->myCamera.StrafeDown(Distance);
}

void cmr::CameraController::RotateX(double Degrees)
{
  myViewPtr->myCamera.RotateX(Degrees);
}

void cmr::CameraController::RotateY(double Degrees)
{
  myViewPtr->myCamera.RotateY(Degrees);
}

void cmr::CameraController::RotateZ(double Degrees)
{
  myViewPtr->myCamera.RotateZ(Degrees);
}

void cmr::CameraController::RotatePitch(double Degrees)
{
  myViewPtr->myCamera.RotatePitch(Degrees);
}

void cmr::CameraController::RotateRoll(double Degrees)
{
  myViewPtr->myCamera.RotateRoll(Degrees);
}

void cmr::CameraController::RotateYaw(double Degrees)
{
  myViewPtr->myCamera.RotateYaw(Degrees);
}

