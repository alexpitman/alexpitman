///////////////////////////////////////////////////////////////////////////////
//
// Name           : Triple
// Inheritance    : Base class
// Description    : See header.
//
///////////////////////////////////////////////////////////////////////////////

#include "topology/Triple.h"

tpo::Triple::Triple()
: my0(NullIndex),
  my1(NullIndex),
  my2(NullIndex)
{
}

tpo::Triple::Triple(T_Index I0, T_Index I1, T_Index I2)
: my0(I0),
  my1(I1),
  my2(I2)
{
}

tpo::Triple&
tpo::Triple::operator =(const Triple& RHS)
{
	my0 = RHS.my0;
	my1 = RHS.my1;
	my2 = RHS.my2;
	return *this;
}

bool
tpo::Triple::operator ==(const Triple& RHS) const
{
	return my0 == RHS.my0 && my1 == RHS.my1 && my2 == RHS.my2;
}

bool
tpo::Triple::operator !=(const Triple& RHS) const
{
	return !(*this == RHS);
}

bool
tpo::Triple::IsNull() const
{
	return my0 == NullIndex && my1 == NullIndex && my2 == NullIndex;
}

tpo::Triple&
tpo::Triple::Null()
{
	static tpo::Triple t(tpo::NullIndex, tpo::NullIndex, tpo::NullIndex);
	return t;
}

