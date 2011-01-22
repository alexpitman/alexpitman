///////////////////////////////////////////////////////////////////////////////
//
// Name           : Camera
// Inheritance    : Base class
// Desctription   : See header file.
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/Camera.h"

#include "geometry/Transform.h"

#include <glu.h>

cmr::Camera::Camera()
: myPosition(geo::Point3D::Origin()),
  myLookDirection(geo::Vector3D::UnitX()),
  myUpDirection(geo::Vector3D::UnitZ())
{
}

cmr::Camera::Camera(
  geo::Point3D Position,
  geo::Vector3D LookDirection,
  geo::Vector3D UpDirection )
: myPosition(Position),
  myLookDirection(LookDirection),
  myUpDirection(UpDirection)
{
  myLookDirection.Normalise();
  myUpDirection.Normalise();
}

const geo::Point3D&
cmr::Camera::Position() const
{
  return myPosition;
}

const geo::Vector3D&
cmr::Camera::LookDirection() const
{
  return myLookDirection;
}

const geo::Vector3D&
cmr::Camera::UpDirection() const
{
  return myUpDirection;
}

void
cmr::Camera::SetCamera() const
{
  gluLookAt(
    myPosition.X(), myPosition.Y(), myPosition.Z(),
    myPosition.X() + myLookDirection.X(), myPosition.Y() + myLookDirection.Y(), myPosition.Z() + myLookDirection.Z(),
    myUpDirection.X(), myUpDirection.Y(), myUpDirection.Z() );
}

void
cmr::Camera::Translate(const geo::Vector3D& Vector)
{
  myPosition += Vector;
}

void
cmr::Camera::Forward(double Distance)
{
  myPosition += myLookDirection * Distance;
}

void
cmr::Camera::Backward(double Distance)
{
  myPosition -= myLookDirection * Distance;
}

void
cmr::Camera::StrafeLeft(double Distance)
{
  myPosition -= (myLookDirection*myUpDirection) * Distance;
}

void
cmr::Camera::StrafeRight(double Distance)
{
  myPosition += (myLookDirection*myUpDirection) * Distance;
}

void
cmr::Camera::StrafeUp(double Distance)
{
  myPosition += myUpDirection * Distance;
}

void
cmr::Camera::StrafeDown(double Distance)
{
  myPosition -= myUpDirection * Distance;
}

void
cmr::Camera::RotateX(double Degrees)
{
  const geo::Transform transform = geo::Transform::RotateX(Degrees);
  myLookDirection = transform ^ myLookDirection;
  myUpDirection = transform ^ myUpDirection;
}

void
cmr::Camera::RotateY(double Degrees)
{
  const geo::Transform transform = geo::Transform::RotateY(Degrees);
  myLookDirection = transform ^ myLookDirection;
  myUpDirection = transform ^ myUpDirection;
}

void
cmr::Camera::RotateZ(double Degrees)
{
  const geo::Transform transform = geo::Transform::RotateZ(Degrees);
  myLookDirection = transform ^ myLookDirection;
  myUpDirection = transform ^ myUpDirection;
}

void
cmr::Camera::RotatePitch(double Degrees)
{
  const geo::Transform rotate = 
    geo::Transform::Rotate(myPosition, myLookDirection*myUpDirection, Degrees);
  myLookDirection = rotate ^ myLookDirection;
  myUpDirection = rotate ^ myUpDirection;
}

void
cmr::Camera::RotateRoll(double Degrees)
{
  const geo::Transform rotate = 
    geo::Transform::Rotate(myPosition, myLookDirection, Degrees);
  // Rotate the up vector (look at will not change as the rotation is about that axis)
  myUpDirection = rotate ^ myUpDirection;
}

void 
cmr::Camera::RotateYaw(double Degrees)
{
  const geo::Transform rotate = 
    geo::Transform::Rotate(myPosition, myUpDirection, Degrees);
  // Rotate the look vector (up at will not change as the rotation is about that axis)
  myLookDirection = rotate ^ myLookDirection;
}
