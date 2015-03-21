#include "test/Test.h"

TEST(CheckAssertTrue)
{
  ASSERT(true);
};

TEST(CheckAssertFalse)
{
  ASSERT_FAILED_ASSERTION(ASSERT(false));
};
