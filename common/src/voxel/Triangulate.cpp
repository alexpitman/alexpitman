///////////////////////////////////////////////////////////////////////////////
//
// Name           : Triangulate
// Inheritance    : None
// Desctription   : CUBE triangulation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Triangulate.h"

#include "voxel/vxl.H"

namespace local
{
  void GenerateLookupTable();

  class C_Classification
  {
  };
  
  C_Classification lookup[256];
}

void local::GenerateLookupTable()
{
  static bool isGenerated = false;
  if (isGenerated) return;
  
  // Generate lookup table
  unsigned short classification = 0;
  while (classification != 255)
  {
    
  
    ++classification;
  }
  
  
  isGenerated = true;
}

template <unsigned short N>
obj::T_FacetNetworkPtr vxl::Triangulate::SubBlock(const vxl::SubBlock<N>& SubBlock)
{
  std::vector<geo::Point3D> points;
  std::vector<tpo::Triple> facets;
  
  // We are numbering the neighbouring Voxels as such below:
  //      7-----------6
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  4-----------5   |
  //  |   3-------|---2   Z
  //  |  /        |  /    |  Y 
  //  | /         | /     | /
  //  |/          |/      |/____X
  //  0-----------1
  //
  // The numbers relate to the following bit field indicies.
  const unsigned short CUBE0 = 1 << 0;
  const unsigned short CUBE1 = 1 << 1;
  const unsigned short CUBE2 = 1 << 2;
  const unsigned short CUBE3 = 1 << 3;
  const unsigned short CUBE4 = 1 << 4;
  const unsigned short CUBE5 = 1 << 5;
  const unsigned short CUBE6 = 1 << 6;
  const unsigned short CUBE7 = 1 << 7;
  
  for (unsigned short x = 0; x < N-1; ++x)
  {
    for (unsigned short y = 0; y < N-1; ++y)
    {
      for (unsigned short z = 0; z < N-1; ++z)
      {
        const Voxel& v0 = SubBlock(x,   y,   z);
        const Voxel& v1 = SubBlock(x+1, y,   z);
        const Voxel& v2 = SubBlock(x+1, y+1, z);
        const Voxel& v3 = SubBlock(x,   y+1, z);
        const Voxel& v4 = SubBlock(x,   y,   z+1);
        const Voxel& v5 = SubBlock(x+1, y,   z+1);
        const Voxel& v6 = SubBlock(x+1, y+1, z+1);
        const Voxel& v7 = SubBlock(x,   y+1, z+1);
        
        // Classify the cube.
        unsigned short classification = 0;
        if (v0.Type() == vxl::Type::SKY) classification |= CUBE0;
        if (v1.Type() == vxl::Type::SKY) classification |= CUBE1;
        if (v2.Type() == vxl::Type::SKY) classification |= CUBE2;
        if (v3.Type() == vxl::Type::SKY) classification |= CUBE3;
        if (v4.Type() == vxl::Type::SKY) classification |= CUBE4;
        if (v5.Type() == vxl::Type::SKY) classification |= CUBE5;
        if (v6.Type() == vxl::Type::SKY) classification |= CUBE6;
        if (v7.Type() == vxl::Type::SKY) classification |= CUBE7;
        
        // Determine the triangulation based on cube classification.
        
        
        // Interpolate points based on Voxel weights.
      }
    }
  }
  
  return obj::T_FacetNetworkPtr( new obj::FacetNetwork(points.begin(), points.end(), facets.begin(), facets.end()) );
}

// Explicit instantiations
template Dll_vxl obj::T_FacetNetworkPtr vxl::Triangulate::SubBlock(const vxl::SubBlock<10>& SubBlock);
template Dll_vxl obj::T_FacetNetworkPtr vxl::Triangulate::SubBlock(const vxl::SubBlock<256>& SubBlock);