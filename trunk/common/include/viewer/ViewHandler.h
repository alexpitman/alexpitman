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
    
    //T_RendererControllerPtr RendererController();
  
  private:
  
    cmr::T_CameraControllerPtr myCameraControllerPtr;
    //T_RendererControllerPtr myRendererControllerPtr;
  
    vwr::View* myViewPtr;
  
  };
}

#endif
