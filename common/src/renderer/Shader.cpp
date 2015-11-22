#include "renderer/Shader.h"

#include "renderer/ShaderError.h"
#include "renderer/ShaderSource.h"

#include <glew.h>
#include <gl.h>

namespace
{
  namespace local
  {
    // Local class to enable std::make_unique.
    class C_Shader : public ree::Shader
    {
    public:
      C_Shader(const ree::ShaderSource& SourceCode) : ree::Shader(SourceCode) {}
    };
  }
}

void ree::Shader::Bind()
{
  ::glUseProgram(myProgramId);
}

void ree::Shader::Unbind()
{
  ::glUseProgram(0);
}

ree::Shader::~Shader()
{
  if (myProgramId) ::glDeleteProgram(myProgramId);

  for (auto shaderId : myShaderIds)
  {
    ::glDeleteShader(shaderId);
  }
}

ree::Shader::Shader(const ShaderSource& SourceCode)
: myProgramId(0),
  myShaderIds()
{
  std::vector<char*> sourcePointers;
  
  for (const auto& source : SourceCode.ShaderSources())
  {
    Compile(source.first, source.second);
  }

  Link();
}

void ree::Shader::Compile(ShaderType Type, const std::string& Source)
{
  switch (Type)
  {
  case ShaderType::Vertex:
    myShaderIds.push_back(::glCreateShader(GL_VERTEX_SHADER));
    break;
  case ShaderType::Fragment:
    myShaderIds.push_back(::glCreateShader(GL_FRAGMENT_SHADER));
    break;
  case ShaderType::Geometry:
    myShaderIds.push_back(::glCreateShader(GL_GEOMETRY_SHADER));
    break;
  }

  auto data = Source.data();
  ::glShaderSource(myShaderIds.back(), 1, &data, nullptr);
  ::glCompileShader(myShaderIds.back());
  
  GLint status;
  ::glGetShaderiv(myShaderIds.back(), GL_COMPILE_STATUS, &status);
  if (status == GL_FALSE)
  {
    std::vector<GLchar> errorBuffer;
    const GLsizei bufferSize = 4096;
    errorBuffer.resize(bufferSize);
    
    GLsizei length;
    ::glGetShaderInfoLog(
      myShaderIds.back(), bufferSize, &length, errorBuffer.data());
    errorBuffer.back() = '\0';
    
    throw ShaderError(std::string(errorBuffer.data()));
  }
}

void ree::Shader::Link()
{
  myProgramId = ::glCreateProgram();
  for (auto shaderId : myShaderIds)
  {
    ::glAttachShader(myProgramId, shaderId);
  }

  ::glLinkProgram(myProgramId);

  for (auto shaderId : myShaderIds)
  {
    ::glDetachShader(myProgramId, shaderId);
  }

  GLint status;
  ::glGetProgramiv(myProgramId, GL_LINK_STATUS, &status);
  if (status == GL_FALSE)
  {
    GLint maxLength = 0;
    ::glGetProgramiv(myProgramId, GL_INFO_LOG_LENGTH, &maxLength);

    std::vector<GLchar> errorBuffer(maxLength);
    ::glGetProgramInfoLog(myProgramId, maxLength, &maxLength, errorBuffer.data());
    
    throw ShaderError(std::string(errorBuffer.data()));
  }
}

std::unique_ptr<ree::Shader>
ree::MakeShader(const ree::ShaderSource& SourceCode)
{
  return std::make_unique<local::C_Shader>(SourceCode);
}
