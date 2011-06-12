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
	auto fu = myFacetNetwork->FacetsBegin();
	auto fv = myFacetNetwork->FacetsEnd();
	while ( fu != fv )
	{
		const tpo::Triple& facet = *fu++;
	
		Renderer()->Vertex( points[facet[0]] );
		Renderer()->Vertex( points[facet[1]] );
		Renderer()->Vertex( points[facet[2]] );
	}
	
	Renderer()->End();
}
