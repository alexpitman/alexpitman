#ifndef __REE_IRENDERER_H
#define __REE_IRENDERER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : IRenderer
// Inheritance    : interface
// Desctription   : Interface for renderers
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/Dll.h"
#include "renderer/ree.h"

#include "boost/shared_ptr.hpp"

namespace att
{
  class Colour;
}

namespace geo
{
  class Point3D;
  class Vector3D;
}

namespace ree
{
  class IRenderer;
  
  typedef boost::shared_ptr<IRenderer> T_RendererPtr;

  class Dll_ree IRenderer
  {
  public:
  
    /////////////////////////////////////////////////////////////////////////////
    // Common operations
    virtual void Clear() const = 0;
    virtual void Flush() const = 0;
    
    /////////////////////////////////////////////////////////////////////////////
    // Matrix operations
    virtual void ProjectionMode() const = 0;
    virtual void ModelViewMode() const = 0;

    virtual void LoadIdentity() const = 0;

    virtual void Push() const = 0;
    virtual void Pop() const = 0;
    
    /////////////////////////////////////////////////////////////////////////////
    // Transformation operations
    virtual void Transform(const geo::Vector3D& Vector) const = 0;

    /////////////////////////////////////////////////////////////////////////////
    // Drawing operations
    virtual void Begin( ree::DrawMode DrawMode ) const = 0;
    virtual void End() const = 0;

    virtual void Vertex( geo::Point3D Point ) const = 0; 
    
    /////////////////////////////////////////////////////////////////////////////
    // Colour operations
    virtual void SetColour( att::Colour Colour ) const = 0;
    virtual void SetClearColour( att::Colour Colour ) const = 0;
    
    /////////////////////////////////////////////////////////////////////////////
    // Lighting operations
    virtual void EnableLighting() const  = 0;
    virtual void DisableLighting() const  = 0;
    
    virtual void EnableLight(int Id) const  = 0;
    virtual void DisableLight(int Id) const  = 0;
    
    virtual void SetLightDirection(int Id, geo::Vector3D Direction) const = 0;
    virtual void SetLightPosition(int Id, geo::Point3D Position) const = 0;
    virtual void SetAmbient(int Id, att::Colour Colour) const = 0;
    virtual void SetDiffuse(int Id, att::Colour Colour) const = 0;
    virtual void SetSpecular(int Id, att::Colour Colour) const = 0;
  };
}

#endif
