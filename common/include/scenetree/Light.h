#ifndef __ST_LIGHT_H
#define __ST_LIGHT_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : PointLight, DirectionLight
// Inheritance    : Node
// Desctription   : A light in 3D space
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Node.h"

#include "attribute/Colour.h"

#include "geometry/Point.h"
#include "geometry/Vector.h"

namespace st
{
  class Dll_st PointLight : public Node
  {
  public:
  
    PointLight();
    PointLight(
      T_SceneTreePtr SceneTree,
      geo::Point3D Position,
      att::Colour Ambient,
      att::Colour Diffuse,
      att::Colour Specular );
  
    void Enable() const;
    void Disable() const;
  
    void Render() const override;
  
    geo::Extent3D Extent() const override { return geo::Extent3D(); }
  
  private:
  
    // Light ID
    int myId;
  
    // Light position
    geo::Point3D myPosition;
    
    // Light colours
    att::Colour myDiffuse;
    att::Colour myAmbient;
    att::Colour mySpecular;
    
    // Attenuation
    float myConstantAttenuation;
    float myLinearAttenuation;
    float myQuadraticAttenuation;
  
  };
  
  class Dll_st DirectionLight : public Node
  {
  public:
  
    DirectionLight();
    DirectionLight(
      T_SceneTreePtr SceneTree,
      geo::Vector3D Direction,
      att::Colour Ambient,
      att::Colour Diffuse,
      att::Colour Specular );
  
    void Enable() const;
    void Disable() const;
    
    void Render() const;
  
    geo::Extent3D Extent() const override { return geo::Extent3D(); }
  
  private:
  
    // Light ID
    int myId;
  
    // Light direction
    geo::Vector3D myDirection;
    
    // Light colours
    att::Colour myDiffuse;
    att::Colour myAmbient;
    att::Colour mySpecular;
    
    // Attenuation
    float myConstantAttenuation;
    float myLinearAttenuation;
    float myQuadraticAttenuation;
  
  };
}

#endif
