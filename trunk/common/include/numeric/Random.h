#ifndef __NUM_RANDOM_H
#define __NUM_RANDOM_H
///////////////////////////////////////////////////////////////////////////////
//
// Name           : Random
// Inheritance    : Base class
// Desctription   : Generate random seeded numbers.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Dll.h"

namespace num
{
  class Dll_num Random
  {
  public:
  
    Random(unsigned int seed);
    
    double NegOneToOne() const;
    
  };
}

#endif