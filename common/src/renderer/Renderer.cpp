///////////////////////////////////////////////////////////////////////////////
//
// Name           : Renderer
// Inheritance    : IRenderer
// Desctription   : OpenGL Renderer
//
///////////////////////////////////////////////////////////////////////////////

#include "Renderer.h"

#include "attribute/Colour.h"

#include "geometry/Point.h"
#include "geometry/Vector.h"

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
void ree::Renderer::ProjectionMode() const
{
  glMatrixMode( GL_PROJECTION );
}

void ree::Renderer::ModelViewMode() const
{
  glMatrixMode( GL_MODELVIEW );
}

void ree::Renderer::LoadIdentity() const
{
  glLoadIdentity();
}

void ree::Renderer::Push() const
{
  glPushMatrix();
}

void ree::Renderer::Pop() const
{
  glPopMatrix();
}

// Transform Operations ///////////////////////////////////////////////////////
void ree::Renderer::Transform(const geo::Vector3D& Vector) const
{
  glTranslatef(Vector.X(), Vector.Y(), Vector.Z());
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
