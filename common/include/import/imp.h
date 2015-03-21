#ifndef __IMP_IMP_H
#define __IMP_IMP_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ImportObjFile
// Inheritance    : Base class
// Description    : Import obj file http://en.wikipedia.org/wiki/Wavefront_Object_file_format
//
///////////////////////////////////////////////////////////////////////////////

#include "import/Dll.h"

#include <string>

namespace imp
{
  class Dll_imp Base : public std::exception
  {
  public:
  
    Base(const std::string& Reason) : myReason(Reason) {}
  
    const char* what() const override { return myReason.c_str(); }
    
  private:
    
    std::string myReason;
  };
}

#endif