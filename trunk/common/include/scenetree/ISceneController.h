#ifndef __ST_I_SCENE_CONTROLLER_H
#define __ST_I_SCENE_CONTROLLER_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ISceneController
// Inheritance    : Interface 
// Desctription   : Scene manipulation
//
///////////////////////////////////////////////////////////////////////////////

namespace obj
{
	class Object;

	typedef boost::shared_ptr<Object> T_ObjectPtr;
}

namespace st
{
	class ISceneController
	{
	public:
	
		virtual void AddObject(const obj::T_ObjectPtr& Object) = 0;
	
	};
}

#endif