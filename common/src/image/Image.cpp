///////////////////////////////////////////////////////////////////////////////
//
// Name           : Image
// Inheritance    : Base class 
// Desctription   : Representation of an image
//
///////////////////////////////////////////////////////////////////////////////

#include "image/Image.h"

img::Image::Image(unsigned int Width, unsigned int Height)
: myPixelColours(Width * Height, att::Colour::BlackColour()),
  myWidth(Width),
  myHeight(Height)
{
}

unsigned int
img::Image::Width() const
{
  return myWidth;
}

unsigned int
img::Image::Height() const
{
  return myHeight;
}
    
std::vector<att::Colour>::const_iterator
img::Image::PixelColourBegin() const
{
  return myPixelColours.begin();
}

std::vector<att::Colour>::const_iterator
img::Image::PixelColourEnd() const
{
  return myPixelColours.end();
}

att::Colour&
img::Image::operator() (unsigned int X, unsigned int Y)
{
  return myPixelColours[X + Y * myWidth];
}

const att::Colour&
img::Image::operator() (unsigned int X, unsigned int Y) const
{
  return myPixelColours[X + Y * myWidth];
}
    