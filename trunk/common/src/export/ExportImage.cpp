///////////////////////////////////////////////////////////////////////////////
//
// Name           : ExportImage
// Inheritance    : Namespace for image exporting functions
// Desctription   : Export an image
//
///////////////////////////////////////////////////////////////////////////////

#include "export/ExportImage.h"

#include <il.h>
#include <iostream>
#include <assert.h>

void
ept::ExportImage::Png(const img::Image& Image, const std::string& FileName)
{
  ilInit();

  ILuint imageName; // The image name to return.
  ilGenImages(1, &imageName);
  
  ilBindImage(imageName);
  
  ilTexImage(Image.Width(), Image.Height(), 1, 3, IL_RGB, IL_UNSIGNED_BYTE, nullptr);
  
  std::vector<unsigned char> pixelsColours(3 * Image.Width() * Image.Height());
  auto pcu = pixelsColours.begin();
  
  auto cu = Image.PixelColourBegin();
  for (unsigned int x = 0; x < Image.Width(); ++x)
  {
    for (unsigned int y = 0; y < Image.Height(); ++y)
    {
      *pcu++ = cu->Red() * 255;
      *pcu++ = cu->Green() * 255;
      *pcu++ = cu->Blue() * 255;
    
      ++cu;
    }
  }
  
  ilSetPixels( 0, 0, 0, Image.Width(), Image.Height(), 1, IL_RGB, IL_UNSIGNED_BYTE, &(*pixelsColours.begin()));
  
  ilEnable(IL_FILE_OVERWRITE);
  ilSave(IL_PNG, FileName.c_str());
  
  ilDeleteImages(1, &imageName);
}


