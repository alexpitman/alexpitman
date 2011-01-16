#include "attribute/Colour.h"
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Colour
// Inheritance    : Base class
// Desctription   : See header.
//
///////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <time.h>

///////////////////////////////////////////////////////////////////////////////
namespace local
{
  static bool isSeeded = false;
}
///////////////////////////////////////////////////////////////////////////////

att::Colour::Colour() 
{
}

att::Colour::Colour(
  float Red, 
  float Green, 
  float Blue, 
  float Alpha )
: myRed( Red ),
  myGreen( Green ),
  myBlue( Blue ),
  myAlpha( Alpha ) 
{
}

att::Colour
att::Colour::WhiteColour()
{
  const Colour col( 1, 1, 1 );
  return col;
}

att::Colour
att::Colour::BlackColour()
{
  const Colour col( 0, 0, 0 );
  return col;
}

att::Colour
att::Colour::RedColour()
{
  const Colour col( 1, 0, 0 );
  return col;
}

att::Colour
att::Colour::GreenColour()
{
  const Colour col( 0, 1, 0 );
  return col;
}

att::Colour
att::Colour::BlueColour()
{
  const Colour col( 0, 0, 1 );
  return col;
}

att::Colour
att::Colour::Random()
{
  // Seed random from time
  if ( !local::isSeeded ) 
  {
    srand( (unsigned int) time(NULL) );
    local::isSeeded = true;
  }
  
  return Colour( 
    (float) rand() / RAND_MAX, 
    (float) rand() / RAND_MAX, 
    (float) rand() / RAND_MAX );
}
