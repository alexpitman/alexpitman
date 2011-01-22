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

in::T_InputControllerPtr
vwr::ViewHandler::InputController()
{
  if ( !myInputControllerPtr )
  {
    myInputControllerPtr.reset(new in::InputController(myViewPtr));
  }
  return myInputControllerPtr;
}

