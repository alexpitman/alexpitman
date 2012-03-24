///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneController
// Inheritance    : Base class 
// Desctription   : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/SceneController.h"

#include "viewer/View.h"

#include "scenetree/Factory.h"

#include "object/Object.h"

vwr::SceneController::SceneController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr)
{
}

void vwr::SceneController::AddObject(const obj::T_ObjectPtr& Object)
{
  myViewPtr->mySceneTreePtr->AddNode( st::Factory::NewNode(Object) );
}

void vwr::SceneController::SetFacetRenderMode(ree::FacetRenderMode FacetRenderMode)
{
  myViewPtr->SetFacetRenderMode(FacetRenderMode);
}