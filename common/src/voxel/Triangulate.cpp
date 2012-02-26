///////////////////////////////////////////////////////////////////////////////
//
// Name           : Triangulate
// Inheritance    : None
// Desctription   : CUBE triangulation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Triangulate.h"

#include "voxel/vxl.H"

#include <iostream>

namespace local
{
  class C_Classification;
  class C_PointStatus;

  void GenerateLookupTable();
  
  unsigned short FindClassification(const C_PointStatus& Status);
  
  class C_PointStatus
  {
  public:
    C_PointStatus(unsigned char Status);
    C_PointStatus(const C_PointStatus& PointStatus);
  
    unsigned char PointCount() const;
  
    bool operator[](unsigned char index) const;
  
    // Spin the point status about the principle axes.
    void RotateX();
    void RotateY();
    void RotateZ();
  
    void Invert();
  
  private:
    unsigned char myStatus;
  };
  
  unsigned short lookup[256];
  
  const unsigned short CUBE0 = 1 << 0;
  const unsigned short CUBE1 = 1 << 1;
  const unsigned short CUBE2 = 1 << 2;
  const unsigned short CUBE3 = 1 << 3;
  const unsigned short CUBE4 = 1 << 4;
  const unsigned short CUBE5 = 1 << 5;
  const unsigned short CUBE6 = 1 << 6;
  const unsigned short CUBE7 = 1 << 7;
}

void local::GenerateLookupTable()
{
  static bool isGenerated = false;
  if (isGenerated) return;
  
  // Generate lookup table
  unsigned short bitPattern = 0;
  while (bitPattern < 256)
  {
    lookup[bitPattern] = FindClassification(C_PointStatus(bitPattern));
  
    std::cout << bitPattern << " " << lookup[bitPattern] << std::endl;
  
    ++bitPattern;
  }
  
  
  isGenerated = true;
}

