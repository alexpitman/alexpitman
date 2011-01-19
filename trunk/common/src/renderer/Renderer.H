#ifndef __REE_RENDERER_H
#define __REE_RENDERER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Renderer
// Inheritance    : IRenderer
// Desctription   : OpenGL Renderer
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/IRenderer.h"

namespace ree
{
  class Renderer : public IRenderer
  {
  public:
  
    Renderer();
  
    /////////////////////////////////////////////////////////////////////////////
    // Common operations
    void Clear() const;
    void Flush() const;
    
    /////////////////////////////////////////////////////////////////////////////
    // Matrix operations
	void ProjectionMode() const;
	void ModelViewMode() const;
	
    void LoadIdentity() const;
    
	void Push() const;
	void Pop() const;
	
	/////////////////////////////////////////////////////////////////////////////
    // Transform operations
	void Transform(const geo::Vector3D& Vector) const;
	
    /////////////////////////////////////////////////////////////////////////////
    // Drawing operations
    void Begin( ree::DrawMode DrawMode ) const;
    void End() const;

    void Vertex( geo::Point3D Point ) const;
    
    /////////////////////////////////////////////////////////////////////////////
    // Colour operations
    void SetColour( att::Colour Colour ) const;
    void SetClearColour( att::Colour Colour ) const;
  };
}

#endif
