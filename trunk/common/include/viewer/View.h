#ifndef __VWR_VIEW_H
#define __VWR_VIEW_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Description    : View rendering
//
///////////////////////////////////////////////////////////////////////////////

//#include "scenetree/SceneTreeNode.h"

#include "viewer/ViewHandler.h"

#include "camera/Camera.h"

#include "scenetree/SceneTreeNode.h"

#include "renderer/IRenderer.h"

#include "input/Key.h"
#include "input/Mouse.h"

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
  class SceneController;
  class RendererController;

  class Dll_vwr View
  {
  public:

    View();
    ~View();

    // View handler
    ViewHandler* Handler();
    
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
    
    // Mouse events
    void Mouse( const in::Mouse& Mouse );
    
    // Key presses/releases
    void KeyPress( const in::Key& Key );
    void KeyRelease( const in::Key& Key );
    
    // Handler for this view.
    T_ViewHandlerPtr myViewHandlerPtr;
  
    inline ree::T_RendererPtr Renderer() { return myRendererPtr; }
  
    void SetFacetRenderMode(ree::FacetRenderMode FacetRenderMode);
  
    // Renderer for this view
    ree::T_RendererPtr myRendererPtr;
    
    // Camera for this view
    cmr::Camera myCamera;
    
    bool isBuildPending; // Is a new build required?
    bool isRenderPending; // Is a new render required?
    
    st::T_SceneTreePtr mySceneTreePtr;
    
    ree::FacetRenderMode myFacetRenderMode;
    
    // Classes that can access private members
    friend class wid::GLWidget;
    friend class vwr::CameraController;
    friend class SceneController;
    friend class RendererController;
  };
}

#endif
