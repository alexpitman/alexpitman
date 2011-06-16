#ifndef __SYS_INPUT_STREAM_H
#define __SYS_INPUT_STREAM_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : InputStream
// Inheritance    : Base class
// Description    : File input stream
//
///////////////////////////////////////////////////////////////////////////////

#include "system/Dll.h"

#include "boost/shared_ptr.hpp"

#include <fstream>
#include <string>

namespace sys
{
	class InputStream;

	typedef boost::shared_ptr<InputStream> T_InputStreamPtr;

	class Dll_sys InputStream
	{
	public:

		InputStream(const std::string& File);
		
		~InputStream();
		
		bool EndOfFile() const;
		
		void Line(std::string* Line);
		
	private:
	
		std::ifstream myStream;
	
	};
}

#endif