#ifndef __REE_I_RENDERER_CONTROLLER_H
#define __REE_I_RENDERER_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ISceneController
// Inheritance    : Interface 
// Description    : Render properties manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/ree.h"

#include <memory>

namespace ree
{
  class IRendererController;

  typedef std::shared_ptr<IRendererController> T_RendererControllerPtr;

  class IRendererController
  {
  public:
  
    virtual void SetPolygonRenderMode(ree::PolygonRenderMode::Type RenderMode) = 0;
  
    virtual void TestShader() = 0;
  };
}

#endif