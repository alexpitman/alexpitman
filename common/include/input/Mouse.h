#ifndef __IN_MOUSE_H
#define __IN_MOUSE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Mouse
// Inheritance    : Base class 
// Desctription   : Representation of a mouse move
//
///////////////////////////////////////////////////////////////////////////////

#include "geometry/Point.h"

#include <QMouseEvent>

namespace in
{
  class Mouse
  {
  public:

    Mouse();
    Mouse( QMouseEvent* Event );
    
    geo::Point2D Position() const;
    
    bool IsLeftClick() const;
    bool IsRightClick() const;
    
  private:
  
    geo::Point2D myPosition;

    bool isLeftClick;
    bool isRightClick;
    
  };
}

#endif
