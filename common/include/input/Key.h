#ifndef __IN_KEY_H
#define __IN_KEY_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Key
// Inheritance    : Base class 
// Desctription   : Representation of a key press (plus modifiers)
//
///////////////////////////////////////////////////////////////////////////////

#include <QKeyEvent>

namespace in
{
  enum T_Key
  {
    Up = Qt::Key_Up,
    Down = Qt::Key_Down,
    Left = Qt::Key_Left,
    Right = Qt::Key_Right,
    
    A = Qt::Key_A,
    D = Qt::Key_D,
    S = Qt::Key_S,
    W = Qt::Key_W,
  };
  
  enum T_Modifier
  {
    // TODO
  };

  class Key
  {
  public:

    Key( QKeyEvent* Event );
    
    bool Is( T_Key Key ) const;
    //T_Key KeyType() const;
    //T_KeyModifiers KeyModifiers() const;
    
    T_Key KeyType() const;
    
  private:
  
    //T_Key myKey;
    //T_KeyModifiers myModifiers;
    QKeyEvent* myEvent;

  };
}

#endif
