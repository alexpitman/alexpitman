///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneTreeNode
// Inheritance    : Node
// Desctription   : The head of the scene tree used for rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/SceneTreeNode.h"

#include <iostream>

st::SceneTreeNode::SceneTreeNode(ree::T_RendererPtr RendererPtr)
: myRendererPtr(RendererPtr),
  myNodes()
{
}

void
st::SceneTreeNode::Render() const
{
	auto nu = myNodes.begin();
	auto nv = myNodes.end();
	while ( nu != nv )
	{
		(*nu++)->Render();
	}
}

void
st::SceneTreeNode::Rebuild()
{
}

geo::Extent3D
st::SceneTreeNode::Extent() const
{
  geo::Extent3D extent;
  for (const auto& node : myNodes)
  {
    extent += node->Extent();
  }
  return extent;
}

void
st::SceneTreeNode::AddNode(const st::T_NodePtr& Node)
{
	myNodes.push_back(Node);
}
