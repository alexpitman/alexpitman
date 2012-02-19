#ifndef __VXL_OCTREE_H
#define __VXL_OCTREE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Octree
// Inheritance    : Base class
// Desctription   : Voxel storage - stores properties about voxels (not position).
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Dll.H"

namespace vxl
{
  template <typename T>
  class Dll_vxl Octree
  {
  public:
  
    Octree(int size);
    ~Octree();
    
    // Indexing
    T& operator() (int X, int Y, int Z);
    const T& operator() (int X, int Y, int Z) const;
    
  private:
  
    // TODO
  
  };
}

#endif
