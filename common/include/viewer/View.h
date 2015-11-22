#ifndef __VWR_VIEW_H
#define __VWR_VIEW_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Description    : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/ViewHandler.h"

#include "camera/Camera.h"

#include "scenetree/SceneTreeNode.h"

#include "renderer/IRenderer.h"

#include "input/Key.h"
#include "input/Mouse.h"

#include <memory>

namespace wid
{
  class GLWidget;
}

namespace ree
{
  class Shader;
}

namespace vwr
{
  class CameraController;
  class RendererController;
  class SceneController;
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
    
    void SetPolygonRenderMode(ree::PolygonRenderMode::Type RenderMode);
    
    void TestShader();
    
    // Handler for this view.
    T_ViewHandlerPtr myViewHandlerPtr;
  
    inline ree::T_RendererPtr Renderer() { return myRendererPtr; }
  
    // Renderer for this view
    ree::T_RendererPtr myRendererPtr;
    
    bool isBuildPending; // Is a new build required?
    bool isRenderPending; // Is a new render required?
    
    st::T_SceneTreePtr mySceneTreePtr;
    
    // View properties
    cmr::Camera myCamera;
    ree::PolygonRenderMode::Type myPolygonRenderMode;
    
    std::unique_ptr<ree::Shader> myShader;
    
    // Classes that can access private members
    friend class wid::GLWidget;
    friend class vwr::CameraController;
    friend class vwr::SceneController;
    friend class vwr::RendererController;
  };
}

#endif
