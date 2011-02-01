///////////////////////////////////////////////////////////////////////////////
//
// Name           : Node
// Inheritance    : Base class
// Desctription   : Base class for all scenetree nodes
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Node.h"

#include "scenetree/SceneTreeNode.h"

st::Node::Node()
{
}

st::Node::Node(T_SceneTreePtr SceneTreePtr)
: mySceneTreePtr(SceneTreePtr)
{
}

void
st::Node::Render() const
{
}

void
st::Node::Rebuild()
{
}

ree::T_RendererPtr
st::Node::Renderer() const
{
  return mySceneTreePtr->Renderer();
}