///////////////////////////////////////////////////////////////////////////////
//
// Name           : Key
// Inheritance    : Base class 
// Desctription   : Representation of a key press (plus modifiers)
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Key.h"

in::Key::Key( signed long int KeyType, signed long int Modifiers )
: myKeyType( static_cast<T_Key>(KeyType) ),
  myModifiers( static_cast<T_Modifier>(Modifiers) )
{
}

bool in::Key::Is( T_Key Key ) const
{
  return Key == myKeyType;
}

in::T_Key
in::Key::KeyType() const
{
  return myKeyType;
}

