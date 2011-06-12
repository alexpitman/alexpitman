///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetworkNode
// Inheritance    : st::Node
// Description    : See header file.
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/PointSetNode.h"

#include "attribute/Colour.h"

#include <iostream>

st::PointSetNode::PointSetNode(
	const st::T_SceneTreePtr& Root,
	const obj::T_PointSetPtr& PointSet )
: st::Node(Root),
  myPointSet(PointSet)
{
}

void
st::PointSetNode::Render() const
{
	Renderer()->Begin( ree::POINTS );
	
	Renderer()->SetColour( att::Colour(1, 0, 0) );
	
	auto pu = myPointSet->PointsBegin();
	auto pv = myPointSet->PointsEnd();
	while ( pu != pv )
	{
		Renderer()->Vertex( *pu++ );
	}
	
	Renderer()->End();
}
