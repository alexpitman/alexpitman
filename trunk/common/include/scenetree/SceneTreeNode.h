#ifndef __ST_SCENE_TREE_NODE_H
#define __ST_SCENE_TREE_NODE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneTreeNode
// Inheritance    : Node
// Desctription   : The head of the scene tree used for rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Node.h"

#include "renderer/IRenderer.h"

namespace st
{
  class SceneTreeNode;
  
  typedef boost::shared_ptr<SceneTreeNode> T_SceneTreePtr;

  class SceneTreeNode : Node
  {
  public:
    SceneTreeNode(ree::T_RendererPtr RendererPtr);

    void Render();
    
    void Rebuild();
    
  protected:
  
    inline ree::T_RendererPtr Renderer() const { return myRendererPtr; }
    
  private:

    ree::T_RendererPtr myRendererPtr;

    friend Node;
    
  };
}

#endif
