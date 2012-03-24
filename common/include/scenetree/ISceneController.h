#ifndef __ST_I_SCENE_CONTROLLER_H
#define __ST_I_SCENE_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ISceneController
// Inheritance    : Interface 
// Desctription   : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/ree.h"

#include "boost/shared_ptr.hpp"

namespace obj
{
  class Object;

  typedef boost::shared_ptr<Object> T_ObjectPtr;
}

namespace st
{
  class ISceneController;

  typedef boost::shared_ptr<ISceneController> T_SceneControllerPtr;

  class ISceneController
  {
  public:
  
    virtual void AddObject(const obj::T_ObjectPtr& Object) = 0;
  
    virtual void SetFacetRenderMode(ree::FacetRenderMode FacetRenderMode) = 0;
  
  };
}

#endif