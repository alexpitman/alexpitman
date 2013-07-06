#ifndef __VWR_INPUT_CONTROLLER_H
#define __VWR_INPUT_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : InputController
// Inheritance    : Base class 
// Desctription   : Controller that takes in events and does actions based on them
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/Dll.h"

#include "input/Key.h"
#include "input/Mouse.h"
#include "input/XBox.h"

#include <memory>

namespace vwr
{
  class View;
  class InputController;
  
  typedef std::shared_ptr<InputController> T_InputControllerPtr;

  class Dll_vwr InputController
  {
  public:
  
    InputController(vwr::View* ViewPtr);
    
    void Animate();
    
    void Mouse( const in::Mouse& Mouse );
    
    // Keyboard key presses
    void KeyPress( const in::Key& Key );
    void KeyRelease( const in::Key& Key );
  
    // XBox controller key presses
    void XKeyPress( const in::XKey& Key );
    void XKeyRelease( const in::XKey& Key );
    void LeftTriggerChange( short Value );
    void RightTriggerChange( short Value );
    void LeftThumbChange( short X, short Y );
    void RightThumbChange( short X, short Y );
  
  private:
  
    void SetButton( const in::Key& Key, int Increment);
    void SetButton( const in::XKey& Key, int Increment);
  
    void ToggleFacetRenderMode();
  
    View* myViewPtr;
  
    in::XBox myXboxController;
  };
}

#endif
