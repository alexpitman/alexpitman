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

namespace wid
{
  class GLWidget;
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
    
    // Scene tree for this view
  //  SceneTreeHeadNode mySceneTree;
    
    bool isBuildPending; // Is a new build required?
    bool isRenderPending; // Is a new render required?
    
    // Classes that can access private members
    friend class wid::GLWidget;
    friend class SceneTreeController;
    friend class RendererController;
  };
}

#endif
