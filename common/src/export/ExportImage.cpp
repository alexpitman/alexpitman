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
  
  ilTexImage(Image.Width(), Image.Height(), 0, 3, IL_RGB, IL_UNSIGNED_BYTE, nullptr);
  
  auto cu = Image.PixelColourBegin();
  for (unsigned int x = 0; x < Image.Width(); ++x)
  {
    for (unsigned int y = 0; y < Image.Height(); ++y)
    {
      unsigned char colour[3] = {
        cu->Red()   * 255,
        cu->Green() * 255,
        cu->Blue()  * 255 };
    
      ilSetPixels(x, y, 0, 1, 1, 1, IL_RGB, IL_UNSIGNED_BYTE, colour);
      ++cu;
    }
  }
  
  ilEnable(IL_FILE_OVERWRITE);
  ilSave(IL_PNG, FileName.c_str());
  
  ilDeleteImages(1, &imageName);
}


