///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : Namespace
// Desctription   : Creation of scenetree elements.
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Factory.h"

#include "scenetree/FacetNetworkNode.h"
#include "scenetree/PointSetNode.h"

#include "object/PointSet.h"
#include "object/FacetNetwork.h"
#include "object/Object.h"

st::T_NodePtr
st::Factory::NewNode(const st::T_SceneTreePtr& SceneTreePtr,
                     const obj::T_ObjectPtr& Object)
{
#define CREATE(NAME)                                       \
  {                                                        \
    auto o = std::dynamic_pointer_cast<obj::NAME>(Object); \
    if (o)                                                 \
    {                                                      \
      return std::make_shared<st::NAME##Node>(             \
        SceneTreePtr, o);                                  \
    }                                                      \
  }

  CREATE(PointSet);
  CREATE(FacetNetwork);
  
#undef CREATE
  
  return st::T_NodePtr();
}
