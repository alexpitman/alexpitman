#ifndef __OBJ_FACET_NETWORK_H
#define __OBJ_FACET_NETWORK_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetwork
// Inheritance    : Object
// Description    : Network of (connected) indexed triangles
//
///////////////////////////////////////////////////////////////////////////////

#include "object/Object.H"

#include "topology/Triple.H"

#include "geometry/Point.H"

#include <vector>

namespace obj
{
	class FacetNetwork;

	typedef boost::shared_ptr<FacetNetwork> T_FacetNetworkPtr;

	class Dll_obj FacetNetwork : public Object
	{
	public:
	
		FacetNetwork();
		
		FacetNetwork(
			const geo::Point3D* PointsBegin,
		  const geo::Point3D* PointsEnd,
			const tpo::Triple* FacetsBegin,
			const tpo::Triple* FacetsEnd );
	
		// Const accessors
		std::vector<geo::Point3D>::const_iterator PointsBegin() const;
		std::vector<geo::Point3D>::const_iterator PointsEnd() const;
		
		std::vector<tpo::Triple>::const_iterator FacetsBegin() const;
		std::vector<tpo::Triple>::const_iterator FacetsEnd() const;
		
	private:
	
		std::vector<geo::Point3D> myPoints;
		std::vector<tpo::Triple> myFacets;
		
	};
}

#endif