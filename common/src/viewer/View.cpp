///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Desctription   : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/View.h"

#include "renderer/Factory.h"

#include "attribute/Colour.h"

#include <gl.h>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

vwr::View::View()
: myRendererPtr(ree::Factory::CreateRenderer())
{
}

vwr::View::~View()
{
}

void
vwr::View::Build()
{
  isBuildPending = false;
}

void
vwr::View::SetBuildPending()
{
  isBuildPending = true;
}

void 
vwr::View::Render()
{
  if ( isBuildPending ) Build();
  isRenderPending = false;

  Renderer()->Clear();
  Renderer()->LoadIdentity();
  
  glTranslatef(0, 0, 8);
  glRotatef(210, 1, 0, 0);
  glRotatef(210, 0, 0, 1);
  
  Renderer()->Begin(ree::TRIANGLES);
  
  Renderer()->SetColour( att::Colour(0, 1, 0) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) ); // Front
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  
  Renderer()->SetColour( att::Colour(1, 0, 0) );
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) ); // Back
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  
  Renderer()->SetColour( att::Colour(1, 1, 0) );
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) );
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  
  Renderer()->SetColour( att::Colour(0, 1, 1) );
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  
  Renderer()->SetColour( att::Colour(1, 0, 1) );
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  
  Renderer()->SetColour( att::Colour(1, 1, 1) );
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  
  Renderer()->End();
}

void
vwr::View::SetRenderPending()
{
  isRenderPending = true;
}

void
vwr::View::GLInitialise()
{
  Renderer()->SetClearColour( att::Colour(0, 0, 0) );
  //glClearColor(0, 0, 0, 1) );
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glShadeModel(GL_SMOOTH);
  //glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  glEnable(GL_MULTISAMPLE);
}

void
vwr::View::Resize(int Width, int Height)
{
  glViewport(0, 0, Width, Height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glOrtho(-10, +10, -10, +10, -4.0, -15.0);

  glMatrixMode(GL_MODELVIEW);
}