unsigned short local::FindClassification(const C_PointStatus& PointStatus)
{
  const unsigned char pointCount = PointStatus.PointCount();
  
  // Here is a summary of the possible classifications:
  // Case 0:
  //   All points "0" (no triangulation through this cube.
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---0
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  0-----------0
  //
  // Case 1:
  //   One point "1" all others "0"
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---0
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------0
  //
  // Case 2:
  //   Two points "1" all others "0", points adjacent along edge
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---0
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------1
  //
  // Case 3:
  //   Two points "1" all others "0", points adjacent across plane
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------1   |
  //  |   0-------|---0
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------0
  //
  // Case 4:
  //   Two points "1" all others "0", points adjacent across diagonal of cube
  //
  //      0-----------1
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---0
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------0
  //
  // Case 5:
  //   Three points "1" all others "0", points all share a common face of cube
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------1
  //
  // Case 6:
  //   Three points "1" all others "0", two points share an edge, other one is diagonaly opposite on a face to one of the points
  //
  //      0-----------1
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---0
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------1
  //
  // Case 7:
  //   Three points "1" all others "0", each point diagonally opposite on a face of the cube to another
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------1   |
  //  |   0-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------0
  //
  // Case 8:
  //   Four points "1" all others "0", all four points on single cube face.
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   1-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------1
  //
  // Case 9:
  //   Four points "1" all others "0", three points share face, other diagonally oposite the "corner one"
  //
  //      1-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------1
  //
  // Case 10:
  //   Four points "1" all others "0", All points diagonally opposite along faces to eachother.
  //
  //      1-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------1   |
  //  |   0-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------0
  //
  // Case 11:
  //   Four points "1" all others "0", All points points adjacent along edge to eachother with one in the centre
  //
  //      0-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------1   |
  //  |   0-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------1
  //
  // Case 12:
  //   Four points "1" all others "0", All points points adjacent along edge to eachother making a line
  //
  //      0-----------1
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   1-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------0
  //
  // Case 13:
  //   Four points "1" all others "0", All points points adjacent along edge to eachother making a line (mirror image of 12)
  //
  //      1-----------0
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   1-------|---1
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  0-----------1
  //
  // Case 14:
  //   Four points "1" all others "0", Pairs of points adjacent along edge, edges diagonally across cube to eachother
  //
  //      1-----------1
  //     /|          /|
  //    / |         / |
  //   /  |        /  |
  //  0-----------0   |
  //  |   0-------|---0
  //  |  /        |  /
  //  | /         | /
  //  |/          |/
  //  1-----------1
  //
  // For higher numbers of "1"s the inverted case can be seen
    
  switch (pointCount > 4 ? 8 - pointCount : pointCount)
  {
  case 0:
    assert(pointCount == 0 || pointCount == 8);
    
    // Case 0
    return 0;
    
  case 1:
    assert(pointCount == 1 || pointCount == 7);
  
    // Case 1
    return 1;
    
  case 2:
  {
    assert(pointCount == 2 || pointCount == 6);
  
    // Case 2, 3 or 4
    C_PointStatus pointStatus(PointStatus);
    
    if (pointCount > 4) pointStatus.Invert();
    
    for (unsigned short i = 0; i < 6; ++i)
    {
      for (unsigned short j = 0; j < 4; ++j)
      {
        if (pointStatus[0] && pointStatus[1])
        {
          return 2;
        }
        else if (pointStatus[0] && pointStatus[5])
        {
          return 3;
        }
        else if (pointStatus[0] && pointStatus[6])
        {
          return 4;
        }
        
        pointStatus.RotateZ();
      }
      
      if (i == 4)
      {
        pointStatus.RotateY();
        pointStatus.RotateY();
      }
      else if (i == 3)
      {
        pointStatus.RotateZ();
        pointStatus.RotateY();
      }
      else
      {
        pointStatus.RotateY();
      }
    }
    
    assert(false); // Should not be possible to get here.
    return 0;
  }
  case 3:
  {
    assert(pointCount == 3 || pointCount == 5);
    
    // Case 5, 6 or 7
    C_PointStatus pointStatus(PointStatus);

    if (pointCount > 4) pointStatus.Invert();
    
    for (unsigned short i = 0; i < 6; ++i)
    {
      for (unsigned short j = 0; j < 4; ++j)
      {
        if (pointStatus[0] && pointStatus[1] && pointStatus[2])
        {
          return 5;
        }
        else if (pointStatus[0] && pointStatus[1] && pointStatus[6])
        {
          return 6;
        }
        else if (pointStatus[0] && pointStatus[2] && pointStatus[5])
        {
          return 7;
        }
        
        pointStatus.RotateZ();
      }
      
      if (i == 4)
      {
        pointStatus.RotateY();
        pointStatus.RotateY();
      }
      else if (i == 3)
      {
        pointStatus.RotateZ();
        pointStatus.RotateY();
      }
      else
      {
        pointStatus.RotateY();
      }
    }
    
    assert(false); // Should not be possible to get here.
    return 0;
  }
  case 4:
  {
    assert(pointCount == 4);
    
    // Case 8, 9, 10, 11, 12, 13 or 14
    C_PointStatus pointStatus(PointStatus);
    
    for (unsigned short i = 0; i < 6; ++i)
    {
      for (unsigned short j = 0; j < 4; ++j)
      {
        if (pointStatus[0] && pointStatus[1] && pointStatus[2] && pointStatus[3])
        {
          return 8;
        }
        else if (pointStatus[0] && pointStatus[1] && pointStatus[2] && pointStatus[7])
        {
          return 9;
        }
        else if (pointStatus[0] && pointStatus[2] && pointStatus[5] && pointStatus[7])
        {
          return 10;
        }
        else if (pointStatus[0] && pointStatus[1] && pointStatus[2] && pointStatus[5])
        {
          return 11;
        }
        else if (pointStatus[0] && pointStatus[2] && pointStatus[3] && pointStatus[6])
        {
          return 12;
        }
        else if (pointStatus[1] && pointStatus[2] && pointStatus[3] && pointStatus[7])
        {
          return 13;
        }
        else if (pointStatus[0] && pointStatus[1] && pointStatus[6] && pointStatus[7])
        {
          return 14;
        }
        
        pointStatus.RotateZ();
      }
      
      if (i == 4)
      {
        pointStatus.RotateY();
        pointStatus.RotateY();
      }
      else if (i == 3)
      {
        pointStatus.RotateZ();
        pointStatus.RotateY();
      }
      else
      {
        pointStatus.RotateY();
      }
    }
    
    assert(false); // Should not be possible to get here.
    return 0;
  }
  default:
    assert(false); // Should not be possible to get here.
  }

  assert(false); // Should not be possible to get here.
  return 0;
}

