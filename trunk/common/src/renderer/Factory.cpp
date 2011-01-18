///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : None
// Desctription   : Factory for creating renderers
//
///////////////////////////////////////////////////////////////////////////////

#include "renderer/Factory.H"

#include "Renderer.H"

ree::T_RendererPtr 
ree::Factory::CreateRenderer()
{
  return T_RendererPtr(new Renderer());
}
