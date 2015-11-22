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

#include "geometry/Extent.h"

#include <memory>

namespace st
{
  class Node;
  class SceneTreeNode;
  
  typedef std::shared_ptr<Node> T_NodePtr;
  typedef std::shared_ptr<SceneTreeNode> T_SceneTreePtr;

  class Dll_st Node
  {
  public:
	
		Node();
    Node(const st::T_SceneTreePtr& SceneTreePtr);

		virtual ~Node() {};
		
    virtual void Render() const;
    
    virtual void Rebuild();

    virtual geo::Extent3D Extent() const = 0;
    
  protected:
	
    ree::T_RendererPtr Renderer() const;
		
		T_SceneTreePtr Root() const;
    
  private:

    T_SceneTreePtr mySceneTreePtr;

  };
}

#endif
