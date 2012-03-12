///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetwork
// Inheritance    : Object
// Desctription   : See header
//
///////////////////////////////////////////////////////////////////////////////
#include "object/FacetNetwork.h"

#include <set>

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
  myNormals()
{
  CalculatePerPointNormals();
}

obj::FacetNetwork::FacetNetwork(
  std::vector<geo::Point3D>::const_iterator PointsBegin,
  std::vector<geo::Point3D>::const_iterator PointsEnd,
  std::vector<tpo::Triple>::const_iterator FacetsBegin,
  std::vector<tpo::Triple>::const_iterator FacetsEnd )
: myPoints(PointsBegin, PointsEnd),
  myFacets(FacetsBegin, FacetsEnd),
  myNormals()
{
  CalculatePerPointNormals();
}

obj::FacetNetwork::FacetNetwork(
  std::vector<geo::Point3D>::const_iterator PointsBegin,
  std::vector<geo::Point3D>::const_iterator PointsEnd,
  std::vector<tpo::Triple>::const_iterator FacetsBegin,
  std::vector<tpo::Triple>::const_iterator FacetsEnd,
  std::vector<geo::Vector3D>::const_iterator NormalsBegin,
  std::vector<geo::Vector3D>::const_iterator NormalsEnd )
: myPoints(PointsBegin, PointsEnd),
  myFacets(FacetsBegin, FacetsEnd),
  myNormals(NormalsBegin, NormalsEnd)
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

void obj::FacetNetwork::CalculatePerPointNormals()
{
  std::vector<std::set<unsigned int>> pointIndexToFacetIndices(myPoints.size());
  
  std::vector<geo::Vector3D> facetNormals(myPoints.size());
  
  for (unsigned int i = 0; i < myFacets.size(); ++i)
  {
    const tpo::Triple& facet = myFacets[i];
  
    pointIndexToFacetIndices[facet[0]].insert(i);
    pointIndexToFacetIndices[facet[1]].insert(i);
    pointIndexToFacetIndices[facet[2]].insert(i);
    
    const geo::Point3D& p0 = myPoints[facet[0]];
    const geo::Point3D& p1 = myPoints[facet[1]];
    const geo::Point3D& p2 = myPoints[facet[2]];
    facetNormals[i] = (p1-p0) * (p2-p0);
    facetNormals[i].Normalise();
  }
  
  myNormals.reserve(myPoints.size());
  
  for (unsigned int i = 0; i < myPoints.size(); ++i)
  {
    geo::Vector3D normal = geo::Vector3D::Zero();
    
    auto u = pointIndexToFacetIndices[i].begin();
    auto v = pointIndexToFacetIndices[i].end();
    while (u != v) normal += facetNormals[*u++];
    
    if (pointIndexToFacetIndices[i].size() != 0) normal.Normalise();
    
    myNormals.push_back(normal);
  }
}
