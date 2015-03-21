#include "test/Test.h"

#include <list>

namespace
{
  namespace local
  {
    std::list<tst::Case> OurTestCases;
  }
}

void tst::Test::AddTest(const tst::Case& Case)
{
  local::OurTestCases.push_back(Case);
}

void tst::Test::RunTests()
{
  for (auto c : local::OurTestCases)
  {
    c.Run();
  }
}