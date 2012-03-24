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

#include <windows.h>
#include <XInput.h>
#include <functional>

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

  enum T_XTrigger
  {
    XTriggerLeft,
    XTriggerRight,
  };
  
  class Dll_in XKey
  {
  public:
    
    XKey( T_XKey Key );
    
    bool Is( T_XKey Key ) const;
    
    T_XKey KeyType() const;
    
  private:
  
    T_XKey myKeyType;

  };
  
  typedef std::function<void(const in::XKey& Key)> T_KeyPressCallback;
  typedef std::function<void(const in::XKey& Key)> T_KeyReleaseCallback;
  typedef std::function<void(short Value)> T_TriggerCallback;
  typedef std::function<void(short X, short Y)> T_ThumbCallback;
  
  class Dll_in XBox
  {
  public:
  
    XBox(
      int PlayerNumber,
      T_KeyPressCallback KeyPressCallback,
      T_KeyReleaseCallback KeyReleaseCallback,
      T_TriggerCallback LeftTriggerCallback,
      T_TriggerCallback RightTriggerCallback,
      T_ThumbCallback LeftThumbCallback,
      T_ThumbCallback RightThumbCallback);
  
    // Poll the xbox controller for changes.
    void Poll();
    // Calls the appropriate callbacks if a button was pressed/released.
  
    // Vibrate the controller
    void Vibrate(int Left, int Right);
    // Controllers have two motors in them (left and right)
    
    // Check if a button is pressed.
    bool IsPressed( T_XKey Key ) const;
  
    // Get the trigger pressed down amount.
    short LeftTrigger() const;
    short RightTrigger() const;
    // Range 0-255
  
    static const short TriggerMaxValue = 255;
  
    // Get the thumb stick position.
    short ThumbLeftX() const;
    short ThumbLeftY() const;
    short ThumbRightX() const;
    short ThumbRightY() const;
    // Range -32768 and 32767.
    
    static const short ThumbMaxValue = 32767;
    
  private:
  
    // Poll the xbox controller
    bool Update(XINPUT_STATE* State);
    // Returns false on failure (e.g. connection lost)
  
    // Check if a given key has changed states.
    bool HasKeyStateChanged( T_XKey Key, XINPUT_STATE Old, XINPUT_STATE New );
  
    int myControllerNumber;
    
    T_KeyPressCallback myKeyPressCallback;
    T_KeyReleaseCallback myKeyReleaseCallback;
    
    T_TriggerCallback myLeftTriggerCallback;
    T_TriggerCallback myRightTriggerCallback;
    
    T_ThumbCallback myLeftThumbCallback;
    T_ThumbCallback myRightThumbCallback;
    
    XINPUT_STATE myState;
  };
}

#endif
