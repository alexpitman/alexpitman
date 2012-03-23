///////////////////////////////////////////////////////////////////////////////
//
// Name           : InputController
// Inheritance    : Base class 
// Desctription   : Controller that takes in events and does actions based on them
//
///////////////////////////////////////////////////////////////////////////////
 
#include "viewer/InputController.h"
#include "viewer/View.h"

#include "input/Mouse.h"
#include "input/XBox.h"

#include <iostream>

namespace local
{
  static const double Sensitivity = 0.5;
  static const double DegSensitivity = 0.3;

  static int IsUp = 0;
  static int IsDown = 0;
  static int IsLeft = 0;
  static int IsRight = 0;
  static int IsRise = 0;
  static int IsFall = 0;
  static int IsRollRight = 0;
  static int IsRollLeft = 0;
  static int IsVibrating = 0;
  
  static bool firstMouseEvent = false;
  static in::Mouse lastMouse;

  static in::XBox xbox(1);
}

vwr::InputController::InputController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr)
{
}

void
vwr::InputController::Animate()
{
  cmr::T_CameraControllerPtr cmrController = myViewPtr->Handler()->CameraController();
  
  // Camera translation movement
  if ( local::IsUp ) cmrController->Forward(local::Sensitivity);
  if ( local::IsDown ) cmrController->Backward(local::Sensitivity);
  if ( local::IsLeft ) cmrController->StrafeLeft(local::Sensitivity);
  if ( local::IsRight ) cmrController->StrafeRight(local::Sensitivity);
  if ( local::IsRise ) cmrController->StrafeUp(local::Sensitivity);
  if ( local::IsFall ) cmrController->StrafeDown(local::Sensitivity);
  if ( local::IsRollRight ) cmrController->RotateRoll(local::Sensitivity * 3);
  if ( local::IsRollLeft ) cmrController->RotateRoll(-local::Sensitivity * 3);
  
  if ( local::IsVibrating )
  {
    local::xbox.Vibrate(65535, 65535);
  }
  else
  {
    local::xbox.Vibrate(0, 0);
  }
}

void
vwr::InputController::Mouse( const in::Mouse& Mouse )
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
      // Camera panning
      geo::Vector2D diff = Mouse.Position() - local::lastMouse.Position();
      cmrController->RotateYaw( local::DegSensitivity*diff.X() );
      cmrController->RotatePitch( local::DegSensitivity*diff.Y() );
    }
  }
    
  local::lastMouse = Mouse;
}

void
vwr::InputController::KeyPress( const in::Key& Key )
{
  SetButton(Key, 1);
}

void
vwr::InputController::KeyRelease( const in::Key& Key )
{
  SetButton(Key, -1);
}

void
vwr::InputController::SetButton( const in::Key& Key, int Increment)
{
  switch( Key.KeyType() )
  {
  // Movement
  case in::W:
  case in::Up:
    local::IsUp += Increment;
    break;
  case in::S:
  case in::Down:
    local::IsDown += Increment;
    break;
  case in::A:
  case in::Left:
    local::IsLeft += Increment;
    break;
  case in::D:
  case in::Right:
    local::IsRight += Increment;
    break;
  case in::PageUp:
    local::IsRise += Increment;
    break;
  case in::PageDown:
    local::IsFall += Increment;
    break;
  case in::Q:
    local::IsRollLeft += Increment;
    break;
  case in::E:
    local::IsRollRight += Increment;
    break;
  case in::V:
    local::IsVibrating += Increment;
    break;
  default: break; // Do nothing
  }
}



