///////////////////////////////////////////////////////////////////////////////
//
// Name           : Mouse
// Inheritance    : Base class 
// Desctription   : Representation of a mouse move
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Mouse.h"

in::Mouse::Mouse()
: myPosition(geo::Point2D::Null()),
  isLeftClick(false),
  isRightClick(false),
  isMiddleClick(false)
{
}

in::Mouse::Mouse( double X, double Y, bool IsLeft, bool IsRight, bool IsMiddle )
: myPosition( geo::Point2D(X, Y) ),
  isLeftClick(IsLeft),
  isRightClick(IsRight),
  isMiddleClick(IsMiddle)
{
}
    
geo::Point2D
in::Mouse::Position() const
{
  return myPosition;
}
    
bool
in::Mouse::IsLeftClick() const
{
  return isLeftClick;
}

bool
in::Mouse::IsRightClick() const
{
  return isRightClick;
}
