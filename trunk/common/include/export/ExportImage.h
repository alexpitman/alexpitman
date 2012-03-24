#ifndef __EXP_EXPORTIMAGE_H
#define __EXP_EXPORTIMAGE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ExportImage
// Inheritance    : Namespace for image exporting functions
// Desctription   : Export an image
//
///////////////////////////////////////////////////////////////////////////////

#include "export/Dll.h"

#include "image/Image.h"

namespace ept
{
  namespace ExportImage
  {
    Dll_ept void Png(const img::Image& Image, const std::string& FileName);
  }
}

#endif
