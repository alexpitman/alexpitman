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
  myFacetNetwork(FacetNetwork),
  isRebuildRequired(true),
  myDisplayListId(0)
{
}

st::FacetNetworkNode::~FacetNetworkNode()
{
  if (myDisplayListId) Renderer()->DeleteList(myDisplayListId);
}

void
st::FacetNetworkNode::Build() const
{
  isRebuildRequired = false;

  myExtent = geo::Extent3D();
  for (auto pu = myFacetNetwork->PointsBegin(),
         pv = myFacetNetwork->PointsEnd(); pu != pv; ++pu)
  {
    myExtent += *pu;
  }

  if (myDisplayListId) Renderer()->DeleteList(myDisplayListId);
  
  myDisplayListId = Renderer()->BeginList();

  Renderer()->Begin( ree::TRIANGLES );
  
  auto points = myFacetNetwork->PointsBegin();
  auto normals = myFacetNetwork->NormalsBegin();
  
  auto fu = myFacetNetwork->FacetsBegin();
  auto fv = myFacetNetwork->FacetsEnd();
  
  auto fcu = myFacetNetwork->FacetColoursBegin();
  bool isFacetColoured = fcu != myFacetNetwork->FacetColoursEnd();
  
  // Use specifed per-point normals
  while ( fu != fv )
  {
    const tpo::Triple& facet = *fu++;
    
    if (isFacetColoured) Renderer()->SetColour( *fcu++ );
    
    if (!isFacetColoured) Renderer()->SetColour( normals[facet[0]] );
    Renderer()->Normal( normals[facet[0]] );
    Renderer()->Vertex( points[facet[0]] );
    if (!isFacetColoured) Renderer()->SetColour( normals[facet[1]] );
    Renderer()->Normal( normals[facet[1]] );
    Renderer()->Vertex( points[facet[1]] );
    if (!isFacetColoured) Renderer()->SetColour( normals[facet[2]] );
    Renderer()->Normal( normals[facet[2]] );
    Renderer()->Vertex( points[facet[2]] );
  }
  
  Renderer()->End();
  /*
  // Render normals.
  Renderer()->Begin( ree::LINES );
  
  Renderer()->SetColour( att::Colour(1, 0, 0) );
  
  auto pu = myFacetNetwork->PointsBegin();
  auto pv = myFacetNetwork->PointsEnd();
  auto nu = myFacetNetwork->NormalsBegin();
  while (pu != pv)
  {
    //std::cout << pu->X() << " " << pu->Y() << " " << pu->Z() << std::endl;
    Renderer()->Vertex( *pu );
    Renderer()->Vertex( *pu++ + *nu++ );
  }
  
  
  Renderer()->End();
  */
  Renderer()->EndList();
}

void
st::FacetNetworkNode::Render() const
{
  if (isRebuildRequired) Build();

  Renderer()->CallList(myDisplayListId);
}
