///////////////////////////////////////////////////////////////////////////////
//
// Name           : Triangulate
// Inheritance    : None
// Desctription   : CUBE triangulation
//
///////////////////////////////////////////////////////////////////////////////

#include "voxel/Triangulate.h"

#include "voxel/vxl.H"

#include "geometry/geo.H"

#include "numeric/num.H"

#include <iostream>
#include <set>
#include <map>

namespace local
{
  typedef std::map<tpo::T_Index, tpo::T_Index> T_IndexMap;
  typedef std::map<tpo::T_Index, T_IndexMap> T_DoubleIndexMap;
  typedef std::map<tpo::T_Index, T_DoubleIndexMap> T_TripleIndexMap;

  class C_Triangulation;
  class C_PointStatus;

  const C_Triangulation& LookupTriangulation(unsigned short PointStatus);
  
  void GenerateLookupTable();
  
  unsigned short FindClassification(C_PointStatus& PointStatus);
  
  C_Triangulation GenerateTriangulation(const C_PointStatus& PointStatus, unsigned short ClassificationNumber, bool print);
  
  void CorrectFacets(const C_PointStatus& PointStatus, std::vector<tpo::Triple>& Facets, bool print);
  
  unsigned short RotateEdgeX(unsigned short Index);
  unsigned short RotateEdgeY(unsigned short Index);
  unsigned short RotateEdgeZ(unsigned short Index);
  
  tpo::T_Index FindOrInsert(
    const vxl::Voxel& V0,
    const geo::Point3D& P0,
    const vxl::Voxel& V1,
    const geo::Point3D& P1,
    tpo::T_Index X,
    tpo::T_Index Y,
    tpo::T_Index Z,
    T_TripleIndexMap& IndexMap,
    std::vector<geo::Point3D>* Points);
  // Returns the point index.
  
  geo::Point3D Midpoint(const geo::Point3D& P0, const geo::Point3D& P1);
  
  geo::Point3D LinearInterp(const vxl::Voxel& V0, const geo::Point3D& P0,
                            const vxl::Voxel& V1, const geo::Point3D& P1);
  
  class C_PointStatus
  {
  public:
    C_PointStatus(unsigned char Status);
    C_PointStatus(const C_PointStatus& PointStatus);
  
    unsigned char PointCount() const;
  
    bool operator[](unsigned char index) const;
  
    bool IsInverted() const;
    
    std::vector<unsigned char>::const_reverse_iterator RotationsBegin() const;
    std::vector<unsigned char>::const_reverse_iterator RotationsEnd() const;
  
    // Spin the point status about the principle axes.
    void RotateX();
    void RotateY();
    void RotateZ();
  
    void Invert();
  
  private:
    unsigned char myStatus;
    bool isInverted;
    std::vector<unsigned char> myRotations;
  };
  
  class C_Triangulation
  {
  public:
    C_Triangulation();
    C_Triangulation(const std::vector<tpo::Triple>& Facets);
    
    std::vector<tpo::Triple>::const_iterator FacetsBegin() const;
    std::vector<tpo::Triple>::const_iterator FacetsEnd() const;
    
  private:
    std::vector<tpo::Triple> myFacets;
  };
  
  C_Triangulation lookup[256];
  
  const unsigned short CUBE0 = 1 << 0;
  const unsigned short CUBE1 = 1 << 1;
  const unsigned short CUBE2 = 1 << 2;
  const unsigned short CUBE3 = 1 << 3;
  const unsigned short CUBE4 = 1 << 4;
  const unsigned short CUBE5 = 1 << 5;
  const unsigned short CUBE6 = 1 << 6;
  const unsigned short CUBE7 = 1 << 7;
  
