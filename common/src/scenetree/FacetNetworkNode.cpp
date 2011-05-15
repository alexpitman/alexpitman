///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetworkNode
// Inheritance    : st::Node
// Description    : See header file.
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/FacetNetworkNode.h"

st::FacetNetworkNode::FacetNetworkNode(
	const geo::Point3D* PointsBegin,
	const geo::Point3D* PointsEnd,
	const tpo::Triple* FacetsBegin,
	const tpo::Triple* FacetsEnd )
: myPoints( PointsBegin, PointsEnd ),
	myFacets( FacetsBegin, FacetsEnd )
{
}