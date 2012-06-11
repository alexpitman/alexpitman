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
	
	GLuint BeginList() const;
	void EndList() const;
	void CallList(GLuint Id) const;
  void DeleteList(GLuint Id) const;
	
    void Vertex( const geo::Point3D& Point ) const;
    void Normal( const geo::Vector3D& Direction ) const;
    
    /////////////////////////////////////////////////////////////////////////////
    // Colour operations
    void SetColour( const att::Colour& Colour ) const;
	void SetColour( const geo::Vector3D& Normal ) const;
    void SetClearColour( const att::Colour& Colour ) const;
    
    /////////////////////////////////////////////////////////////////////////////
    // Lighting operations
    void EnableLighting() const;
    void DisableLighting() const;
    
    void EnableLight(int Id) const;
    void DisableLight(int Id) const;
    
    void SetLightDirection(int Id, geo::Vector3D Direction) const;
    void SetLightPosition(int Id, geo::Point3D Position) const;
    void SetAmbient(int Id, att::Colour Colour) const;
    void SetDiffuse(int Id, att::Colour Colour) const;
    void SetSpecular(int Id, att::Colour Colour) const;
  };
}

#endif
