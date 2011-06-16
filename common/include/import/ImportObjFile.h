#ifndef __IMP_IMPORT_OBJ_FILE_H
#define __IMP_IMPORT_OBJ_FILE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ImportObjFile
// Inheritance    : Base class
// Description    : Import obj file http://en.wikipedia.org/wiki/Wavefront_Object_file_format
//
///////////////////////////////////////////////////////////////////////////////

#include "import/Dll.h"

#include "object/FacetNetwork.h"

#include <string>

namespace imp
{
	class Dll_imp ImportObjFile
	{
	public:
	
		static obj::T_FacetNetworkPtr Import(const std::string& File);
	
	};
}

#endif