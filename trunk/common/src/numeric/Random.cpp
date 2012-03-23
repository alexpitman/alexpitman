///////////////////////////////////////////////////////////////////////////////
//
// Name           : Random
// Inheritance    : Base class
// Desctription   : Generate random seeded numbers.
//
///////////////////////////////////////////////////////////////////////////////

#include "numeric/Random.h"

#include <stdlib.h>

num::Random::Random(unsigned int seed)
{
  // Seed the random number.
  srand(seed);
}
    
double num::Random::NegOneToOne() const
{
  return 2.0f * (rand() / float(RAND_MAX)) - 1.0f;
}
