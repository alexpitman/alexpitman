///////////////////////////////////////////////////////////////////////////////
//
// Name           : Mouse
// Inheritance    : Base class 
// Desctription   : Representation of a mouse move
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Mouse.h"

in::Mouse::Mouse()
: myPosition(geo::Point2D::Origin()),
  isLeftClick(false),
  isRightClick(false)
{
}

in::Mouse::Mouse( QMouseEvent* Event )
: myPosition( Event->x(), Event->y() ),
  isLeftClick(false),
  isRightClick(false)
{
  Qt::MouseButtons mb = Event->buttons();
  isLeftClick = mb & Qt::LeftButton;
  isRightClick = mb & Qt::RightButton;
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
