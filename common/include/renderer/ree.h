#ifndef __REE_H
#define __REE_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : ree
// Inheritance    : Enum
// Desctription   : Rendering enums
//
///////////////////////////////////////////////////////////////////////////////

#include <gl.h>

namespace ree
{
  enum DrawMode
  {
    POINTS          = GL_POINTS,
    LINE_STRIP      = GL_LINE_STRIP,
    LINE_LOOP       = GL_LINE_LOOP,
    LINES           = GL_LINES,
    TRIANGLE_STRIP  = GL_TRIANGLE_STRIP,
    TRIANGLE_FAN    = GL_TRIANGLE_FAN,
    TRIANGLES       = GL_TRIANGLES,
  };
}

#endif
