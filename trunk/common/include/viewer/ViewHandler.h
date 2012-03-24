#ifndef __VWR_VIEW_HANDLER_H
#define __VWR_VIEW_HANDLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Desctription   : View handling
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/Dll.h"
#include "viewer/InputController.h"
#include "viewer/SceneController.h"

#include "camera/CameraController.h"

namespace vwr
{
  class View;
  class ViewHandler;
  
  typedef boost::shared_ptr<ViewHandler> T_ViewHandlerPtr;

  class Dll_vwr ViewHandler
  {
  public:
  
    ViewHandler();
    
    ViewHandler(View* ViewPtr);

    // Obtain different controllers on the view
    cmr::T_CameraControllerPtr CameraController();
    T_InputControllerPtr InputController();
    st::T_SceneControllerPtr SceneController();
    //T_RendererControllerPtr RendererController();
  
  private:
  
    cmr::T_CameraControllerPtr myCameraControllerPtr;
    T_InputControllerPtr myInputControllerPtr;
    st::T_SceneControllerPtr mySceneControllerPtr;
    //T_RendererControllerPtr myRendererControllerPtr;
  
    vwr::View* myViewPtr;
  
  };
}

#endif
