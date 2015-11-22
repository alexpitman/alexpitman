#ifndef __REE_SHADER_H
#define __REE_SHADER_H

#include "renderer/Dll.h"
#include "renderer/ShaderType.h"

#include <memory>
#include <string>
#include <vector>

namespace ree
{
  class ShaderSource;

  class Dll_ree Shader
  {
  public:

    void Bind();
    void Unbind();
    
    ~Shader();
    
  protected:
    
    Shader(const ShaderSource& SourceCode);
    
  private:
    
    void Compile(ShaderType Type, const std::string& Source);
    void Link();
    
    int myProgramId;
    std::vector<int> myShaderIds;
  };

  Dll_ree std::unique_ptr<Shader> MakeShader(const ShaderSource& SourceCode);
}

#endif