#ifndef __IN_KEY_H
#define __IN_KEY_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Key
// Inheritance    : Base class 
// Desctription   : Representation of a key press (plus modifiers)
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Dll.h"

#include <QKeyEvent>

namespace in
{
  enum T_Key
  {
    // Misc keys
    Escape    = Qt::Key_Escape,
    Tab       = Qt::Key_Tab,
    BackTab   = Qt::Key_Backtab,
    BackSpace = Qt::Key_Backspace,
    Return    = Qt::Key_Return,
    Enter     = Qt::Key_Enter,
    Insert    = Qt::Key_Insert,
    Delete    = Qt::Key_Delete,
    Pause     = Qt::Key_Pause,
    Print     = Qt::Key_Print,
    SysReq    = Qt::Key_SysReq,
    Clear     = Qt::Key_Clear,
    
    // Cursor movement
    Home     = Qt::Key_Home,
    End      = Qt::Key_End,
    PageUp   = Qt::Key_PageUp,
    PageDown = Qt::Key_PageDown,
  
    // Arrows
    Up    = Qt::Key_Up,
    Down  = Qt::Key_Down,
    Left  = Qt::Key_Left,
    Right = Qt::Key_Right,
    
    // Modifiers
    Shift   = Qt::Key_Shift,
    Control = Qt::Key_Control,
    Windows = Qt::Key_Meta,
    Alt     = Qt::Key_Alt,
    Space   = Qt::Key_Space,
    
    // Locks
    CapsLock   = Qt::Key_CapsLock,
    NumLock    = Qt::Key_NumLock,
    ScrollLock = Qt::Key_ScrollLock,
    
    // Function keys
    F1  = Qt::Key_F1,
    F2  = Qt::Key_F2,
    F3  = Qt::Key_F3,
    F4  = Qt::Key_F4,
    F5  = Qt::Key_F5,
    F6  = Qt::Key_F6,
    F7  = Qt::Key_F7,
    F8  = Qt::Key_F8,
    F9  = Qt::Key_F9,
    F10 = Qt::Key_F10,
    F11 = Qt::Key_F11,
    F12 = Qt::Key_F12,
    
    // Letter keys
    A = Qt::Key_A,
    B = Qt::Key_B,
    C = Qt::Key_C,
    D = Qt::Key_D,
    E = Qt::Key_E,
    F = Qt::Key_F,
    G = Qt::Key_G,
    H = Qt::Key_H,
    I = Qt::Key_I,
    J = Qt::Key_J,
    K = Qt::Key_K,
    L = Qt::Key_L,
    M = Qt::Key_M,
    N = Qt::Key_N,
    O = Qt::Key_O,
    P = Qt::Key_P,
    Q = Qt::Key_Q,
    R = Qt::Key_R,
    S = Qt::Key_S,
    T = Qt::Key_T,
    U = Qt::Key_U,
    V = Qt::Key_V,
    W = Qt::Key_W,
    X = Qt::Key_X,
    Y = Qt::Key_Y,
    Z = Qt::Key_Z,
    
    // Number keys
    N0 = Qt::Key_0,
    N1 = Qt::Key_1,
    N2 = Qt::Key_2,
    N3 = Qt::Key_3,
    N4 = Qt::Key_4,
    N5 = Qt::Key_5,
    N6 = Qt::Key_6,
    N7 = Qt::Key_7,
    N8 = Qt::Key_8,
    N9 = Qt::Key_9,
    
    // Number keys + shift
    Exclam     = Qt::Key_Exclam,      // !
    At         = Qt::Key_At,          // @
    Hash       = Qt::Key_NumberSign,  // #
    Dollar     = Qt::Key_Dollar,      // $
    Percent    = Qt::Key_Percent,     // %
    Power      = Qt::Key_AsciiCircum, // ^
    Ampersand  = Qt::Key_Ampersand,   // &
    Star       = Qt::Key_Asterisk,    // *
    ParenLeft  = Qt::Key_ParenLeft,   // (
    ParenRight = Qt::Key_ParenRight,  // )
    
    // Math
    Plus    = Qt::Key_Plus,    // +
    Minus   = Qt::Key_Minus,   // -
    Slash   = Qt::Key_Slash,   // /
    Less    = Qt::Key_Less,    // <
    Equal   = Qt::Key_Equal,   // =
    Greater = Qt::Key_Greater, // >
    
    // Punctuation
    Question    = Qt::Key_Question,   // ?
    DoubleQuote = Qt::Key_QuoteDbl,   // "
    Comma       = Qt::Key_Comma,      // ,
    Apostrophe  = Qt::Key_Apostrophe, // '
    QuoteLeft   = Qt::Key_QuoteLeft,  // `
    Period      = Qt::Key_Period,     // .
    Colon       = Qt::Key_Colon,      // :
    Semicolon   = Qt::Key_Semicolon,  // ;
    
    // Other
    Tilde        = Qt::Key_AsciiTilde,     // ~
    Bar          = Qt::Key_Bar,            // |
    BackSlash    = Qt::Key_Backslash,      // backslash (putting symbol is compiler warning)
    Underscore   = Qt::Key_Underscore,     // _
    BracketLeft  = Qt::Key_BracketLeft,    // {
    BracketRight = Qt::Key_BracketRight,   // }
    BraceLeft    = Qt::Key_BraceLeft,      // [
    BraceRight   = Qt::Key_BraceRight,     // ]
    AngleLeft    = Qt::Key_guillemotleft,  // <
    AngleRight   = Qt::Key_guillemotright, // >
  };
  
  enum T_Modifier
  {
    None     = Qt::NoModifier,
    ShiftM   = Qt::ShiftModifier,
    ControlM = Qt::ControlModifier,
    AltM     = Qt::AltModifier,
    WindowsM = Qt::MetaModifier,
    KeypadM  = Qt::KeypadModifier,
  };

  class Dll_in Key
  {
  public:

    //Key( QKeyEvent* Event );
    
    Key( signed long int KeyType, signed long int Modifiers );
    
    bool Is( T_Key Key ) const;
    
    T_Key KeyType() const;
    T_Modifier Modifiers() const;
    
  private:
  
    T_Key myKeyType;
    T_Modifier myModifiers;

  };
}

#endif
