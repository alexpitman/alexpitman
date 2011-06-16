///////////////////////////////////////////////////////////////////////////////
//
// Name           : ImportObjFile
// Inheritance    : Base class
// Description    : Import obj file http://en.wikipedia.org/wiki/Wavefront_Object_file_format
//
///////////////////////////////////////////////////////////////////////////////

#include "import/ImportObjFile.h"

#include "system/InputStream.h"

#include <vector>

obj::T_FacetNetworkPtr
imp::ImportObjFile::Import(const std::string& File)
{
	sys::InputStream in(File);
	
	std::vector<geo::Point3D> points;
	std::vector<tpo::Triple> facets;

	std::string line;
	while (!in.EndOfFile())
	{
		in.Line(&line);
	}
	
	return obj::T_FacetNetworkPtr();
	//return obj::T_FacetNetworkPtr(new obj::FacetNetwork(points.cbegin(), points.cend(), facets.cbegin(), facets.cend()));
}
