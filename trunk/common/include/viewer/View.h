#ifndef __VWR_VIEW_H
#define __VWR_VIEW_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Desctription   : View rendering
//
///////////////////////////////////////////////////////////////////////////////

//#include "scenetree/SceneTreeNode.h"

#include "viewer/ViewHandler.h"

#include "camera/Camera.h"

#include "renderer/IRenderer.h"

namespace wid
{
  class GLWidget;
}

namespace cmr
{
  class CameraController;
}

namespace vwr
{
  class SceneTreeController;
  class RendererController;

  class View
  {
  public:

    View();
    ~View();

    // View handler
    ViewHandler* Handler() { return myViewHandlerPtr.get(); };
    
  private:

    // Build the scene tree
    void Build();

    void SetBuildPending();
    
    // Render the scene tree
    void Render();
    
    void SetRenderPending();
    
    // Initialise the openGL context.
    void GLInitialise();

    // Handle window resizes
    void Resize(int Width, int Height);
    
    // Animate the view
    void Animate();
    
    // Handler for this view.
    T_ViewHandlerPtr myViewHandlerPtr;
    
    // Scene tree for this view
  //  SceneTreeHeadNode mySceneTree;
  
    ree::IRenderer* Renderer() { return myRendererPtr.get(); }
  
    // Renderer for this view
    ree::T_RendererPtr myRendererPtr;
    
    // Camera for this view
    cmr::Camera myCamera;
    
    bool isBuildPending; // Is a new build required?
    bool isRenderPending; // Is a new render required?
    
    // Classes that can access private members
    friend class wid::GLWidget;
    friend class cmr::CameraController;
    friend class SceneTreeController;
    friend class RendererController;
  };
}

#endif
