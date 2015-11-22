#include "renderer/ShaderSource.h"

ree::ShaderSource::ShaderSource()
: myShaderSources()
{
}

void ree::ShaderSource::AddSourceCode(ShaderType Type, const std::string& Source)
{
  myShaderSources.push_back(std::make_pair(Type, Source));
}

const std::vector<ree::ShaderSource::SourcePair>&
ree::ShaderSource::ShaderSources() const
{
  return myShaderSources;
}
