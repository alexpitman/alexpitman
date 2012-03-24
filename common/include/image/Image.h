#ifndef __IMG_IMAGE_H
#define __IMG_IMAGE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Image
// Inheritance    : Base class 
// Desctription   : Representation of an image
//
///////////////////////////////////////////////////////////////////////////////

#include "image/Dll.h"

#include "attribute/Colour.h"

#include <vector>

namespace img
{
  class Dll_img Image
  {
  public:

    Image(unsigned int Width, unsigned int Height);
    
    unsigned int Width() const;
    unsigned int Height() const;
    
    std::vector<att::Colour>::const_iterator PixelColourBegin() const;
    std::vector<att::Colour>::const_iterator PixelColourEnd() const;
    
  private:
  
    std::vector<att::Colour> myPixelColours;
    
    unsigned int myWidth;
    unsigned int myHeight;
  };
}

#endif
