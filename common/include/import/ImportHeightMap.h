#ifndef __IMP_IMPORT_HEIGHT_MAP_H
#define __IMP_IMPORT_HEIGHT_MAP_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ImportHeightMap
// Inheritance    : Base class
// Description    : Import height maps from file
//
///////////////////////////////////////////////////////////////////////////////

#include "import/Dll.h"

#include "object/FacetNetwork.h"

#include <string>

namespace imp
{
	class Dll_imp ImportHeightMap
	{
	public:
	
		static obj::T_FacetNetworkPtr BMPImage(const std::string& File);
	
	};
}

#endif