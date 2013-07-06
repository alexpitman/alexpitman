///////////////////////////////////////////////////////////////////////////////
//
// Name           : Renderer
// Inheritance    : IRenderer
// Description    : OpenGL Renderer
//
///////////////////////////////////////////////////////////////////////////////

#include "Renderer.h"

#include "camera/Camera.h"

#include "attribute/Colour.h"

#include "geometry/Point.h"
#include "geometry/Vector.h"

#include <gl.h>
#include <glu.h>

#include <assert.h>

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

void ree::Renderer::SetCamera(const cmr::Camera& Camera) const
{
  const auto& position = Camera.Position();
  const auto& lookDirection = Camera.LookDirection();
  const auto& upDirection = Camera.UpDirection();

  gluLookAt(
    position.X(), position.Y(), position.Z(),
    position.X() + lookDirection.X(), position.Y() + lookDirection.Y(), position.Z() + lookDirection.Z(),
    upDirection.X(), upDirection.Y(), upDirection.Z());
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

GLuint ree::Renderer::BeginList() const
{
  GLuint id = glGenLists(1);
  
  glNewList(id, GL_COMPILE);
  
  return id;
}

void ree::Renderer::EndList() const
{
  glEndList();
}

void ree::Renderer::CallList(GLuint Id) const
{
  glCallList(Id);
}

void ree::Renderer::DeleteList(GLuint Id) const
{
  glDeleteLists(Id, 1);
}

void ree::Renderer::Vertex( const geo::Point3D& Point ) const
{
  glVertex3f(Point.X(), Point.Y(), Point.Z());
}

void ree::Renderer::Normal( const geo::Vector3D& Normal ) const
{
  glNormal3f(Normal.X(), Normal.Y(), Normal.Z());
}

// Colour Operations //////////////////////////////////////////////////////////
void ree::Renderer::SetColour( const att::Colour& Colour ) const
{
  glColor4f(Colour.Red(), Colour.Green(), Colour.Blue(), Colour.Alpha());
}

void ree::Renderer::SetColour( const geo::Vector3D& Normal ) const
{
  glColor3f(Normal[0]/2 + 0.5f, Normal[1]/2 + 0.5f, Normal[2]/2 + 0.5f);
}

void ree::Renderer::SetClearColour( const att::Colour& Colour ) const
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
