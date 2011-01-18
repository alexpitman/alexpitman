///////////////////////////////////////////////////////////////////////////////
//
// Name           : Renderer
// Inheritance    : IRenderer
// Desctription   : OpenGL Renderer
//
///////////////////////////////////////////////////////////////////////////////

#include "Renderer.h"

#include <gl.h>

// GL_MULTISAMPLE hack
#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

ree::Renderer::Renderer()
{
}

// Common Operations //////////////////////////////////////////////////////////
void ree::Renderer::Clear() const
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void ree::Renderer::Flush() const
{
  glFlush();
}

// Matrix Operations //////////////////////////////////////////////////////////
void ree::Renderer::LoadIdentity() const
{
  glLoadIdentity();
}

// Drawing Operations /////////////////////////////////////////////////////////
void ree::Renderer::Begin( ree::DrawMode DrawMode ) const
{
  glBegin(DrawMode);
}

void ree::Renderer::End() const
{
  glEnd();
}

void ree::Renderer::Vertex( geo::Point3D Point ) const
{
  glVertex3f(Point.X(), Point.Y(), Point.Z());
}

// Colour Operations //////////////////////////////////////////////////////////
void ree::Renderer::SetColour( att::Colour Colour ) const
{
  glColor4f(Colour.Red(), Colour.Green(), Colour.Blue(), Colour.Alpha());
}

void ree::Renderer::SetClearColour( att::Colour Colour ) const
{
  glClearColor(Colour.Red(), Colour.Green(), Colour.Blue(), Colour.Alpha());
}
