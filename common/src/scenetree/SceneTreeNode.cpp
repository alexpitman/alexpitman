///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneTreeNode
// Inheritance    : Node
// Desctription   : The head of the scene tree used for rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/SceneTreeNode.h"

st::SceneTreeNode::SceneTreeNode(ree::T_RendererPtr RendererPtr)
: myRendererPtr(RendererPtr)
{
}

void
st::SceneTreeNode::Render()
{
}

void
st::SceneTreeNode::Rebuild()
{
}

