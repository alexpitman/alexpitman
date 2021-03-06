///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Description    : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <glew.h>

#include "viewer/View.h"

#include "scenetree/SceneTreeNode.h"
#include "scenetree/Light.h"
#include "scenetree/FacetNetworkNode.h"
#include "scenetree/PointSetNode.h"

#include "renderer/Factory.h"
#include "renderer/Shader.h"
#include "renderer/ShaderSource.h"

#include "object/PointSet.h"
#include "object/FacetNetwork.h"
#include "object/Object.h"

#include "attribute/Colour.h"

#include "geometry/Point.h"
#include "geometry/Vector.h"

#include <gl.h>
#include <glu.h>

#include <assert.h>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

namespace local
{
  static st::PointLight light;
  static st::DirectionLight sun;
}

vwr::View::View()
: myRendererPtr(ree::Factory::CreateRenderer()),
  myViewHandlerPtr(new ViewHandler(this)),
  myPolygonRenderMode(ree::PolygonRenderMode::SOLID)
{
}

vwr::View::~View()
{
}

vwr::ViewHandler*
vwr::View::Handler()
{
  return myViewHandlerPtr.get();
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
  if (isBuildPending) Build();
  isRenderPending = false;

  if (myShader) myShader->Bind();
  
  Renderer()->Clear();
  Renderer()->LoadIdentity();
  
  //local::sun.Render();
  
  // Set up camera
  Renderer()->SetCamera(myCamera);
  
  // Set up lights
  //local::light.Render();
  
  Renderer()->SetPolygonRenderMode(myPolygonRenderMode);
  
  // HACK
  glDisable(GL_LIGHTING);
  
  // Render Geometry
  mySceneTreePtr->Render();
}

void
vwr::View::SetRenderPending()
{
  isRenderPending = true;
}

void
vwr::View::GLInitialise()
{
  ::glewInit();
  
  mySceneTreePtr.reset( new st::SceneTreeNode(Renderer()) );

  local::light = st::PointLight(
    mySceneTreePtr,
    geo::Point3D(0, 0, 0),
    att::Colour(1, 1, 1),
    att::Colour(1, 1, 1),
    att::Colour(1, 1, 1) );
  local::sun = st::DirectionLight(
    mySceneTreePtr,
    geo::Vector3D(1, 0, 0),
    att::Colour(1, 0, 0, 1),
    att::Colour(1, 1, 0, 1),
    att::Colour(1, 1, 1, 1) );
  
  Renderer()->EnableLighting();
  glEnable(GL_COLOR_MATERIAL);
  
  Renderer()->SetClearColour( att::Colour(0, 0, 0) );
  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_MULTISAMPLE);
  
  myCamera = cmr::Camera( geo::Point3D(-8, -2, 3),
                          geo::Vector3D(1, 0, 0),
                          geo::Vector3D(0, 0, 1) );
}

void
vwr::View::Resize(int Width, int Height)
{
  Renderer()->ProjectionMode();
  Renderer()->LoadIdentity();
  
  gluPerspective( 80, (GLfloat) Width / Height, 1.0, 100.0 );
  glViewport(0, 0, Width, Height);

  Renderer()->ModelViewMode();
}

void
vwr::View::Animate()
{
  Handler()->InputController()->Animate();
}

void
vwr::View::Mouse( const in::Mouse& Mouse )
{
  Handler()->InputController()->Mouse(Mouse);
}

void
vwr::View::KeyPress( const in::Key& Key )
{
  Handler()->InputController()->KeyPress(Key);
}

void
vwr::View::KeyRelease( const in::Key& Key )
{
  Handler()->InputController()->KeyRelease(Key);
}

void
vwr::View::SetPolygonRenderMode(ree::PolygonRenderMode::Type RenderMode)
{
  myPolygonRenderMode = RenderMode;
}

void
vwr::View::TestShader()
{
  ree::ShaderSource source;
  source.AddSourceCode(
    ree::ShaderType::Fragment,
    R"(#version 330
out vec4 FragColour;
void main()
{
  FragColour = vec4(0.0, 0.0, 1.0, 1.0);
})");

  myShader = ree::MakeShader(source);
}

