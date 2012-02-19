#ifndef __VXL_SUB_BLOCK_H
#define __VXL_SUB_BLOCK_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : SubBlock
// Inheritance    : Base class
// Desctription   : NxNxN Voxel storage.
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Dll.h"
#include "voxel/Voxel.h"

namespace vxl
{
  template <unsigned short N>
  class Dll_vxl SubBlock
  {
  public:
  
    SubBlock();
    
    // Indexing
    Voxel& operator() (int X, int Y, int Z);
    const Voxel& operator() (int X, int Y, int Z) const;
    
  private:
  
    Voxel myVoxels[N][N][N];
  };
}

#endif
