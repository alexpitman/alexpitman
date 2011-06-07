#ifndef __ST_NODE_H
#define __ST_NODE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Node
// Inheritance    : Base class
// Desctription   : Base class for all scenetree nodes
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Dll.h"

#include "renderer/IRenderer.h"

namespace st
{
  class Node;
  class SceneTreeNode;
  
  typedef boost::shared_ptr<Node> T_NodePtr;
  typedef boost::shared_ptr<SceneTreeNode> T_SceneTreePtr;

  class Dll_st Node
  {
  public:
    Node();
    Node(T_SceneTreePtr SceneTreePtr);

		virtual ~Node() {};
		
    virtual void Render() const;
    
    virtual void Rebuild();

  protected:
  
    ree::T_RendererPtr Renderer() const;
		
		T_SceneTreePtr Root() const;
    
  private:

    T_SceneTreePtr mySceneTreePtr;

  };
}

#endif
