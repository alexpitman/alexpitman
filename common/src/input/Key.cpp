///////////////////////////////////////////////////////////////////////////////
//
// Name           : Key
// Inheritance    : Base class 
// Desctription   : Representation of a key press (plus modifiers)
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Key.h"

in::Key::Key( QKeyEvent* Event )
: myEvent(Event)
{
}

bool in::Key::Is( T_Key Key ) const
{
  return Key == myEvent->key();
}

in::T_Key
in::Key::KeyType() const
{
  return static_cast<T_Key>( myEvent->key() );
}

/*
in::Key::T_Key
in::Key::KeyType() const
{
  return myKey;
}

in::Key::T_KeyModifiers
in::Key::KeyModifiers() const
{
  return myModifiers;
}
*/