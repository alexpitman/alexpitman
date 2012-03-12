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

void ree::Renderer::Normal( geo::Vector3D Normal ) const
{
  glNormal3f(Normal.X(), Normal.Y(), Normal.Z());
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

// Light Operations ///////////////////////////////////////////////////////////
void ree::Renderer::EnableLighting() const
{
  glEnable(GL_LIGHTING);
}

void ree::Renderer::DisableLighting() const
{
  glDisable(GL_LIGHTING);
}

void ree::Renderer::EnableLight(int Id) const
{
  switch (Id)
  {
  case 0: glEnable(GL_LIGHT0); break;
  case 1: glEnable(GL_LIGHT1); break;
  case 2: glEnable(GL_LIGHT2); break;
  case 3: glEnable(GL_LIGHT3); break;
  case 4: glEnable(GL_LIGHT4); break;
  case 5: glEnable(GL_LIGHT5); break;
  case 6: glEnable(GL_LIGHT6); break;
  case 7: glEnable(GL_LIGHT7); break;
  default: assert(false); // Too many lights
  }
}

void ree::Renderer::DisableLight(int Id) const
{
  switch (Id)
  {
  case 0: glDisable(GL_LIGHT0); break;
  case 1: glDisable(GL_LIGHT1); break;
  case 2: glDisable(GL_LIGHT2); break;
  case 3: glDisable(GL_LIGHT3); break;
  case 4: glDisable(GL_LIGHT4); break;
  case 5: glDisable(GL_LIGHT5); break;
  case 6: glDisable(GL_LIGHT6); break;
  case 7: glDisable(GL_LIGHT7); break;
  default: assert(false); // Too many lights
  }
}

void ree::Renderer::SetLightDirection(int Id, geo::Vector3D Direction) const
{
  float position[4] = {Direction.X(), Direction.Y(), Direction.Z(), 0.0 }; 
  glLightfv(Id, GL_POSITION, position );
}

void ree::Renderer::SetLightPosition(int Id, geo::Point3D Position) const
{
  float position[4] = {Position.X(), Position.Y(), Position.Z(), 1.0 }; 
  glLightfv(Id, GL_POSITION, position );
}

void ree::Renderer::SetAmbient(int Id, att::Colour Colour) const
{
  float colour[4] = {Colour.Red(), Colour.Green(), Colour.Blue(), Colour.Alpha()};
  glLightfv(Id, GL_AMBIENT, colour );
}

void ree::Renderer::SetDiffuse(int Id, att::Colour Colour) const
{
  float colour[4] = {Colour.Red(), Colour.Green(), Colour.Blue(), Colour.Alpha()};
  glLightfv(Id, GL_DIFFUSE, colour );  
}

void ree::Renderer::SetSpecular(int Id, att::Colour Colour) const
{
  float colour[4] = {Colour.Red(), Colour.Green(), Colour.Blue(), Colour.Alpha()};
  glLightfv(Id, GL_SPECULAR, colour );
}