  const unsigned short EDGE0 = 1 << 0;
  const unsigned short EDGE1 = 1 << 1;
  const unsigned short EDGE2 = 1 << 2;
  const unsigned short EDGE3 = 1 << 3;
  const unsigned short EDGE4 = 1 << 4;
  const unsigned short EDGE5 = 1 << 5;
  const unsigned short EDGE6 = 1 << 6;
  const unsigned short EDGE7 = 1 << 7;
  const unsigned short EDGE8 = 1 << 8;
  const unsigned short EDGE9 = 1 << 9;
  const unsigned short EDGE10 = 1 << 10;
  const unsigned short EDGE11 = 1 << 11;
}

const local::C_Triangulation&
local::LookupTriangulation(unsigned short PointStatus)
{
  assert(PointStatus < 256);
  
  /*if (PointStatus != 0 && PointStatus != 255)
  {
    std::cout << PointStatus << " " << lookup[PointStatus].FacetsEnd() - lookup[PointStatus].FacetsBegin() << std::endl;
  }*/
  return lookup[PointStatus];
}

void local::GenerateLookupTable()
{
  static bool isGenerated = false;
  if (isGenerated) return;
  
  // Generate lookup table
  unsigned short bitPattern = 0;
  while (bitPattern < 256)
  {
    C_PointStatus pointStatus(bitPattern);
  
    unsigned short classificationNumber = FindClassification(pointStatus);
  
    //std::cout << bitPattern << " " << classificationNumber << std::endl;
  
    lookup[bitPattern] = GenerateTriangulation(pointStatus, classificationNumber, false);
  
    ++bitPattern;
  }
  
  isGenerated = true;
}

