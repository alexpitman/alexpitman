#ifndef __ATT_COLOUR_H
#define __ATT_COLOUR_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Colour
// Inheritance    : Base class
// Desctription   : Struct representing RGBA colour
//
///////////////////////////////////////////////////////////////////////////////

#include "attribute/Dll.h"

namespace att
{
  class Dll_att Colour
  {
  public:
    // Constructors
    Colour();
    Colour(float Red, float Green, float Blue, float Alpha = 1.0 );

    inline float Red() const;
    inline float Green() const;
    inline float Blue() const;
    inline float Alpha() const;
    
    inline bool operator ==(const Colour& RHS) const;
    inline bool operator !=(const Colour& RHS) const;
    
    static Colour WhiteColour();
    static Colour BlackColour();
    
    static Colour RedColour();
    static Colour GreenColour();
    static Colour BlueColour();
    
    static Colour Random();
    
  private:
  
    float myRed;
    float myGreen;
    float myBlue;
    float myAlpha;
  };
}

///////////////////// INLINE DECLARATIONS /////////////////////////////////////

float att::Colour::Red() const { return myRed; }
float att::Colour::Green() const { return myGreen; }
float att::Colour::Blue() const { return myBlue; }
float att::Colour::Alpha() const { return myAlpha; }

inline bool att::Colour::operator ==(const Colour& RHS) const
{
  return myRed   == RHS.myRed &&
         myGreen == RHS.myGreen &&
         myBlue  == RHS.myBlue &&
         myAlpha == RHS.myAlpha;
}

inline bool att::Colour::operator !=(const Colour& RHS) const
{
  return !(*this == RHS);
}

///////////////////////////////////////////////////////////////////////////////

#endif