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
  static const double Sensitivity = 0.5f;
  static const double DegSensitivity = 0.3f;

  static double LeftXMove = 0.0f;
  static double LeftYMove = 0.0f;
  static double RightXMove = 0.0f;
  static double RightYMove = 0.0f;
  
  static int IsUp = 0;
  static int IsDown = 0;
  static int IsLeft = 0;
  static int IsRight = 0;
  static int IsRise = 0;
  static int IsFall = 0;
  static int IsRollRight = 0;
  static int IsRollLeft = 0;
  static int IsVibrating = 0;
  static bool IsCurrentlyVibrating = false;
  
  static bool firstMouseEvent = false;
  static in::Mouse lastMouse;
}

vwr::InputController::InputController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr),
  myXboxController(
    1, // Hard coded to player one for now
    std::bind(&InputController::XKeyPress, this, std::placeholders::_1),
    std::bind(&InputController::XKeyRelease, this, std::placeholders::_1),
    std::bind(&InputController::LeftTriggerChange, this, std::placeholders::_1),
    std::bind(&InputController::RightTriggerChange, this, std::placeholders::_1),
    std::bind(&InputController::LeftThumbChange, this, std::placeholders::_1, std::placeholders::_2),
    std::bind(&InputController::RightThumbChange, this, std::placeholders::_1, std::placeholders::_2))
{
}

void
vwr::InputController::Animate()
{
  myXboxController.Poll();

  cmr::T_CameraControllerPtr cmrController = myViewPtr->Handler()->CameraController();
  
  // Camera movement.
  if ( local::LeftYMove != 0.0f )
  {
    cmrController->Forward(local::LeftYMove * local::Sensitivity);
  }
  else if ( local::IsUp )
  {
    cmrController->Forward(local::Sensitivity);
  }
  else if ( local::IsDown )
  {
    cmrController->Backward(local::Sensitivity);
  }
  
  if ( local::LeftXMove != 0.0f )
  {
    cmrController->StrafeRight(local::LeftXMove * local::Sensitivity);
  }
  else if ( local::IsLeft )
  {
    cmrController->StrafeLeft(local::Sensitivity);
  }
  else if ( local::IsRight )
  {
    cmrController->StrafeRight(local::Sensitivity);
  }
  
  if ( local::RightXMove != 0.0f )
  {
    cmrController->RotateX( -local::RightXMove * local::Sensitivity * 3 );
  }
  if ( local::RightYMove != 0.0f )
  {
    cmrController->RotateY( -local::RightYMove * local::Sensitivity * 3 );
  }
  
  if ( local::IsRise ) cmrController->StrafeUp(local::Sensitivity);
  if ( local::IsFall ) cmrController->StrafeDown(local::Sensitivity);
  
  if ( local::IsRollRight ) cmrController->RotateRoll(local::Sensitivity * 3);
  if ( local::IsRollLeft ) cmrController->RotateRoll(-local::Sensitivity * 3);
  
  if ( local::IsVibrating && !local::IsCurrentlyVibrating )
  {
    myXboxController.Vibrate(65535, 65535);
  }
  else if ( !local::IsVibrating && local::IsCurrentlyVibrating )
  {
    myXboxController.Vibrate(0, 0);
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
vwr::InputController::XKeyPress( const in::XKey& Key )
{
  SetButton(Key, 1);
}

void
vwr::InputController::XKeyRelease( const in::XKey& Key )
{
  SetButton(Key, -1);
}

void
vwr::InputController::LeftTriggerChange( short Value )
{
  std::cout << Value << std::endl;
}

void
vwr::InputController::RightTriggerChange( short Value )
{
}
 
void
vwr::InputController::LeftThumbChange( short X, short Y )
{
  local::LeftXMove = X / double(in::XBox::ThumbMaxValue);
  local::LeftYMove = Y / double(in::XBox::ThumbMaxValue);
}

void
vwr::InputController::RightThumbChange( short X, short Y )
{
  local::RightXMove = X / double(in::XBox::ThumbMaxValue);
  local::RightYMove = Y / double(in::XBox::ThumbMaxValue);
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

void
vwr::InputController::SetButton( const in::XKey& Key, int Increment)
{
  switch (Key.KeyType())
  {
  case in::XA:
    local::IsFall += Increment;
    break;
  case in::XB:
    local::IsRise += Increment;
    break;
  case in::XLeftShoulder:
    local::IsRollLeft += Increment;
    break;
  case in::XRightShoulder:
    local::IsRollRight += Increment;
    break;
  default: break; // Do nothing
  }
}