unsigned short local::FindClassification(C_PointStatus& PointStatus)
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
  {
    assert(pointCount == 0 || pointCount == 8);
    
    // Case 0
    return 0;
  }
  case 1:
  {
    assert(pointCount == 1 || pointCount == 7);
  
    // Case 1 - we still need to figure out the rotation.
    if (pointCount > 4) PointStatus.Invert();
    
    for (unsigned short i = 0; i < 6; ++i)
    {
      for (unsigned short j = 0; j < 4; ++j)
      {
        if (PointStatus[0])
        {
          return 1;
        }
        
        PointStatus.RotateZ();
      }
      
      if (i == 4)
      {
        PointStatus.RotateY();
        PointStatus.RotateY();
      }
      else if (i == 3)
      {
        PointStatus.RotateZ();
        PointStatus.RotateY();
      }
      else
      {
        PointStatus.RotateY();
      }
    }
    
    assert(false); // Should not be possible to get here.
    return 0;
  }
  case 2:
  {
    assert(pointCount == 2 || pointCount == 6);
  
    // Case 2, 3 or 4
    if (pointCount > 4) PointStatus.Invert();
    
    for (unsigned short i = 0; i < 6; ++i)
    {
      for (unsigned short j = 0; j < 4; ++j)
      {
        if (PointStatus[0] && PointStatus[1])
        {
          return 2;
        }
        else if (PointStatus[0] && PointStatus[5])
        {
          return 3;
        }
        else if (PointStatus[0] && PointStatus[6])
        {
          return 4;
        }
        
        PointStatus.RotateZ();
      }
      
      if (i == 4)
      {
        PointStatus.RotateY();
        PointStatus.RotateY();
      }
      else if (i == 3)
      {
        PointStatus.RotateZ();
        PointStatus.RotateY();
      }
      else
      {
        PointStatus.RotateY();
      }
    }
    
    assert(false); // Should not be possible to get here.
    return 0;
  }
  case 3:
  {
    assert(pointCount == 3 || pointCount == 5);
    
    // Case 5, 6 or 7
    if (pointCount > 4) PointStatus.Invert();
    
    for (unsigned short i = 0; i < 6; ++i)
    {
      for (unsigned short j = 0; j < 4; ++j)
      {
        if (PointStatus[0] && PointStatus[1] && PointStatus[2])
        {
          return 5;
        }
        else if (PointStatus[0] && PointStatus[1] && PointStatus[6])
        {
          return 6;
        }
        else if (PointStatus[0] && PointStatus[2] && PointStatus[5])
        {
          return 7;
        }
        
        PointStatus.RotateZ();
      }
      
      if (i == 4)
      {
        PointStatus.RotateY();
        PointStatus.RotateY();
      }
      else if (i == 3)
      {
        PointStatus.RotateZ();
        PointStatus.RotateY();
      }
      else
      {
        PointStatus.RotateY();
      }
    }
    
    assert(false); // Should not be possible to get here.
    return 0;
  }
  case 4:
  {
    assert(pointCount == 4);
    
    // Case 8, 9, 10, 11, 12, 13 or 14
    for (unsigned short i = 0; i < 6; ++i)
    {
      for (unsigned short j = 0; j < 4; ++j)
      {
        if (PointStatus[0] && PointStatus[1] && PointStatus[2] && PointStatus[3])
        {
          return 8;
        }
        else if (PointStatus[0] && PointStatus[1] && PointStatus[2] && PointStatus[7])
        {
          return 9;
        }
        else if (PointStatus[0] && PointStatus[2] && PointStatus[5] && PointStatus[7])
        {
          return 10;
        }
        else if (PointStatus[0] && PointStatus[1] && PointStatus[2] && PointStatus[5])
        {
          return 11;
        }
        else if (PointStatus[0] && PointStatus[2] && PointStatus[3] && PointStatus[6])
        {
          return 12;
        }
        else if (PointStatus[1] && PointStatus[2] && PointStatus[3] && PointStatus[7])
        {
          return 13;
        }
        else if (PointStatus[0] && PointStatus[1] && PointStatus[6] && PointStatus[7])
        {
          return 14;
        }
        
        PointStatus.RotateZ();
      }
      
      if (i == 4)
      {
        PointStatus.RotateY();
        PointStatus.RotateY();
      }
      else if (i == 3)
      {
        PointStatus.RotateZ();
        PointStatus.RotateY();
      }
      else
      {
        PointStatus.RotateY();
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
: myStatus(Status),
  isInverted(false),
  myRotations()
{
}

local::C_Triangulation
local::GenerateTriangulation(const C_PointStatus& PointStatus, unsigned short ClassificationNumber, bool print)
{
  std::vector<tpo::Triple> facets;

  // Insert the facets as edge indicies.
  switch (ClassificationNumber)
  {
  case 0:
    return C_Triangulation();
  case 1:
    facets.push_back(tpo::Triple(0, 3, 8));
    break;
  case 2:
    facets.push_back(tpo::Triple(1, 3, 8));
    facets.push_back(tpo::Triple(1, 8, 9));
    break;
  case 3:
    facets.push_back(tpo::Triple(0, 3, 8));
    facets.push_back(tpo::Triple(4, 5, 9));
    break;
  case 4:
    facets.push_back(tpo::Triple(0, 3, 8));
    facets.push_back(tpo::Triple(5, 6, 10));
    break;
  case 5:
    facets.push_back(tpo::Triple(2, 3, 8));
    facets.push_back(tpo::Triple(2, 8, 10));
    facets.push_back(tpo::Triple(8, 9, 10));
    break;
  case 6:
    facets.push_back(tpo::Triple(1, 2, 8));
    facets.push_back(tpo::Triple(1, 8, 9));
    facets.push_back(tpo::Triple(5, 6, 10));
    break;
  case 7:
    facets.push_back(tpo::Triple(0, 3, 8));
    facets.push_back(tpo::Triple(2, 1, 10));
    facets.push_back(tpo::Triple(4, 5, 9));
    break;
  case 8:
    facets.push_back(tpo::Triple(8, 9, 10));
    facets.push_back(tpo::Triple(8, 10, 11));
    break;
  case 9:
    facets.push_back(tpo::Triple(2, 3, 8));
    facets.push_back(tpo::Triple(2, 8, 10));
    facets.push_back(tpo::Triple(8, 9, 10));
    facets.push_back(tpo::Triple(6, 7, 11));
    break;
  case 10:
    facets.push_back(tpo::Triple(0, 3, 8));
    facets.push_back(tpo::Triple(4, 5, 9));
    facets.push_back(tpo::Triple(2, 1, 10));
    facets.push_back(tpo::Triple(6, 7, 11));
    break;
  case 11:
    facets.push_back(tpo::Triple(2, 3, 8));
    facets.push_back(tpo::Triple(2, 8, 10));
    facets.push_back(tpo::Triple(8, 4, 10));
    facets.push_back(tpo::Triple(4, 5, 10));
    break;
  case 12:
    facets.push_back(tpo::Triple(0, 1, 8));
    facets.push_back(tpo::Triple(1, 5, 8));
    facets.push_back(tpo::Triple(8, 5, 11));
    facets.push_back(tpo::Triple(5, 6, 11));
    break;
  case 13:
    facets.push_back(tpo::Triple(0, 9, 10));
    facets.push_back(tpo::Triple(0, 10, 6));
    facets.push_back(tpo::Triple(0, 6, 7));
    facets.push_back(tpo::Triple(0, 7, 3));
    break;
  case 14:
    facets.push_back(tpo::Triple(1, 2, 8));
    facets.push_back(tpo::Triple(1, 8, 9));
    facets.push_back(tpo::Triple(5, 10, 11));
    facets.push_back(tpo::Triple(5, 11, 7));
    break;
  default:
    assert(false); // Should not be possible to get here.
  }
  
  // Use the point status rotations to rotate the facets to their correct edges.
  CorrectFacets(PointStatus, facets, print);
  // This also once done undoing the rotations numbers the facets 0 through to N-1 where N is
  // the number of points that will be inserted. The ordering of the point insertion should be
  // the same as the the edge indexing.
  
  return C_Triangulation(facets);
}

void local::CorrectFacets(const C_PointStatus& PointStatus, std::vector<tpo::Triple>& Facets, bool print)
{
  auto ru = PointStatus.RotationsBegin();
  auto rv = PointStatus.RotationsEnd();
  
  while (ru != rv)
  {
    // For of the same rotations in a row is a no-op
    if (rv-ru > 3 && ru[0] == ru[1] && ru[2] == ru[3] && ru[1] == ru[2])
    {
      ru += 4;
      continue;
    }
  
    auto fu = Facets.begin();
    auto fv = Facets.end();
    switch (*ru)
    {
    case 'x':
      while (fu != fv)
      {
        (*fu)[0] = RotateEdgeX((*fu)[0]);
        (*fu)[1] = RotateEdgeX((*fu)[1]);
        (*fu)[2] = RotateEdgeX((*fu)[2]);
        ++fu;
      }
      break;
    case 'y':
      while (fu != fv)
      {
        //if (print) std::cout << "BEFORE Y: " << (*fu)[0] << " " << (*fu)[1] << " " << (*fu)[2] << std::endl;
        (*fu)[0] = RotateEdgeY((*fu)[0]);
        (*fu)[1] = RotateEdgeY((*fu)[1]);
        (*fu)[2] = RotateEdgeY((*fu)[2]);
        //if (print) std::cout << "AFTER Y: " << (*fu)[0] << " " << (*fu)[1] << " " << (*fu)[2] << std::endl;
        ++fu;
      }
      break;
    case 'z':
      while (fu != fv)
      {
        //if (print) std::cout << "BEFORE Z: " << (*fu)[0] << " " << (*fu)[1] << " " << (*fu)[2] << std::endl;
        (*fu)[0] = RotateEdgeZ((*fu)[0]);
        (*fu)[1] = RotateEdgeZ((*fu)[1]);
        (*fu)[2] = RotateEdgeZ((*fu)[2]);
        //if (print) std::cout << "AFTER Z: " << (*fu)[0] << " " << (*fu)[1] << " " << (*fu)[2] << std::endl;
        ++fu;
      }
      break;
    default:
      assert(false); // Should not be possible to get here.
    }
  
    ++ru;
  }
  
  if (PointStatus.IsInverted())
  {
    // Flip the orientation of the facets.
    auto fu = Facets.begin();
    auto fv = Facets.end();
    while (fu != fv)
    {
      unsigned short temp = (*fu)[1];
      (*fu)[1] = (*fu)[2];
      (*fu)[2] = temp;
      ++fu;
    }
  }
  
  // Now change the indicies to be 0 to N with increments of 1.
  {
    std::set<tpo::T_Index> indicies;
    {
      auto fu = Facets.begin();
      auto fv = Facets.end();
      while (fu != fv)
      {
        indicies.insert((*fu)[0]);
        indicies.insert((*fu)[1]);
        indicies.insert((*fu)[2]);
        ++fu;
      }
    }
  
    auto iu = indicies.begin();
    auto iv = indicies.end();
    unsigned short index = 0;
    while (iu != iv)
    {
      auto fu = Facets.begin();
      auto fv = Facets.end();
      while (fu != fv)
      {
        if ((*fu)[0] == *iu) (*fu)[0] = index;
        if ((*fu)[1] == *iu) (*fu)[1] = index;
        if ((*fu)[2] == *iu) (*fu)[2] = index;
        ++fu;
      }
    
      ++index;
      ++iu;
    }
  }
}

unsigned short local::RotateEdgeX(unsigned short Index)
{
  switch (Index)
  {
  case 0: return 4;
  case 1: return 9;
  case 2: return 0;
  case 3: return 8;
  case 4: return 6;
  case 5: return 10;
  case 6: return 2;
  case 7: return 11;
  case 8: return 7;
  case 9: return 5;
  case 10: return 1;
  case 11: return 3;
  }
  
  assert(false); // Should not be possible to get here.
  return 0;
}

unsigned short local::RotateEdgeY(unsigned short Index)
{
  switch (Index)
  {
  case 0: return 9;
  case 1: return 5;
  case 2: return 10;
  case 3: return 1;
  case 4: return 8;
  case 5: return 7;
  case 6: return 11;
  case 7: return 3;
  case 8: return 0;
  case 9: return 4;
  case 10: return 6;
  case 11: return 2;
  }

  assert(false); // Should not be possible to get here.
  return 0;
}

unsigned short local::RotateEdgeZ(unsigned short Index)
{
  switch (Index)
  {
  case 0: return 3;
  case 1: return 0;
  case 2: return 1;
  case 3: return 2;
  case 4: return 7;
  case 5: return 4;
  case 6: return 5;
  case 7: return 6;
  case 8: return 11;
  case 9: return 8;
  case 10: return 9;
  case 11: return 10;
  }

  assert(false); // Should not be possible to get here.
  return 0;
}

tpo::T_Index local::FindOrInsert(
  const vxl::Voxel& V0,
  const geo::Point3D& P0,
  const vxl::Voxel& V1,
  const geo::Point3D& P1,
  tpo::T_Index X,
  tpo::T_Index Y,
  tpo::T_Index Z,
  T_TripleIndexMap& IndexMap,
  std::vector<geo::Point3D>* Points)
{
  // Check if this point already exists.
  auto tripleIndex = IndexMap.find(X);
  if (tripleIndex != IndexMap.end())
  {
    auto doubleIndex = tripleIndex->second.find(Y);
    if (doubleIndex != tripleIndex->second.end())
    {
      auto index = doubleIndex->second.find(Z);
      if (index != doubleIndex->second.end())
      {
        // Point already exists return it.
        return index->second;
      }
    }
  }
  
  // Otherwise we need to generate a new point.
  tpo::T_Index index = Points->size();
  IndexMap[X][Y][Z] = index;
  Points->push_back(Midpoint(P0, P1));
  return index;
}

geo::Point3D local::Midpoint(const geo::Point3D& P0, const geo::Point3D& P1)
{
  return geo::Centroid(P0, P1);
}

geo::Point3D local::LinearInterp(const vxl::Voxel& V0, const geo::Point3D& P0,
                                 const vxl::Voxel& V1, const geo::Point3D& P1)
{
  geo::Vector3D direction = P1-P0;
  double abs0 = num::Abs(V0.Weight());
  double abs1 = num::Abs(V1.Weight());
  double t = abs0 / (abs0+abs1);
  
  return P0 + direction*t;
}

local::C_PointStatus::C_PointStatus(const C_PointStatus& PointStatus)
: myStatus(PointStatus.myStatus),
  isInverted(PointStatus.isInverted),
  myRotations(PointStatus.myRotations.begin(), PointStatus.myRotations.end())
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

bool local::C_PointStatus::IsInverted() const
{
  return isInverted;
}
    
std::vector<unsigned char>::const_reverse_iterator local::C_PointStatus::RotationsBegin() const
{
  return myRotations.rbegin();
}

std::vector<unsigned char>::const_reverse_iterator local::C_PointStatus::RotationsEnd() const
{
  return myRotations.rend();
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
  myRotations.push_back('x');
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
  myRotations.push_back('y');
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
  myRotations.push_back('z');
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
  isInverted = !isInverted;
}

local::C_Triangulation::C_Triangulation()
: myFacets()
{
}

local::C_Triangulation::C_Triangulation(
  const std::vector<tpo::Triple>& Facets)
: myFacets(Facets.begin(), Facets.end())
{
}

std::vector<tpo::Triple>::const_iterator
local::C_Triangulation::FacetsBegin() const
{
  return myFacets.begin();
}

std::vector<tpo::Triple>::const_iterator
local::C_Triangulation::FacetsEnd() const
{
  return myFacets.end();
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
  // And edges as:
  //      x-----6-----x
  //     /|          /|
  //    7 11        5 10
  //   /  |        /  |
  //  x-----4-----x   |
  //  |   x----2--|---x   Z
  //  8  /        9  /    |  Y 
  //  | 3         | 1     | /
  //  |/          |/      |/____X
  //  x-----0-----x
  //
  // The numbers relate to the following bit field indicies.
  //                _______________
  // Point Status  |7|6|5|4|3|2|1|0|
  //                _________________________
  // Edge Status   |11|10|9|8|7|6|5|4|3|2|1|0|

  // Ensure the lookup table is initialised.
  local::GenerateLookupTable();
  
  // Maps for storing already calculated point indicies.
  local::T_TripleIndexMap xEdgeIndexMap;
  local::T_TripleIndexMap yEdgeIndexMap;
  local::T_TripleIndexMap zEdgeIndexMap;
  
  for (tpo::T_Index x = 0; x < N-1; ++x)
  {
    for (tpo::T_Index y = 0; y < N-1; ++y)
    {
      for (tpo::T_Index z = 0; z < N-1; ++z)
      {
        // We centre position on the origin
        const geo::Point3D p0(int(x) - N/2, int(y) - N/2, int(z) - N/2);
        const geo::Point3D p1(p0.X()+1, p0.Y(),   p0.Z());
        const geo::Point3D p2(p0.X()+1, p0.Y()+1, p0.Z());
        const geo::Point3D p3(p0.X(),   p0.Y()+1, p0.Z());
        const geo::Point3D p4(p0.X(),   p0.Y(),   p0.Z()+1);
        const geo::Point3D p5(p0.X()+1, p0.Y(),   p0.Z()+1);
        const geo::Point3D p6(p0.X()+1, p0.Y()+1, p0.Z()+1);
        const geo::Point3D p7(p0.X(),   p0.Y()+1, p0.Z()+1);
      
        const Voxel& v0 = SubBlock(x,   y,   z);
        const Voxel& v1 = SubBlock(x+1, y,   z);
        const Voxel& v2 = SubBlock(x+1, y+1, z);
        const Voxel& v3 = SubBlock(x,   y+1, z);
        const Voxel& v4 = SubBlock(x,   y,   z+1);
        const Voxel& v5 = SubBlock(x+1, y,   z+1);
        const Voxel& v6 = SubBlock(x+1, y+1, z+1);
        const Voxel& v7 = SubBlock(x,   y+1, z+1);
        
        // Classify the cube.
        unsigned short pointStatus = 0;
        if (v0.Type() != vxl::Type::SKY) pointStatus |= local::CUBE0;
        if (v1.Type() != vxl::Type::SKY) pointStatus |= local::CUBE1;
        if (v2.Type() != vxl::Type::SKY) pointStatus |= local::CUBE2;
        if (v3.Type() != vxl::Type::SKY) pointStatus |= local::CUBE3;
        if (v4.Type() != vxl::Type::SKY) pointStatus |= local::CUBE4;
        if (v5.Type() != vxl::Type::SKY) pointStatus |= local::CUBE5;
        if (v6.Type() != vxl::Type::SKY) pointStatus |= local::CUBE6;
        if (v7.Type() != vxl::Type::SKY) pointStatus |= local::CUBE7;
        // 0 represents outside the surface, 1 represents inside the surface
        
        // Determine the triangulation based on cube classification.
        const local::C_Triangulation& triangulation = local::LookupTriangulation(pointStatus);
        
        const local::C_PointStatus status(pointStatus);
        
        // Calculate and insert points.
        unsigned short edgeStatus = 0;
        if (status[0] != status[1]) edgeStatus |= local::EDGE0;
        if (status[1] != status[2]) edgeStatus |= local::EDGE1;
        if (status[2] != status[3]) edgeStatus |= local::EDGE2;
        if (status[0] != status[3]) edgeStatus |= local::EDGE3;
        if (status[4] != status[5]) edgeStatus |= local::EDGE4;
        if (status[5] != status[6]) edgeStatus |= local::EDGE5;
        if (status[6] != status[7]) edgeStatus |= local::EDGE6;
        if (status[4] != status[7]) edgeStatus |= local::EDGE7;
        if (status[0] != status[4]) edgeStatus |= local::EDGE8;
        if (status[1] != status[5]) edgeStatus |= local::EDGE9;
        if (status[2] != status[6]) edgeStatus |= local::EDGE10;
        if (status[3] != status[7]) edgeStatus |= local::EDGE11;
        
        
        // Interpolate as midpoints - good for debugging
        /*
        if (edgeStatus & local::EDGE0) points.push_back(local::Midpoint(p0, p1));
        if (edgeStatus & local::EDGE1) points.push_back(local::Midpoint(p1, p2));
        if (edgeStatus & local::EDGE2) points.push_back(local::Midpoint(p2, p3));
        if (edgeStatus & local::EDGE3) points.push_back(local::Midpoint(p0, p3));
        if (edgeStatus & local::EDGE4) points.push_back(local::Midpoint(p4, p5));
        if (edgeStatus & local::EDGE5) points.push_back(local::Midpoint(p5, p6));
        if (edgeStatus & local::EDGE6) points.push_back(local::Midpoint(p6, p7));
        if (edgeStatus & local::EDGE7) points.push_back(local::Midpoint(p4, p7));
        if (edgeStatus & local::EDGE8) points.push_back(local::Midpoint(p0, p4));
        if (edgeStatus & local::EDGE9) points.push_back(local::Midpoint(p1, p5));
        if (edgeStatus & local::EDGE10) points.push_back(local::Midpoint(p2, p6));
        if (edgeStatus & local::EDGE11) points.push_back(local::Midpoint(p3, p7));
        */
        
        // Interpolate points based on Voxel weights.
        /*
        if (edgeStatus & local::EDGE0) points.push_back(local::LinearInterp(v0, p0, v1, p1));
        if (edgeStatus & local::EDGE1) points.push_back(local::LinearInterp(v1, p1, v2, p2));
        if (edgeStatus & local::EDGE2) points.push_back(local::LinearInterp(v2, p2, v3, p3));
        if (edgeStatus & local::EDGE3) points.push_back(local::LinearInterp(v0, p0, v3, p3));
        if (edgeStatus & local::EDGE4) points.push_back(local::LinearInterp(v4, p4, v5, p5));
        if (edgeStatus & local::EDGE5) points.push_back(local::LinearInterp(v5, p5, v6, p6));
        if (edgeStatus & local::EDGE6) points.push_back(local::LinearInterp(v6, p6, v7, p7));
        if (edgeStatus & local::EDGE7) points.push_back(local::LinearInterp(v7, p4, v7, p7));
        if (edgeStatus & local::EDGE8) points.push_back(local::LinearInterp(v0, p0, v4, p4));
        if (edgeStatus & local::EDGE9) points.push_back(local::LinearInterp(v1, p1, v5, p5));
        if (edgeStatus & local::EDGE10) points.push_back(local::LinearInterp(v2, p2, v6, p6));
        if (edgeStatus & local::EDGE11) points.push_back(local::LinearInterp(v3, p3, v7, p7));
        */
        
        std::vector<tpo::T_Index> pointIndicies;
        if (edgeStatus & local::EDGE0) pointIndicies.push_back(local::FindOrInsert(v0, p0, v1, p1, x, y, z, xEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE1) pointIndicies.push_back(local::FindOrInsert(v1, p1, v2, p2, x+1, y, z, yEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE2) pointIndicies.push_back(local::FindOrInsert(v2, p2, v3, p3, x, y+1, z, xEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE3) pointIndicies.push_back(local::FindOrInsert(v0, p0, v3, p3, x, y, z, yEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE4) pointIndicies.push_back(local::FindOrInsert(v4, p4, v5, p5, x, y, z+1, xEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE5) pointIndicies.push_back(local::FindOrInsert(v5, p5, v6, p6, x+1, y, z+1, yEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE6) pointIndicies.push_back(local::FindOrInsert(v6, p6, v7, p7, x, y+1, z+1, xEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE7) pointIndicies.push_back(local::FindOrInsert(v7, p4, v7, p7, x, y, z+1, yEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE8) pointIndicies.push_back(local::FindOrInsert(v0, p0, v4, p4, x, y, z, zEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE9) pointIndicies.push_back(local::FindOrInsert(v1, p1, v5, p5, x+1, y, z, zEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE10) pointIndicies.push_back(local::FindOrInsert(v2, p2, v6, p6, x+1, y+1, z, zEdgeIndexMap, &points));
        if (edgeStatus & local::EDGE11) pointIndicies.push_back(local::FindOrInsert(v3, p3, v7, p7, x, y+1, z, zEdgeIndexMap, &points));
        
        // Insert facets.
        auto fu = triangulation.FacetsBegin();
        auto fv = triangulation.FacetsEnd();
        while (fu != fv)
        {
          facets.push_back(tpo::Triple( pointIndicies[(*fu)[0]], pointIndicies[(*fu)[1]], pointIndicies[(*fu)[2]] ));
          ++fu;
        }
      }
    }
  }
  
  return obj::T_FacetNetworkPtr( new obj::FacetNetwork(points.begin(), points.end(), facets.begin(), facets.end()) );
}

// Explicit instantiations
template Dll_vxl obj::T_FacetNetworkPtr vxl::Triangulate::SubBlock(const vxl::SubBlock<10>& SubBlock);
template Dll_vxl obj::T_FacetNetworkPtr vxl::Triangulate::SubBlock(const vxl::SubBlock<256>& SubBlock);