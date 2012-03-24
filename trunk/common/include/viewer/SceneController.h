#ifndef __VWR_SCENE_CONTROLLER_H
#define __VWR_SCENE_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneController
// Inheritance    : Base class 
// Desctription   : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/ISceneController.h"

#include "viewer/Dll.h"

namespace vwr
{
  class View;

  class Dll_vwr SceneController : public st::ISceneController
  {
  public:
  
    SceneController(vwr::View* ViewPtr);
  
    virtual void AddObject(const obj::T_ObjectPtr& Object) override;
  
    virtual void SetFacetRenderMode(ree::FacetRenderMode FacetRenderMode) override;
  
  private:
  
    View* myViewPtr;
    
  };
}

#endif