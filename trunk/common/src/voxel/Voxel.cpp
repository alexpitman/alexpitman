///////////////////////////////////////////////////////////////////////////////
//
// Name           : Voxel
// Inheritance    : Base class
// Desctription   : Voxel storage - stores properties about voxels (not position).
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Voxel.H"

vxl::Voxel::Voxel()
: myType(0),
  myWeight(0.0f)
{
}

vxl::Voxel::Voxel(unsigned short Type, float Weight)
: myType(Type),
  myWeight(Weight)
{
}
  
unsigned short vxl::Voxel::Type() const
{
  return myType;
}

float vxl::Voxel::Weight() const
{
  return myWeight;
}
