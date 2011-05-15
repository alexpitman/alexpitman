#ifndef __TPO_TRIPLE_H
#define __TPO_TRIPLE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Triple
// Inheritance    : Base class
// Description    : Index triple
//
///////////////////////////////////////////////////////////////////////////////

#include "topology/tpo.h"

namespace tpo
{
	class Dll_tpo Triple
	{
	public:
	
		// Default (null) constructor.
		Triple();
		
		// Create a triple.
		Triple(T_Index I0, T_Index I1, T_Index I2); 
		
		// Obtain elements.
		inline T_Index operator[] (unsigned short int Index) const;
    inline T_Index& operator[] (unsigned short int Index);

		// Copy
    Triple& operator =(const Triple& RHS);
		
		// Equality
		bool operator ==(const Triple& RHS) const;
    bool operator !=(const Triple& RHS) const;
		
		// Check for null
		bool IsNull() const;
		
	private:
	
		T_Index my0;
		T_Index my1;
		T_Index my2;
	
	};
}

///////////////////// INLINE DECLARATIONS /////////////////////////////////////
tpo::T_Index
tpo::Triple::operator[] (unsigned short int Index) const
{
	switch(Index)
	{
	case 0: return my0;
	case 1: return my1;
	case 2: return my2;
	default:
		// ASSERT_UNREACHABLE();
		return my0;
	}
}

tpo::T_Index&
tpo::Triple::operator[] (unsigned short int Index)
{
	switch(Index)
	{
	case 0: return my0;
	case 1: return my1;
	case 2: return my2;
	default:
		// ASSERT_UNREACHABLE();
		return my0;
	}
}

#endif