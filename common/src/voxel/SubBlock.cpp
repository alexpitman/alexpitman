///////////////////////////////////////////////////////////////////////////////
//
// Name           : SubBlock
// Inheritance    : Base class
// Desctription   : NxNxN Voxel storage.
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/SubBlock.h"

template <unsigned short N>
vxl::SubBlock<N>::SubBlock(const geo::Vector3D& Offset)
: myOffset(Offset)
{
}

template <unsigned short N>
const geo::Vector3D&
vxl::SubBlock<N>::Offset() const
{
  return myOffset;
}

template <unsigned short N>
vxl::Voxel& vxl::SubBlock<N>::operator() (int X, int Y, int Z)
{
  return myVoxels[X][Y][Z];
}

template <unsigned short N>
const vxl::Voxel& vxl::SubBlock<N>::operator() (int X, int Y, int Z) const
{
  return myVoxels[X][Y][Z];
}

// Explicit instantiations
template class vxl::SubBlock<10>;
template class vxl::SubBlock<64>;
template class vxl::SubBlock<256>;
