///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneController
// Inheritance    : Base class 
// Description    : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "SceneController.h"

#include "viewer/View.h"

#include "scenetree/Factory.h"

#include "object/Object.h"

vwr::SceneController::SceneController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr)
{
}

void vwr::SceneController::AddObject(const obj::T_ObjectPtr& Object)
{
  auto node = st::Factory::NewNode(myViewPtr->mySceneTreePtr, Object);
  if (node)
  {
    myViewPtr->mySceneTreePtr->AddNode(node);
  }
}
