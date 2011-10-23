///////////////////////////////////////////////////////////////////////////////
//
// Name           : View
// Inheritance    : Base class 
// Desctription   : View rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/View.h"

#include "scenetree/SceneTreeNode.h"
#include "scenetree/Light.h"
#include "scenetree/FacetNetworkNode.h"
#include "scenetree/PointSetNode.h"

#include "renderer/Factory.h"

#include "import/ImportObjFile.h"

#include "object/PointSet.h"
#include "object/FacetNetwork.h"
#include "object/Object.h"

#include "attribute/Colour.h"

#include "geometry/Point.h"
#include "geometry/Vector.h"

#include <gl.h>

#include <glu.h>

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
  myViewHandlerPtr(new ViewHandler(this))
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
  if ( isBuildPending ) Build();
  isRenderPending = false;

  Renderer()->Clear();
  Renderer()->LoadIdentity();
  
  local::sun.Render();
  
  // Set up camera
  myCamera.SetCamera();  
  
  // Set up lights
  local::light.Render();
  
  
  Renderer()->Transform( geo::Vector3D(8, 0, 0) );
  
  // Render Geometry
	/*
  Renderer()->Begin(ree::TRIANGLES);
  
  Renderer()->SetColour( att::Colour(0, 1, 0) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) ); // Front
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  
  Renderer()->SetColour( att::Colour(1, 0, 0) );
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) ); // Back
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) );
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  
  Renderer()->SetColour( att::Colour(1, 1, 0) );
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  
  Renderer()->SetColour( att::Colour(0, 1, 1) );
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  Renderer()->Vertex( geo::Point3D(-1, -1,  1) );
  
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  Renderer()->Vertex( geo::Point3D(-1, -1, -1) );
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  
  Renderer()->SetColour( att::Colour(1, 0, 1) );
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  
  Renderer()->Vertex( geo::Point3D( 1, -1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  Renderer()->Vertex( geo::Point3D( 1, -1,  1) );
  
  Renderer()->SetColour( att::Colour(1, 1, 1) );
  Renderer()->Vertex( geo::Point3D( 1,  1, -1) );
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  
  Renderer()->Vertex( geo::Point3D( 1,  1,  1) );
  Renderer()->Vertex( geo::Point3D(-1,  1, -1) );
  Renderer()->Vertex( geo::Point3D(-1,  1,  1) );
  
  Renderer()->End();
	*/
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
  mySceneTreePtr.reset( new st::SceneTreeNode(Renderer()) );

  local::light = st::PointLight(
    mySceneTreePtr,
    geo::Point3D(-5, 0, 0),
    att::Colour(0, 0, 0, 1),
    att::Colour(0, 0, 0, 1),
    att::Colour(0, 0, 0, 1) );
  local::sun = st::DirectionLight(
    mySceneTreePtr,
    geo::Vector3D(1, 0, 0),
    att::Colour(1, 0, 0, 1),
    att::Colour(1, 1, 0, 1),
    att::Colour(1, 1, 1, 1) );
  
	geo::Point3D points[] = {
		geo::Point3D(-1, -1,  1),
		geo::Point3D(-1,  1,  1),
		geo::Point3D( 1,  1,  1),
		geo::Point3D( 1, -1,  1),
	};
	
	tpo::Triple facets[] = {
		tpo::Triple(0, 1, 2),
		tpo::Triple(0, 2, 3),
	};
	
	obj::T_FacetNetworkPtr f(new obj::FacetNetwork(points, points+4, facets, facets+2));
	obj::T_PointSetPtr p(new obj::PointSet(points, points+4));
	
	obj::T_FacetNetworkPtr f2 = imp::ImportObjFile::Import("test.obj");
	obj::T_FacetNetworkPtr f3 = imp::ImportObjFile::Import("candle.obj");
	
	mySceneTreePtr->AddNode( st::T_NodePtr(new st::FacetNetworkNode(mySceneTreePtr, f)) );
	mySceneTreePtr->AddNode( st::T_NodePtr(new st::FacetNetworkNode(mySceneTreePtr, f2)) );
	mySceneTreePtr->AddNode( st::T_NodePtr(new st::FacetNetworkNode(mySceneTreePtr, f3)) );
	mySceneTreePtr->AddNode( st::T_NodePtr(new st::PointSetNode(mySceneTreePtr, p)) );
	
  Renderer()->EnableLighting();
  glEnable(GL_COLOR_MATERIAL);
  
  Renderer()->SetClearColour( att::Colour(0, 0, 0) );
  
  glPointSize(5);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_MULTISAMPLE);
  
  myCamera = cmr::Camera( geo::Point3D(-1, -2, -3),
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

  //static const geo::Vector3D move(0.1, 0, 0);
  //myCamera.Translate(move);
  
  //myCamera.RotateX(1.0);
  //myCamera.RotateY(1.0);
  //myCamera.RotateZ(1.0);
  //myCamera.RotateRoll(1.0);
  //myCamera.RotatePitch(1.0);
  //myCamera.RotateYaw(1.0);
  
  //myCamera.StrafeUp(0.1);
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


