#ifndef __ST_SCENETREENODE_H
#define __ST_SCENETREENODE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneTreeNode
// Inheritance    : Node
// Desctription   : The head of the scene tree used for rendering
//
///////////////////////////////////////////////////////////////////////////////

#include "scenetree/Node.h"

namespace st
{
  class SceneTreeNode : Node
  {
  public:
    SceneTreeHeadNode();

    void Rebuild();
    
  private:

    

  };
}

#endif
