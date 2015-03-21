#ifndef __ST_FACTORY_H
#define __ST_FACTORY_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Factory
// Inheritance    : Namespace
// Desctription   : Creation of scenetree elements.
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Dll.h"

#include "object/Object.h"

namespace st
{
  class Node;
  class SceneTreeNode;
  
  typedef std::shared_ptr<Node> T_NodePtr;
  typedef std::shared_ptr<SceneTreeNode> T_SceneTreePtr;

  namespace Factory
  {
    Dll_st st::T_NodePtr NewNode(const st::T_SceneTreePtr& SceneTreePtr,
                                 const obj::T_ObjectPtr& Object);
  };
}

#endif