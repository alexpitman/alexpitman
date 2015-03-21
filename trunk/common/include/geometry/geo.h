#ifndef __GEO_H
#define __GEO_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : geo namespace
// Inheritance    : None
// Desctription   : Geometry namespace defines/functions
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Dll.h"
#include "geometry/Point.h"

namespace geo
{
  Dll_geo Point3D Centroid(const Point3D& P0, const Point3D& P1);
}

#endif