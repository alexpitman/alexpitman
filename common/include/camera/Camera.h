#ifndef __CMR_CAMERA_H
#define __CMR_CAMERA_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Camera
// Inheritance    : Base class
// Desctription   : Representation of a basic camera
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Point.h"
#include "geometry/Vector.h"

namespace cmr
{
  class Camera
  {
  public:
    Camera();
  
    Camera( geo::Point3D Position,
            geo::Vector3D LookDirection,
            geo::Vector3D UpDirection );
    
    void SetCamera() const;
  
  private:
  
    geo::Point3D myPosition;
    geo::Vector3D myLookDirection;
    geo::Vector3D myUpDirection;
  
  };
}

#endif
