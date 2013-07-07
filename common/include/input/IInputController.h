#ifndef __IN_I_INPUT_CONTROLLER_H
#define __IN_I_INPUT_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : InputController
// Inheritance    : Base class 
// Description    : Controller that takes in events and does actions based on them
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Key.h"
#include "input/Mouse.h"
#include "input/XBox.h"

#include <memory>

namespace in
{
  class IInputController;
  
  typedef std::shared_ptr<IInputController> T_InputControllerPtr;

  class IInputController
  {
  public:
    
    virtual void Animate() = 0;
    
    virtual void Mouse( const in::Mouse& Mouse ) = 0;
    
    // Keyboard key presses
    virtual void KeyPress( const in::Key& Key ) = 0;
    virtual void KeyRelease( const in::Key& Key ) = 0;
  
    // XBox controller key presses
    virtual void XKeyPress( const in::XKey& Key ) = 0;
    virtual void XKeyRelease( const in::XKey& Key ) = 0;
    virtual void LeftTriggerChange( short Value ) = 0;
    virtual void RightTriggerChange( short Value ) = 0;
    virtual void LeftThumbChange( short X, short Y ) = 0;
    virtual void RightThumbChange( short X, short Y ) = 0;
  };
}

#endif
