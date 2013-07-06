#ifndef __OBJ_OBJECT_H
#define __OBJ_OBJECT_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Object
// Inheritance    : Base class
// Description    : Basic class for all objects (facet networks etc)
//
///////////////////////////////////////////////////////////////////////////////

#include "object/Dll.h"

#include <memory>

namespace obj
{
	class Object;

	typedef std::shared_ptr<Object> T_ObjectPtr;

	class Dll_obj Object
	{
	public:
	
		Object() {};
		
	};
}

#endif