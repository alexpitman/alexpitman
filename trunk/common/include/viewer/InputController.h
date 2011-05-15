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

#include "boost/shared_ptr.hpp"

namespace vwr
{
	class View;
  class InputController;
  
  typedef boost::shared_ptr<InputController> T_InputControllerPtr;

  class Dll_vwr InputController
  {
  public:
  
    InputController(vwr::View* ViewPtr);
    
    void Animate();
    
    void Mouse( const in::Mouse& Mouse );
    
    void KeyPress( const in::Key& Key );
    void KeyRelease( const in::Key& Key );
  
  private:
  
    void SetButton( const in::Key& Key, int Increment);
  
    View* myViewPtr;
  
  };
}

#endif
