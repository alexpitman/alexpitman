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

#include <memory>

namespace ree
{
  class IRenderer;
  
  typedef std::auto_ptr<IRenderer> T_RendererPtr;

  class IRenderer
  {
  public:
  
    /////////////////////////////////////////////////////////////////////////////
    // Common operations
    virtual void Clear() const = 0;
    virtual void Flush() const = 0;
    
    /////////////////////////////////////////////////////////////////////////////
    // Matrix operations
    virtual void LoadIdentity() const = 0;
    
    /////////////////////////////////////////////////////////////////////////////
    // Drawing operations
    virtual void Begin( ree::DrawMode DrawMode ) const = 0;
    virtual void End() const = 0;

    virtual void Vertex( geo::Point3D Point ) const = 0; 
    
    /////////////////////////////////////////////////////////////////////////////
    // Colour operations
    virtual void SetColour( att::Colour Colour ) const = 0;
    virtual void SetClearColour( att::Colour Colour ) const = 0;
    
    
  };
}

#endif
