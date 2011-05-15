#ifndef __IN_XBOX_H
#define __IN_XBOX_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : XBox
// Inheritance    : Base class 
// Desctription   : Representation of a xbox controller
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Dll.h"

#include <XInput.h>

namespace in
{
  enum T_XKey
  {
    XUp            = 0x00000001,
    XDown          = 0x00000002,
    XLeft          = 0x00000004,
    XRight         = 0x00000008,
    XStart         = 0x00000010,
    XBack          = 0x00000020,
    XLeftThumb     = 0x00000040,
    XRightThumb    = 0x00000080,
    XLeftShoulder  = 0x0100,
    XRightShoulder = 0x0200,
    XA             = 0x1000,
    XB             = 0x2000,
    XX             = 0x4000,
    XY             = 0x8000,
  };

  class Dll_in XBox
  {
  public:
  
    XBox(int PlayerNumber);
  
    // Poll the xbox controller
    bool Update();
    // Returns false on failure (e.g. connection lost)
  
    // Vibrate the controller
    void Vibrate(int Left, int Right);
    // Controllers have two motors in them (left and right)
    
    bool IsPressed( T_XKey Key ) const;
  
  private:
  
    int myControllerNumber;
    
    XINPUT_STATE myState;
  
  };
}

#endif
