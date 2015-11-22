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

#include "object/FacetNetwork.h"

namespace st
{
	class Dll_st FacetNetworkNode : public Node
	{
	public:
	
		FacetNetworkNode(
			const st::T_SceneTreePtr& Root,
			const obj::T_FacetNetworkPtr& FacetNetwork );
	
    ~FacetNetworkNode();
  
    void Build() const;
  
		void Render() const override;
	
    geo::Extent3D Extent() const override { return myExtent; }
  
	private:
	
		obj::T_FacetNetworkPtr myFacetNetwork;
    
	
    mutable bool isRebuildRequired;
    mutable GLuint myDisplayListId;
    mutable geo::Extent3D myExtent;
	};
}

#endif