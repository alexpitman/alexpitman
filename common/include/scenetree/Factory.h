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
  
  typedef boost::shared_ptr<Node> T_NodePtr;

	namespace Factory
	{
		Dll_st st::T_NodePtr NewNode(const obj::T_ObjectPtr& Object);
	};
}

#endif