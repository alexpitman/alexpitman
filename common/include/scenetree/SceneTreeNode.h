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

#include <memory>
#include <vector>

namespace st
{
  class SceneTreeNode;
  
  typedef std::shared_ptr<SceneTreeNode> T_SceneTreePtr;

  class Dll_st SceneTreeNode : public Node
  {
  public:
	
    SceneTreeNode(ree::T_RendererPtr RendererPtr);
		
    void Render() const override;
    
    void Rebuild() override;
    
    geo::Extent3D Extent() const override;
    
		void AddNode(const st::T_NodePtr& Node);
  
		// Get a pointer to the renderer.
    inline ree::T_RendererPtr Renderer() const { return myRendererPtr; }
		
  private:
	
    ree::T_RendererPtr myRendererPtr;

		std::vector<st::T_NodePtr> myNodes;

    friend Node;
    
  };
}

#endif
