#ifndef __ST_I_SCENE_CONTROLLER_H
#define __ST_I_SCENE_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ISceneController
// Inheritance    : Interface 
// Description    : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include <memory>

namespace obj
{
  class Object;

  typedef std::shared_ptr<Object> T_ObjectPtr;
}

namespace st
{
  class ISceneController;

  typedef std::shared_ptr<ISceneController> T_SceneControllerPtr;

  class ISceneController
  {
  public:
  
    virtual void AddObject(const obj::T_ObjectPtr& Object) = 0;
  
  };
}

#endif