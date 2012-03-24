///////////////////////////////////////////////////////////////////////////////
//
// Name           : XBox
// Inheritance    : Base class 
// Desctription   : Representation of a xbox controller
//
///////////////////////////////////////////////////////////////////////////////

#include "input/XBox.h"

#include <assert.h>

in::XKey::XKey( T_XKey Key )
: myKeyType(Key)
{
}
    
bool in::XKey::Is( T_XKey Key ) const
{
  return myKeyType == Key;
}

in::T_XKey in::XKey::KeyType() const
{
  return myKeyType;
}

in::XBox::XBox(
  int PlayerNumber,
  T_KeyPressCallback KeyPressCallback,
  T_KeyReleaseCallback KeyReleaseCallback,
  T_TriggerCallback LeftTriggerCallback,
  T_TriggerCallback RightTriggerCallback,
  T_ThumbCallback LeftThumbCallback,
  T_ThumbCallback RightThumbCallback)
: myControllerNumber( PlayerNumber - 1 ),
  myKeyPressCallback(KeyPressCallback),
  myKeyReleaseCallback(KeyReleaseCallback),
  myLeftTriggerCallback(LeftTriggerCallback),
  myRightTriggerCallback(RightTriggerCallback),
  myLeftThumbCallback(LeftThumbCallback),
  myRightThumbCallback(RightThumbCallback)
{
  ZeroMemory(&myState, sizeof(XINPUT_STATE));
}

void in::XBox::Poll()
{
  XINPUT_STATE oldState = myState;
  
  bool sucess = Update(&myState);
  // TODO handle controller disconnect etc.
  
  // Handle sensitivity issues with the triggers (set to zero if less than threshold).
  if (myState.Gamepad.bLeftTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
  {
    myState.Gamepad.bLeftTrigger = 0;
  }
  if (myState.Gamepad.bRightTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
  {
    myState.Gamepad.bRightTrigger = 0;
  }
  
  // Handle sensitivity issues with thumbsticks (set zero if less than threshold).
  if ( myState.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
       myState.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
       myState.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
       myState.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE )
  {
    myState.Gamepad.sThumbLX = 0;
    myState.Gamepad.sThumbLY = 0;
  }
  if ( myState.Gamepad.sThumbRX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
       myState.Gamepad.sThumbRX > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
       myState.Gamepad.sThumbRY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE &&
       myState.Gamepad.sThumbRY > -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE )
  {
    myState.Gamepad.sThumbRX = 0;
    myState.Gamepad.sThumbRY = 0;
  }
  
  // Button changes.
  if (oldState.Gamepad.wButtons != myState.Gamepad.wButtons)
  {
    // Check what was pressed/released.
#define IN_CHECK_BUTTON(BUTTON)                             \
    if (HasKeyStateChanged(BUTTON, oldState, myState))      \
    {                                                       \
      if (IsPressed(BUTTON)) myKeyPressCallback(BUTTON);    \
      else                   myKeyReleaseCallback(BUTTON);  \
    }
    
    IN_CHECK_BUTTON(XUp);
    IN_CHECK_BUTTON(XDown);
    IN_CHECK_BUTTON(XLeft);
    IN_CHECK_BUTTON(XRight);
    IN_CHECK_BUTTON(XStart);
    IN_CHECK_BUTTON(XBack);
    IN_CHECK_BUTTON(XLeftThumb);
    IN_CHECK_BUTTON(XRightThumb);
    IN_CHECK_BUTTON(XLeftShoulder);
    IN_CHECK_BUTTON(XRightShoulder);
    IN_CHECK_BUTTON(XA);
    IN_CHECK_BUTTON(XB);
    IN_CHECK_BUTTON(XX);
    IN_CHECK_BUTTON(XY);
    
#undef IN_CHECK_BUTTON
  }
  
  // Trigger changes.
  if (oldState.Gamepad.bLeftTrigger != myState.Gamepad.bLeftTrigger)
  {
    myLeftTriggerCallback(myState.Gamepad.bLeftTrigger);
  }
  if (oldState.Gamepad.bRightTrigger != myState.Gamepad.bRightTrigger)
  {
    myLeftTriggerCallback(myState.Gamepad.bRightTrigger);
  }
  
  // Thumb changes.
  if (oldState.Gamepad.sThumbLX != myState.Gamepad.sThumbLX ||
      oldState.Gamepad.sThumbLY != myState.Gamepad.sThumbLY)
  {
    myLeftThumbCallback(myState.Gamepad.sThumbLX, myState.Gamepad.sThumbLY);
  }
  if (oldState.Gamepad.sThumbRX != myState.Gamepad.sThumbRX ||
      oldState.Gamepad.sThumbRY != myState.Gamepad.sThumbRY)
  {
    myRightThumbCallback(myState.Gamepad.sThumbRX, myState.Gamepad.sThumbRY);
  }
}

void
in::XBox::Vibrate(int Left, int Right)
{
  XINPUT_VIBRATION vibration;

  // Clear vibration state
  ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
  
  vibration.wLeftMotorSpeed = Left;
  vibration.wRightMotorSpeed = Right;
  
  // Vibrate the controller
  XInputSetState(myControllerNumber, &vibration);
}

bool
in::XBox::IsPressed( in::T_XKey Key ) const
{
  return myState.Gamepad.wButtons & Key;
}

short
in::XBox::LeftTrigger() const
{
  return myState.Gamepad.bLeftTrigger;
}

short
in::XBox::RightTrigger() const
{
  return myState.Gamepad.bRightTrigger;
}
  
short in::XBox::ThumbLeftX() const
{
  return myState.Gamepad.sThumbLX;
}

short
in::XBox::ThumbLeftY() const
{
  return myState.Gamepad.sThumbLY;
}

short
in::XBox::ThumbRightX() const
{
  return myState.Gamepad.sThumbRX;
}

short
in::XBox::ThumbRightY() const
{
  return myState.Gamepad.sThumbRY;
}

bool
in::XBox::Update(XINPUT_STATE* State)
{
  // Clear the state
  ZeroMemory(State, sizeof(XINPUT_STATE));

  DWORD sucess = XInputGetState(myControllerNumber, State);
  
  return sucess == ERROR_SUCCESS;
}

bool in::XBox::HasKeyStateChanged( in::T_XKey Key, XINPUT_STATE Old, XINPUT_STATE New )
{
  switch (Key)
  {
  case in::XUp:
  case in::XDown:
  case in::XLeft:
  case in::XRight:
  case in::XStart:
  case in::XBack:
  case in::XLeftThumb:
  case in::XRightThumb:
  case in::XLeftShoulder:
  case in::XRightShoulder:
  case in::XA:
  case in::XB:
  case in::XX:
  case in::XY:
    return (Old.Gamepad.wButtons & Key) != (New.Gamepad.wButtons & Key);
  }
  assert(false); // Should not be reachable.
  return false;
}
