#ifndef __ST_POINT_SET_NODE_H
#define __ST_POINT_SET_NODE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetworkNode
// Inheritance    : st::Node
// Description    : Basic triangulation
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Node.h"

#include "object/PointSet.h"

namespace st
{
	class Dll_st PointSetNode : public Node
	{
	public:
	
		PointSetNode(
			const st::T_SceneTreePtr& Root,
			const obj::T_PointSetPtr& PointSet );
	
		void Render() const override;
	
    geo::Extent3D Extent() const override { return myExtent; }
  
	private:
	
		obj::T_PointSetPtr myPointSet;
    geo::Extent3D myExtent;
	};
}

#endif