///////////////////////////////////////////////////////////////////////////////
//
// Name           : ViewHandler
// Inheritance    : Base class 
// Desctription   : View handling
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/ViewHandler.h"

vwr::ViewHandler::ViewHandler()
: myViewPtr(NULL)
{
}
    
vwr::ViewHandler::ViewHandler(View* ViewPtr)
: myViewPtr(ViewPtr)
{
}
  
cmr::T_CameraControllerPtr
vwr::ViewHandler::CameraController()
{
  if ( !myCameraControllerPtr )
  {
    myCameraControllerPtr.reset(new cmr::CameraController(myViewPtr));
  }
  return myCameraControllerPtr;
}

vwr::T_InputControllerPtr
vwr::ViewHandler::InputController()
{
  if ( !myInputControllerPtr )
  {
    myInputControllerPtr.reset(new vwr::InputController(myViewPtr));
  }
  return myInputControllerPtr;
}

