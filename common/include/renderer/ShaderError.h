#ifndef __REE_SHADER_ERROR_H
#define __REE_SHADER_ERROR_H

#include "renderer/Dll.h"

#include <string>

namespace ree
{
  class Dll_ree ShaderError
  {
  public:
    ShaderError(const std::string& Reason) : myReason(Reason) {}
    
    const std::string& Reason() const { return myReason; }
    
  private:
    const std::string myReason;
  };
}

#endif