#ifndef __VXL_TRIANGULATE_H
#define __VXL_TRIANGULATE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Triangulate
// Inheritance    : None
// Desctription   : Voxel triangulation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/SubBlock.h"
#include "voxel/TerrainDescriptor.h"

#include "object/FacetNetwork.h"

namespace vxl
{
  namespace Triangulate
  {
    template <unsigned short N>
    Dll_vxl obj::T_FacetNetworkPtr SubBlock(const vxl::SubBlock<N>& SubBlock);
    
    template <unsigned short N>
    Dll_vxl obj::T_FacetNetworkPtr Terrain(const vxl::TerrainDescriptor& Terrain, const geo::Vector3D& Offset);
  }
}

#endif
