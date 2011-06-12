#ifndef __OBJ_POINT_SET_H
#define __OBJ_POINT_SET_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : PointSet
// Inheritance    : Object
// Description    : Cloud of points
//
///////////////////////////////////////////////////////////////////////////////

#include "object/Object.H"

#include "geometry/Point.H"

#include <vector>

namespace obj
{
	class PointSet;

	typedef boost::shared_ptr<PointSet> T_PointSetPtr;

	class Dll_obj PointSet : public Object
	{
	public:
	
		PointSet();
		
		PointSet(
			const geo::Point3D* PointsBegin,
		  const geo::Point3D* PointsEnd );
	
		// Const accessors
		std::vector<geo::Point3D>::const_iterator PointsBegin() const;
		std::vector<geo::Point3D>::const_iterator PointsEnd() const;
		
	private:
	
		std::vector<geo::Point3D> myPoints;
		
	};
}

#endif