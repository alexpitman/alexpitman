///////////////////////////////////////////////////////////////////////////////
//
// Name           : RendererController
// Inheritance    : Base class 
// Description    : Render properties manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "RendererController.h"

#include "viewer/View.h"

vwr::RendererController::RendererController(vwr::View* ViewPtr)
: myViewPtr(ViewPtr)
{
}

void vwr::RendererController::SetPolygonRenderMode(ree::PolygonRenderMode::Type RenderMode)
{
  myViewPtr->SetPolygonRenderMode(RenderMode);
}

void vwr::RendererController::TestShader()
{
  myViewPtr->TestShader();
}
