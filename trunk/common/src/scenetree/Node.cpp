///////////////////////////////////////////////////////////////////////////////
//
// Name           : Node
// Inheritance    : Base class
// Desctription   : Base class for all scenetree nodes
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Node.h"

#include "scenetree/SceneTreeNode.h"

#include <iostream>

st::Node::Node()
{
}

st::Node::Node(const st::T_SceneTreePtr& SceneTreePtr)
: mySceneTreePtr(SceneTreePtr)
{
}

void
st::Node::Render() const
{
	//std::cout << "RENDER ELEMENT" << std::endl;
}

void
st::Node::Rebuild()
{
}

st::T_SceneTreePtr
st::Node::Root() const
{
	return mySceneTreePtr;
}

ree::T_RendererPtr
st::Node::Renderer() const
{
  return mySceneTreePtr->Renderer();
}