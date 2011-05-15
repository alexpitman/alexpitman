#ifndef __IN_MOUSE_H
#define __IN_MOUSE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Mouse
// Inheritance    : Base class 
// Desctription   : Representation of a mouse move
//
///////////////////////////////////////////////////////////////////////////////

#include "input/Dll.h"

#include "geometry/Point.h"

#include <QMouseEvent>

namespace in
{
  class Dll_in Mouse
  {
  public:

    Mouse();
    Mouse( double X, double Y, bool IsLeft, bool IsRight, bool IsMiddle );
    
    geo::Point2D Position() const;
    
    bool IsLeftClick() const;
    bool IsRightClick() const;
    
  private:
  
    geo::Point2D myPosition;

    bool isLeftClick;
    bool isRightClick;
    bool isMiddleClick;
    
  };
}

#endif
