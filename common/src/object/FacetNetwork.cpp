///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetwork
// Inheritance    : Object
// Desctription   : See header
//
///////////////////////////////////////////////////////////////////////////////
#include "object/FacetNetwork.h"

obj::FacetNetwork::FacetNetwork()
: myPoints(),
  myFacets()
{
}

obj::FacetNetwork::FacetNetwork(
	const geo::Point3D* PointsBegin,
	const geo::Point3D* PointsEnd,
	const tpo::Triple* FacetsBegin,
	const tpo::Triple* FacetsEnd )
: myPoints(PointsBegin, PointsEnd),
  myFacets(FacetsBegin, FacetsEnd)
{
}

std::vector<geo::Point3D>::const_iterator
obj::FacetNetwork::PointsBegin() const
{
	return myPoints.cbegin();
}

std::vector<geo::Point3D>::const_iterator
obj::FacetNetwork::PointsEnd() const
{
	return myPoints.cend();
}

std::vector<tpo::Triple>::const_iterator
obj::FacetNetwork::FacetsBegin() const
{
	return myFacets.cbegin();
}

std::vector<tpo::Triple>::const_iterator
obj::FacetNetwork::FacetsEnd() const
{
	return myFacets.cend();
}