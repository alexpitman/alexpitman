#ifndef __VWR_SCENE_CONTROLLER_H
#define __VWR_SCENE_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneController
// Inheritance    : Base class 
// Description    : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/ISceneController.h"

namespace vwr
{
  class View;

  class SceneController : public st::ISceneController
  {
  public:
  
    SceneController(vwr::View* ViewPtr);
  
    virtual void AddObject(const obj::T_ObjectPtr& Object) override;
  
  private:
  
    View* myViewPtr;
    
  };
}

#endif