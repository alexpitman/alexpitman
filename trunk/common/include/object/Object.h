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

#include "boost/shared_ptr.hpp"

namespace obj
{
	class Dll_obj Object;

	typedef boost::shared_ptr<Object> T_ObjectPtr;

	class Object
	{
	public:
	
		Object() {};
		
	};
}

#endif