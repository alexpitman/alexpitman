#ifndef __VXL_VOXEL_H
#define __VXL_VOXEL_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Voxel
// Inheritance    : Base class
// Desctription   : Voxel storage - stores properties about voxels (not position).
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Dll.H"

namespace vxl
{
  struct Dll_vxl Voxel
  {
  public:
  
    Voxel();
    Voxel(unsigned short Type, float Weight);
  
    unsigned short Type() const;
    float Weight() const;
  
  private:
    unsigned short myType;
    float myWeight;
  };
}

#endif
