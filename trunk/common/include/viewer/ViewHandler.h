#ifndef __VWR_VIEW_HANDLER_H
#define __VWR_VIEW_HANDLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Description    : View handling/controlling
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/Dll.h"

#include "input/IInputController.h"

#include "scenetree/ISceneController.h"

#include "renderer/IRendererController.h"

#include "camera/ICameraController.h"

#include <memory>

namespace vwr
{
  class View;
  class ViewHandler;
  
  typedef std::shared_ptr<ViewHandler> T_ViewHandlerPtr;

  class Dll_vwr ViewHandler
  {
  public:
  
    ViewHandler();
    
    ViewHandler(View* ViewPtr);

    // Obtain different controllers on the view
    cmr::T_CameraControllerPtr CameraController();
    in::T_InputControllerPtr InputController();
    st::T_SceneControllerPtr SceneController();
    ree::T_RendererControllerPtr RendererController();
  
  private:
  
    cmr::T_CameraControllerPtr myCameraControllerPtr;
    in::T_InputControllerPtr myInputControllerPtr;
    st::T_SceneControllerPtr mySceneControllerPtr;
    ree::T_RendererControllerPtr myRendererControllerPtr;
  
    vwr::View* myViewPtr;
  
  };
}

#endif
