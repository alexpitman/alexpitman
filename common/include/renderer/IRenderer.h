#ifndef __REE_IRENDERER_H
#define __REE_IRENDERER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : IRenderer
// Inheritance    : interface
// Desctription   : Interface for renderers
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/ree.h"

#include "geometry/Point.h"

#include "attribute/Colour.h"

namespace ree
{
  class IRenderer
  {
    /////////////////////////////////////////////////////////////////////////////
    // Common methods
    void Clear() const = 0;
    void Flush() const = 0;
    void Swap() const = 0;
    
    /////////////////////////////////////////////////////////////////////////////
    // Drawing methods
    void Begin( reeN::DrawMode DrawMode ) const = 0;
    void End() const = 0;

    void Vertex( Point Point ) const = 0;  
    void SetColour( Colour Colour ) const = 0;
    
    
  };
}

#endif
