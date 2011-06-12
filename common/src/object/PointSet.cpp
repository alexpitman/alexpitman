///////////////////////////////////////////////////////////////////////////////
//
// Name           : PointSet
// Inheritance    : Object
// Desctription   : See header
//
///////////////////////////////////////////////////////////////////////////////
#include "object/PointSet.h"

obj::PointSet::PointSet()
: myPoints()
{
}

obj::PointSet::PointSet(
	const geo::Point3D* PointsBegin,
	const geo::Point3D* PointsEnd )
: myPoints(PointsBegin, PointsEnd)
{
}

std::vector<geo::Point3D>::const_iterator
obj::PointSet::PointsBegin() const
{
	return myPoints.cbegin();
}

std::vector<geo::Point3D>::const_iterator
obj::PointSet::PointsEnd() const
{
	return myPoints.cend();
}
