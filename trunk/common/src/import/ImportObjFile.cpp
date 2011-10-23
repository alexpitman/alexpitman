///////////////////////////////////////////////////////////////////////////////
//
// Name           : ImportObjFile
// Inheritance    : Base class
// Description    : Import obj file http://en.wikipedia.org/wiki/Wavefront_Object_file_format
//
///////////////////////////////////////////////////////////////////////////////

#include "import/ImportObjFile.h"

#include "geometry/Point.h"

#include "system/InputStream.h"

#include "numeric/num.h"

#include <vector>
#include <iostream>

namespace local
{
	geo::Point3D ParsePoint(const std::string& Line);
	void ParseFacet(const std::string& Line, std::vector<tpo::Triple>* Facet, std::vector<tpo::Triple>* Normals);
	geo::Vector3D ParseNormal(const std::string& Line);
	//tpo::Double ParseUV(const std::string& Line);
}

geo::Point3D local::ParsePoint(const std::string& Line)
{
	int size = Line.size();
	int i = 0;
	int start = Line.find_first_of(" ", 0, size)+1;
	int next;
	double coord[3] = { num::NaN<double>(), num::NaN<double>(), num::NaN<double>() };
	while ( i < 3 && start != size )
	{
		next = Line.find_first_of(" ", start, size);
		if ( next < 0 ) next = size;
		//std::cout << "substr[" << Line.substr(start, next-start) << "]" << start << " " << next << std::endl;
		
		coord[i] = atof((Line.substr(start, next-start).c_str()));
		
		start = next+1;
		++i;
	}
	if ( coord[0] != coord[0] || coord[1] != coord[1] || coord[2] != coord[2] ) throw std::exception(); // Parse error
	
	return geo::Point3D(coord[0], coord[1], coord[2]);
}

void local::ParseFacet(const std::string& Line, std::vector<tpo::Triple>* Facets, std::vector<tpo::Triple>* Normals)
{
	int size = Line.size();
	int i = 0;
	int start = Line.find_first_of(' ')+1;
	int next, subStart, subEnd;
	int findex[3] = { tpo::NullIndex, tpo::NullIndex, tpo::NullIndex };
	int nindex[3] = { tpo::NullIndex, tpo::NullIndex, tpo::NullIndex };
	int tindex[3] = { tpo::NullIndex, tpo::NullIndex, tpo::NullIndex };
	while ( start < size )
	{
		//std::cout << i << std::endl;

		next = Line.find_first_of(' ', start);
		
		//std::cout << start << " " << size << " " << next << std::endl;
		if ( next < 0 ) next = size;
		//std::cout << "substr[" << Line.substr(start, next-start) << "]" << std::endl;
		
		subEnd = Line.find_first_of('/', start);
		
		int index = i;
		if (i > 2) index = 2;
		
		if ( subEnd < 0 )
		{
			// only facet indicies
			findex[index] = atoi(Line.substr(start, next-start).c_str()) - 1;
		}
		else
		{
			// must have texture/normal indicies as well
			findex[index] = atoi(Line.substr(start, subEnd-start).c_str()) - 1;
			
			//std::cout << Line.substr(start, subEnd-start) << std::endl;
			
			subStart = subEnd + 1;
			subEnd = Line.find_first_of('/', subStart);
			//std::cout << Line.substr(subStart, subEnd-subStart) << std::endl;
			// TODO UV
			
			subStart = subEnd + 1;
			//std::cout << Line.substr(subStart, next-subStart) << std::endl;
			if ( subStart != next )
			{
				nindex[index] = atoi(Line.substr(subStart, next-subStart).c_str()) - 1;
			}
		}
		
		start = next+1;
		++i;
		
		if (i > 2)
		{
			if ( findex[0] == tpo::NullIndex || findex[1] == tpo::NullIndex || findex[2] == tpo::NullIndex ) throw std::exception(); // Parse error
	
			Facets->push_back( tpo::Triple(findex[0], findex[1], findex[2]) );
	
			if ( nindex[0] != tpo::NullIndex || nindex[1] != tpo::NullIndex || nindex[2] != tpo::NullIndex )
			{
				if ( nindex[0] == tpo::NullIndex || nindex[1] == tpo::NullIndex || nindex[2] == tpo::NullIndex ) throw std::exception(); // Parse error
	
				Normals->push_back( tpo::Triple(nindex[0], nindex[1], nindex[2]));
			}
			
			if (start < size)
			{
				findex[1] = findex[2];
				nindex[1] = nindex[2];
			}
		}
	}
}

