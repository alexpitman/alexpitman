#ifndef __VWR_VIEW_HANDLER_H
#define __VWR_VIEW_HANDLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Desctription   : View handling
//
///////////////////////////////////////////////////////////////////////////////

#include "camera/CameraController.h"

#include "input/InputController.h"

namespace vwr
{
  class View;
  class ViewHandler;
  
  typedef boost::shared_ptr<ViewHandler> T_ViewHandlerPtr;

  class ViewHandler
  {
  public:
  
    ViewHandler();
    
    ViewHandler(View* ViewPtr);
  
    cmr::T_CameraControllerPtr CameraController();
    
    in::T_InputControllerPtr InputController();
    
    //T_RendererControllerPtr RendererController();
  
  private:
  
    cmr::T_CameraControllerPtr myCameraControllerPtr;
    in::T_InputControllerPtr myInputControllerPtr;
    //T_RendererControllerPtr myRendererControllerPtr;
  
    vwr::View* myViewPtr;
  
  };
}

#endif
