///////////////////////////////////////////////////////////////////////////////
//
// Name           : ViewHandler
// Inheritance    : Base class 
// Description    : View handling
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/ViewHandler.h"

#include "CameraController.h"
#include "InputController.h"
#include "RendererController.h"
#include "SceneController.h"

vwr::ViewHandler::ViewHandler()
: myViewPtr(nullptr)
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
    myCameraControllerPtr.reset(new vwr::CameraController(myViewPtr));
  }
  return myCameraControllerPtr;
}

in::T_InputControllerPtr
vwr::ViewHandler::InputController()
{
  if ( !myInputControllerPtr )
  {
    myInputControllerPtr.reset(new vwr::InputController(myViewPtr));
  }
  return myInputControllerPtr;
}

st::T_SceneControllerPtr
vwr::ViewHandler::SceneController()
{
  if ( !mySceneControllerPtr )
  {
    mySceneControllerPtr.reset(new vwr::SceneController(myViewPtr));
  }
  return mySceneControllerPtr;
}

ree::T_RendererControllerPtr
vwr::ViewHandler::RendererController()
{
  if ( !myRendererControllerPtr )
  {
    myRendererControllerPtr.reset(new vwr::RendererController(myViewPtr));
  }
  return myRendererControllerPtr;
}