geo::Vector3D local::ParseNormal(const std::string& Line)
{
	int size = Line.size();
	int i = 0;
	int start = Line.find_first_of(" ", 0, size)+1;
	int next;
	double dir[3] = { num::NaN<double>(), num::NaN<double>(), num::NaN<double>() };
	while ( i < 3 && start != size )
	{
		next = Line.find_first_of(" ", start, size);
		if ( next < 0 ) next = size;
		//std::cout << "substr[" << Line.substr(start, next-start) << "]" << start << " " << next << std::endl;
		
		dir[i] = atof((Line.substr(start, next-start).c_str()));
		
		start = next+1;
		++i;
	}
	if ( dir[0] != dir[0] || dir[1] != dir[1] || dir[2] != dir[2] ) throw std::exception(); // Parse error
	return geo::Vector3D(dir[0], dir[1], dir[2]);
}

obj::T_FacetNetworkPtr
imp::ImportObjFile::Import(const std::string& File)
{
	sys::InputStream in(File);
	
	std::vector<geo::Point3D> points;
	std::vector<geo::Vector3D> normals;
	std::vector<tpo::Triple> facets;
	std::vector<tpo::Triple> facetToNormal;

	int highestPointIndex = -1;
	int highestNormalIndex = -1;
	
	std::string line;
	int num = 1;
	while (!in.EndOfFile())
	{
		in.Line(&line);
		
		//std::cout << num << " : " << line << std::endl;
		++num;
		
		// Ignore blank lines.
		if ( line.size() == 0 ) continue;
		
		char first = line.at(0);
		// Ignore comment lines.
		if ( first == '#' ) continue;
		
		if ( first == 'v' )
		{
			if ( line.size() == 1 ) throw(std::exception()); // error malformed line
			
			char second = line.at(1);
			if ( second == 'n' )
			{
				normals.push_back(local::ParseNormal(line));
			}
			else if ( second == 't' )
			{
				// local::ParseUV(line);
				//throw(std::exception()); // Not handled yet
			}
			else
			{
				points.push_back( local::ParsePoint(line) );
			}
		}
		else if ( first == 'f' )
		{
			std::vector<tpo::Triple> newFacets, newNormals;
			local::ParseFacet(line, &newFacets, &newNormals);
			
			for (int i = 0; i < newFacets.size(); ++i)
			{
				const tpo::Triple& f = newFacets[i];
				for (int j = 0; j < 3; ++j )
				{
					if (static_cast<int>(f[j]) > highestPointIndex) highestPointIndex = f[j];
				}
			}
			facets.insert( facets.end(), newFacets.begin(), newFacets.end() );
			
			for (int i = 0; i < newNormals.size(); ++i)
			{
				const tpo::Triple& f = newNormals[i];
				for (int j = 0; j < 3; ++j )
				{
					if (static_cast<int>(f[j]) > highestNormalIndex) highestNormalIndex = f[j];
				}
			}
			facetToNormal.insert(facetToNormal.end(), newNormals.begin(), newNormals.end());
		}
		else
		{
			throw(std::exception()); // Not handled yet
		}
	}
	
	if ( highestPointIndex >= points.size() ) throw(std::exception()); // index too big
	
	return obj::T_FacetNetworkPtr(new obj::FacetNetwork(points.cbegin(), points.cend(), facets.cbegin(), facets.cend()));
}
