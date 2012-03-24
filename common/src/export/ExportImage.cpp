///////////////////////////////////////////////////////////////////////////////
//
// Name           : ExportImage
// Inheritance    : Namespace for image exporting functions
// Desctription   : Export an image
//
///////////////////////////////////////////////////////////////////////////////

#include "export/ExportImage.h"

#include <png.h>
#include <iostream>
#include <assert.h>

void
ept::ExportImage::Png(const img::Image& Image, const std::string& FileName)
{
  // Open file for write.
  FILE* fp = fopen(FileName.c_str(), "wb");
  assert(fp);
  
  png_structp pngPtr =
    png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
  assert(pngPtr);
  
  png_infop infoPtr = png_create_info_struct(pngPtr);
  assert(infoPtr);
  
  // Write header
  if (setjmp(png_jmpbuf(pngPtr)))
  {
    assert(false);
  }
  
  png_init_io(pngPtr, fp);

  png_set_IHDR(
    pngPtr,
    infoPtr,
    Image.Width(),
    Image.Height(),
    8, // bit depth
    PNG_COLOR_TYPE_RGB, // colour type
    PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_BASE,
    PNG_FILTER_TYPE_DEFAULT);
  
  std::cout << "HERE" << std::endl;
  png_write_info(pngPtr, infoPtr);

  png_set_packing(pngPtr);

  // Generate rows
  png_bytep* rowPtrs = new png_bytep[Image.Height()];
  assert(rowPtrs);
  
  auto cu = Image.PixelColourBegin();
  for (unsigned int y = 0; y < Image.Height(); ++y)
  {
    png_byte* row = new png_byte[Image.Width() * 3];
    assert(row);
    
    rowPtrs[y] = row;
    
    for (unsigned int x = 0; x < Image.Width(); ++x)
    {
      *row++ = unsigned char(cu->Red() * 255.0);
      *row++ = unsigned char(cu->Green() * 255.0);
      *row++ = unsigned char(cu->Blue() * 255.0);
      ++cu;
    }
  }
  
  // Write bytes
  png_set_rows(pngPtr, infoPtr, rowPtrs);
  
  std::cout << "HERE" << std::endl;
  png_write_image(pngPtr, rowPtrs);
  std::cout << "HERE" << std::endl;
  png_write_end(pngPtr, infoPtr);
  std::cout << "HERE" << std::endl;

  // Clean up heap allocation
  for (unsigned int y = 0; y < Image.Height(); ++y)
  {
	delete [] rowPtrs[y];
    //png_free(pngPtr, rowPtrs[y]);
  }
  delete [] rowPtrs;
  //png_free(pngPtr, rowPtrs);
  
  png_destroy_write_struct(&pngPtr, nullptr);

  // Close file pointer
  fclose(fp);
}


