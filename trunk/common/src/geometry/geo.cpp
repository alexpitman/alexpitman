#include "geometry/geo.h"
///////////////////////////////////////////////////////////////////////////////
//
// Name           : geo namespace
// Inheritance    : None
// Desctription   : See header file
//
///////////////////////////////////////////////////////////////////////////////

geo::Point3D
geo::Centroid(const Point3D& P0, const Point3D& P1)
{
  return geo::Point3D(
    (P0.X() + P1.X())/2.0f,
    (P0.Y() + P1.Y())/2.0f,
    (P0.Z() + P1.Z())/2.0f);
}
