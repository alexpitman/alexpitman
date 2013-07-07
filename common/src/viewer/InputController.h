#ifndef __VWR_INPUT_CONTROLLER_H
#define __VWR_INPUT_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : InputController
// Inheritance    : Base class 
// Description    : Controller that takes in events and does actions based on them
//
///////////////////////////////////////////////////////////////////////////////

#include "input/IInputController.h"
#include "input/Key.h"
#include "input/Mouse.h"
#include "input/XBox.h"

#include <memory>

namespace vwr
{
  class View;

  class InputController : public in::IInputController
  {
  public:
  
    InputController(vwr::View* ViewPtr);
    
    void Animate() override;
    
    void Mouse( const in::Mouse& Mouse ) override;
    
    // Keyboard key presses
    void KeyPress( const in::Key& Key ) override;
    void KeyRelease( const in::Key& Key ) override;
  
    // XBox controller key presses
    void XKeyPress( const in::XKey& Key ) override;
    void XKeyRelease( const in::XKey& Key ) override;
    void LeftTriggerChange( short Value ) override;
    void RightTriggerChange( short Value ) override;
    void LeftThumbChange( short X, short Y ) override;
    void RightThumbChange( short X, short Y ) override;
  
  private:
  
    void SetButton( const in::Key& Key, int Increment);
    void SetButton( const in::XKey& Key, int Increment);
  
    void ToggleFacetRenderMode();
  
    View* myViewPtr;
  
    in::XBox myXboxController;
  };
}

#endif
