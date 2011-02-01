///////////////////////////////////////////////////////////////////////////////
//
// Name           : PointLight, DirectionLight
// Inheritance    : Node
// Desctription   : A light in 3D space
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Light.h"

namespace local
{
  static int IdCounter = 0;
}

st::PointLight::PointLight()
{
}

st::PointLight::PointLight(
  T_SceneTreePtr SceneTree, 
  geo::Point3D Position,
  att::Colour Ambient,
  att::Colour Diffuse,
  att::Colour Specular )
: Node(SceneTree),
  myPosition( Position ),
  myId( local::IdCounter++ ),
  myAmbient(Ambient),
  myDiffuse(Diffuse),
  mySpecular(Specular)
{
  Renderer()->SetLightPosition(myId, myPosition);
  Renderer()->SetAmbient(myId, myAmbient);
  Renderer()->SetDiffuse(myId, myDiffuse);
  Renderer()->SetSpecular(myId, mySpecular);

  Enable();
}

void
st::PointLight::Enable() const
{
  Renderer()->EnableLight(myId);
}

void
st::PointLight::Disable() const
{
  Renderer()->DisableLight(myId);
}

void
st::PointLight::Render() const
{
  Renderer()->SetLightPosition(myId, myPosition);
  
  Renderer()->Begin(ree::POINTS);
  Renderer()->Vertex(myPosition);
  Renderer()->End();
}


st::DirectionLight::DirectionLight()
{
}

st::DirectionLight::DirectionLight(
  T_SceneTreePtr SceneTree,
  geo::Vector3D Direction,
  att::Colour Ambient,
  att::Colour Diffuse,
  att::Colour Specular )
: Node(SceneTree),
  myDirection( Direction ),
  myId( local::IdCounter++ ),
  myAmbient(Ambient),
  myDiffuse(Diffuse),
  mySpecular(Specular)
{
  Renderer()->SetLightDirection(myId, myDirection);
  Renderer()->SetAmbient(myId, myAmbient);
  Renderer()->SetDiffuse(myId, myDiffuse);
  Renderer()->SetSpecular(myId, mySpecular);

  Enable();
}
  
void
st::DirectionLight::Enable() const
{
  Renderer()->EnableLight(myId);
}

void
st::DirectionLight::Disable() const
{
  Renderer()->DisableLight(myId);
}

void
st::DirectionLight::Render() const
{
  Renderer()->SetLightDirection(myId, myDirection);
}