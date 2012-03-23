///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetworkNode
// Inheritance    : st::Node
// Description    : See header file.
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/FacetNetworkNode.h"

#include "attribute/Colour.h"

#include <iostream>

st::FacetNetworkNode::FacetNetworkNode(
  const st::T_SceneTreePtr& Root,
  const obj::T_FacetNetworkPtr& FacetNetwork )
: st::Node(Root),
  myFacetNetwork(FacetNetwork)
{
}

void
st::FacetNetworkNode::Render() const
{
  Renderer()->Begin( ree::TRIANGLES );
  
  Renderer()->SetColour( att::Colour(0, 1, 0) );
  
  auto points = myFacetNetwork->PointsBegin();
  auto normals = myFacetNetwork->NormalsBegin();
  
  auto fu = myFacetNetwork->FacetsBegin();
  auto fv = myFacetNetwork->FacetsEnd();
  
  // Use specifed per-point normals
  while ( fu != fv )
  {
    const tpo::Triple& facet = *fu++;
    
    Renderer()->Normal( normals[facet[0]] );
    Renderer()->Vertex( points[facet[0]] );
    Renderer()->Normal( normals[facet[1]] );
    Renderer()->Vertex( points[facet[1]] );
    Renderer()->Normal( normals[facet[2]] );
    Renderer()->Vertex( points[facet[2]] );
  }
  
  Renderer()->End();
  
  Renderer()->Begin( ree::LINES );
  
  Renderer()->SetColour( att::Colour(1, 0, 0) );
  
  
  // Render normals.
  /*
  auto pu = myFacetNetwork->PointsBegin();
  auto pv = myFacetNetwork->PointsEnd();
  auto nu = myFacetNetwork->NormalsBegin();
  while (pu != pv)
  {
    //std::cout << pu->X() << " " << pu->Y() << " " << pu->Z() << std::endl;
    Renderer()->Vertex( *pu );
    Renderer()->Vertex( *pu++ + *nu++ );
  }
  */
  
  Renderer()->End();
}
