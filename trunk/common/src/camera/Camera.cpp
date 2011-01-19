///////////////////////////////////////////////////////////////////////////////
//
// Name           : Camera
// Inheritance    : Base class
// Desctription   : See header file.
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/Camera.h"

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
}

void
cmr::Camera::SetCamera() const
{
  gluLookAt(
    myPosition.X(), myPosition.Y(), myPosition.Z(),
    myLookDirection.X(), myLookDirection.Y(), myLookDirection.Z(),
    myUpDirection.X(), myUpDirection.Y(), myUpDirection.Z() );
}
