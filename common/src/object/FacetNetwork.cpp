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
  myFacets(FacetsBegin, FacetsEnd),
	myNormals(),
	myFacetToNormals()
{
}

obj::FacetNetwork::FacetNetwork(
	std::vector<geo::Point3D>::const_iterator PointsBegin,
	std::vector<geo::Point3D>::const_iterator PointsEnd,
	std::vector<tpo::Triple>::const_iterator FacetsBegin,
	std::vector<tpo::Triple>::const_iterator FacetsEnd )
: myPoints(PointsBegin, PointsEnd),
  myFacets(FacetsBegin, FacetsEnd),
	myNormals(),
	myFacetToNormals()
{
}

obj::FacetNetwork::FacetNetwork(
	std::vector<geo::Point3D>::const_iterator PointsBegin,
	std::vector<geo::Point3D>::const_iterator PointsEnd,
	std::vector<tpo::Triple>::const_iterator FacetsBegin,
	std::vector<tpo::Triple>::const_iterator FacetsEnd,
	std::vector<geo::Vector3D>::const_iterator NormalsBegin,
	std::vector<geo::Vector3D>::const_iterator NormalsEnd,
	std::vector<tpo::Triple>::const_iterator FacetToNormalsBegin,
	std::vector<tpo::Triple>::const_iterator FacetToNormalsEnd )
: myPoints(PointsBegin, PointsEnd),
  myFacets(FacetsBegin, FacetsEnd),
	myNormals(NormalsBegin, NormalsEnd),
	myFacetToNormals(FacetToNormalsBegin, FacetToNormalsEnd)
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

std::vector<geo::Vector3D>::const_iterator
obj::FacetNetwork::NormalsBegin() const
{
	return myNormals.cbegin();
}

std::vector<geo::Vector3D>::const_iterator
obj::FacetNetwork::NormalsEnd() const
{
	return myNormals.cend();
}

std::vector<tpo::Triple>::const_iterator
obj::FacetNetwork::FacetToNormalsBegin() const
{
	return myFacetToNormals.cbegin();
}

std::vector<tpo::Triple>::const_iterator
obj::FacetNetwork::FacetToNormalsEnd() const
{
	return myFacetToNormals.cend();
}
