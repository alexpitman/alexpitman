#ifndef __REE_SHADER_SOURCE_H
#define __REE_SHADER_SOURCE_H

#include "renderer/Dll.h"
#include "renderer/ShaderType.h"

#include <string>
#include <utility>
#include <vector>

namespace ree
{
  class Dll_ree ShaderSource
  {
  public:
  
    using SourcePair = std::pair<ShaderType, std::string>;
  
    ShaderSource();

    void AddSourceCode(ShaderType Type, const std::string& Source);

    const std::vector<SourcePair>& ShaderSources() const;

  private:
    
    std::vector<SourcePair> myShaderSources;
  };
}

#endif