#ifndef __REE_FACTORY_H
#define __REE_FACTORY_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : None
// Desctription   : Factory for creating renderers
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/IRenderer.h"

namespace ree
{
  class Dll_ree Factory
  {
  public:
  
    // Basic renderer
    static T_RendererPtr CreateRenderer();
    
  };
}

#endif
