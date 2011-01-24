///////////////////////////////////////////////////////////////////////////////
//
// Name           : InputController
// Inheritance    : Base class 
// Desctription   : Controller that takes in events and does actions based on them
//
///////////////////////////////////////////////////////////////////////////////
 
#include "input/InputController.h"
#include "input/Mouse.h"

#include "viewer/View.h"

namespace local
{
  static const double Sensitivity = 0.5;
  static const double DegSensitivity = 0.3;

  static int IsUp = 0;
  static int IsDown = 0;
  static int IsLeft = 0;
  static int IsRight = 0;
  
  static bool firstMouseEvent = false;
  static in::Mouse lastMouse;
  //static in::Mouse newMouse;

}

in::InputController::InputController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr)
{
}

void
in::InputController::Animate()
{
  cmr::T_CameraControllerPtr cmrController = myViewPtr->Handler()->CameraController();

/*  if ( local::firstMouseEvent )
  {
//    if ( local::newMouse.IsLeftClick() )
//    {
      geo::Vector2D diff = local::newMouse.Position() - local::lastMouse.Position();
      cmrController->RotateYaw( local::DegSensitivity*diff.X() );
      cmrController->RotatePitch( local::DegSensitivity*diff.Y() );
//    }
    local::lastMouse = local::newMouse;
  }*/
  
  if ( local::IsUp ) cmrController->Forward(local::Sensitivity);
  if ( local::IsDown ) cmrController->Backward(local::Sensitivity);
  if ( local::IsLeft ) cmrController->StrafeLeft(local::Sensitivity);
  if ( local::IsRight ) cmrController->StrafeRight(local::Sensitivity);

}

void
in::InputController::Mouse( const in::Mouse& Mouse )
{
  if ( !local::firstMouseEvent )
  {
    local::firstMouseEvent = true;
    local::lastMouse = Mouse;
    return;
  }
  
  cmr::T_CameraControllerPtr cmrController = myViewPtr->Handler()->CameraController();
  
  if ( local::lastMouse.IsLeftClick() )
  {
    if ( Mouse.IsLeftClick() )
    {
      geo::Vector2D diff = Mouse.Position() - local::lastMouse.Position();
      cmrController->RotateYaw( local::DegSensitivity*diff.X() );
      cmrController->RotatePitch( local::DegSensitivity*diff.Y() );
    }
  }
    
  local::lastMouse = Mouse;
}

void
in::InputController::KeyPress( const Key& Key )
{
  SetButton(Key, 1);
}

void
in::InputController::KeyRelease( const Key& Key )
{
  SetButton(Key, -1);
}

void
in::InputController::SetButton( const Key& Key, int Increment)
{
  switch( Key.KeyType() )
  {
  // Movement
  case W:
  case Up:
    local::IsUp += Increment;
    break;
  case S:
  case Down:
    local::IsDown += Increment;
    break;
  case A:
  case Left:
    local::IsLeft += Increment;
    break;
  case D:
  case Right:
    local::IsRight += Increment;
    break;
  default: break; // Do nothing
  }
}



