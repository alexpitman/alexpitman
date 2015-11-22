#ifndef __VWR_RENDERER_CONTROLLER_H
#define __VWR_RENDERER_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : RendererController
// Inheritance    : Base class 
// Description    : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/IRendererController.h"

namespace vwr
{
  class View;

  class RendererController : public ree::IRendererController
  {
  public:
  
    RendererController(vwr::View* ViewPtr);
  
    void SetPolygonRenderMode(ree::PolygonRenderMode::Type RenderMode) override;
  
    void TestShader() override;
  
  private:
  
    View* myViewPtr;
    
  };
}

#endif