local::C_PointStatus::C_PointStatus(unsigned char Status)
: myStatus(Status)
{
}

local::C_PointStatus::C_PointStatus(const C_PointStatus& PointStatus)
: myStatus(PointStatus.myStatus)
{
}

unsigned char local::C_PointStatus::PointCount() const
{
  unsigned char pointCount = 0;
  unsigned char status = myStatus;
  while (status > 0)
  {
    if (status & 1) ++pointCount;
    status = status >> 1;
  }
  return pointCount;
}

bool local::C_PointStatus::operator[](unsigned char index) const
{
  return (1 << index) & myStatus;
}

void local::C_PointStatus::RotateX()
{
  unsigned char status = 0;
  
  if (myStatus & CUBE0) status |= CUBE3;
  if (myStatus & CUBE1) status |= CUBE2;
  if (myStatus & CUBE2) status |= CUBE6;
  if (myStatus & CUBE3) status |= CUBE7;
  if (myStatus & CUBE4) status |= CUBE0;
  if (myStatus & CUBE5) status |= CUBE1;
  if (myStatus & CUBE6) status |= CUBE5;
  if (myStatus & CUBE7) status |= CUBE4;
  
  myStatus = status;
}

void local::C_PointStatus::RotateY()
{
  unsigned char status = 0;
  
  if (myStatus & CUBE0) status |= CUBE4;
  if (myStatus & CUBE1) status |= CUBE0;
  if (myStatus & CUBE2) status |= CUBE3;
  if (myStatus & CUBE3) status |= CUBE7;
  if (myStatus & CUBE4) status |= CUBE5;
  if (myStatus & CUBE5) status |= CUBE1;
  if (myStatus & CUBE6) status |= CUBE2;
  if (myStatus & CUBE7) status |= CUBE6;
  
  myStatus = status;
}

void local::C_PointStatus::RotateZ()
{
  unsigned char status = 0;
  
  if (myStatus & CUBE0) status |= CUBE1;
  if (myStatus & CUBE1) status |= CUBE2;
  if (myStatus & CUBE2) status |= CUBE3;
  if (myStatus & CUBE3) status |= CUBE0;
  if (myStatus & CUBE4) status |= CUBE5;
  if (myStatus & CUBE5) status |= CUBE6;
  if (myStatus & CUBE6) status |= CUBE7;
  if (myStatus & CUBE7) status |= CUBE4;
  
  myStatus = status;
}

void local::C_PointStatus::Invert()
{
  unsigned char status = 0;

  if (!(myStatus & CUBE0)) status |= CUBE0;
  if (!(myStatus & CUBE1)) status |= CUBE1;
  if (!(myStatus & CUBE2)) status |= CUBE2;
  if (!(myStatus & CUBE3)) status |= CUBE3;
  if (!(myStatus & CUBE4)) status |= CUBE4;
  if (!(myStatus & CUBE5)) status |= CUBE5;
  if (!(myStatus & CUBE6)) status |= CUBE6;
  if (!(myStatus & CUBE7)) status |= CUBE7;
  
  myStatus = status;
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

  // HACK - testing lookup table
  local::GenerateLookupTable();
  
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
        if (v0.Type() == vxl::Type::SKY) classification |= local::CUBE0;
        if (v1.Type() == vxl::Type::SKY) classification |= local::CUBE1;
        if (v2.Type() == vxl::Type::SKY) classification |= local::CUBE2;
        if (v3.Type() == vxl::Type::SKY) classification |= local::CUBE3;
        if (v4.Type() == vxl::Type::SKY) classification |= local::CUBE4;
        if (v5.Type() == vxl::Type::SKY) classification |= local::CUBE5;
        if (v6.Type() == vxl::Type::SKY) classification |= local::CUBE6;
        if (v7.Type() == vxl::Type::SKY) classification |= local::CUBE7;
        
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