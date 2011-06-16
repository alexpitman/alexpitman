///////////////////////////////////////////////////////////////////////////////
//
// Name           : FacetNetworkNode
// Inheritance    : st::Node
// Description    : See header file.
//
///////////////////////////////////////////////////////////////////////////////

#include "system/InputStream.h"

sys::InputStream::InputStream(const std::string& File)
: myStream(File)
{
}

sys::InputStream::~InputStream()
{
  myStream.close();
}

bool
sys::InputStream::EndOfFile() const
{
	return myStream.eof();
}

void
sys::InputStream::Line(std::string* Line)
{
	std::getline(myStream, *Line);
}