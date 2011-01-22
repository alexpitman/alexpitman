#ifndef __IN_INPUT_CONTROLLER_H
#define __IN_INPUT_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : InputController
// Inheritance    : Base class 
// Desctription   : Controller that takes in events and does actions based on them
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Key.h"
#include "input/Mouse.h"

#include "boost/shared_ptr.hpp"

namespace vwr
{
  class View;
}

namespace in
{
  class InputController;
  
  typedef boost::shared_ptr<InputController> T_InputControllerPtr;

  class InputController
  {
  public:
  
    InputController(vwr::View* ViewPtr);
    
    void Animate();
    
    void Mouse( const Mouse& Mouse );
    
    void KeyPress( const Key& Key );
    void KeyRelease( const Key& Key );
  
  private:
  
    void SetButton( const Key& Key, int Increment);
  
    vwr::View* myViewPtr;
  
  };
}

#endif
