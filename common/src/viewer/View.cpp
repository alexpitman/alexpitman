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

#include "geometry/Point.h"
#include "geometry/Vector.h"

#include <gl.h>

#include <glu.h>

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
  
  // Set up camera
  myCamera.SetCamera();
  
  Renderer()->Transform( geo::Vector3D(8, 0, 0) );
  //glRotatef(210, 1, 0, 0);
  //glRotatef(210, 0, 0, 1);
  
  // Render Geometry
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
  
  myCamera = cmr::Camera( geo::Point3D(0, 0, 0),
                          geo::Vector3D(8, 0, 0),
                          geo::Vector3D(0, 0, 1) );
}

void
vwr::View::Resize(int Width, int Height)
{
  Renderer()->ProjectionMode();
  Renderer()->LoadIdentity();
  
  gluPerspective( 80, (GLfloat) Width / Height, 1.0, 30.0 );
  glViewport(0, 0, Width, Height);

  Renderer()->ModelViewMode();
}