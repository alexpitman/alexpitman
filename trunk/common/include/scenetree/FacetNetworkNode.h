#ifndef __ST_FACET_NETWORK_NODE_H
#define __ST_FACET_NETWORK_NODE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetworkNode
// Inheritance    : st::Node
// Description    : Basic triangulation
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Node.h"

#include "topology/Triple.H"

#include "geometry/Point.H"

#include <vector>

namespace st
{
	class Dll_st FacetNetworkNode : Node
	{
	public:
	
		FacetNetworkNode(
			const geo::Point3D* PointsBegin,
		  const geo::Point3D* PointsEnd,
			const tpo::Triple* FacetsBegin,
			const tpo::Triple* FacetsEnd );
	
	private:
	
		std::vector<geo::Point3D> myPoints;
		std::vector<tpo::Triple> myFacets;
	
	};
}

#endif