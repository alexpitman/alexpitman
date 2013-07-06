///////////////////////////////////////////////////////////////////////////////
//
// Name           : CameraController
// Inheritance    : Base class 
// Description    : Camera manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/CameraController.h"

#include "viewer/View.h"

vwr::CameraController::CameraController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr)
{
}
    
const cmr::Camera&
vwr::CameraController::Camera() const
{
  return myViewPtr->myCamera;
}

void
vwr::CameraController::Translate(const geo::Vector3D& Vector)
{
  myViewPtr->myCamera.Translate(Vector);
}

void
vwr::CameraController::Forward(double Distance)
{
  myViewPtr->myCamera.Forward(Distance);
}

void vwr::CameraController::Backward(double Distance)
{
  myViewPtr->myCamera.Backward(Distance);
}

void vwr::CameraController::StrafeLeft(double Distance)
{
  myViewPtr->myCamera.StrafeLeft(Distance);
}

void vwr::CameraController::StrafeRight(double Distance)
{
  myViewPtr->myCamera.StrafeRight(Distance);
}

void vwr::CameraController::StrafeUp(double Distance)
{
  myViewPtr->myCamera.StrafeUp(Distance);
}

void vwr::CameraController::StrafeDown(double Distance)
{
  myViewPtr->myCamera.StrafeDown(Distance);
}

void vwr::CameraController::RotateX(double Degrees)
{
  myViewPtr->myCamera.RotateX(Degrees);
}

void vwr::CameraController::RotateY(double Degrees)
{
  myViewPtr->myCamera.RotateY(Degrees);
}

void vwr::CameraController::RotateZ(double Degrees)
{
  myViewPtr->myCamera.RotateZ(Degrees);
}

void vwr::CameraController::RotatePitch(double Degrees)
{
  myViewPtr->myCamera.RotatePitch(Degrees);
}

void vwr::CameraController::RotateRoll(double Degrees)
{
  myViewPtr->myCamera.RotateRoll(Degrees);
}

void vwr::CameraController::RotateYaw(double Degrees)
{
  myViewPtr->myCamera.RotateYaw(Degrees);
}

