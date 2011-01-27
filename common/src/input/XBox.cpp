///////////////////////////////////////////////////////////////////////////////
//
// Name           : XBox
// Inheritance    : Base class 
// Desctription   : Representation of a xbox controller
//
///////////////////////////////////////////////////////////////////////////////

#include "input/XBox.h"

in::XBox::XBox(int PlayerNumber)
: myControllerNumber( PlayerNumber - 1 )
{
}

bool
in::XBox::Update()
{
  // Clear the state
  ZeroMemory(&myState, sizeof(XINPUT_STATE));

  DWORD sucess = XInputGetState(myControllerNumber, &myState);
  
  return sucess == ERROR_SUCCESS;
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

void
in::XBox::IsPressed( T_XKey Key )
{
  return myState & Key;
}
