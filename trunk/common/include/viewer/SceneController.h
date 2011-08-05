#ifndef __VWR_SCENE_CONTROLLER_H
#define __VWR_SCENE_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : SceneController
// Inheritance    : Base class 
// Desctription   : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

#include "viewer/Dll.h"

#include "boost/shared_ptr.hpp"

namespace obj
{
	class Object;

	typedef boost::shared_ptr<Object> T_ObjectPtr;
}

namespace vwr
{
	class View;

	class Dll_vwr SceneController
	{
	public:
	
		void AddObject(const obj::T_ObjectPtr& Object);
	
	private:
  
    vwr::View* myViewPtr;
		
	};
}

#endif