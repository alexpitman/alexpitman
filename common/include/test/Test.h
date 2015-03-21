#ifndef __TST_TEST_H
#define __TST_TEST_H

#include "test/Case.h"
#include "test/Dll.h"
#include "test/FailedAssertion.h"

#define BREAK() __debugbreak()

#define ASSERT(CONDITION)                            \
  if (!(CONDITION))                                  \
  {                                                  \
    throw tst::FailedAssertion(                      \
      __LINE__, __FILE__, #CONDITION);               \
  }

#define ASSERT_FAILED_ASSERTION(OPERATION)           \
  {                                                  \
    bool failedAssertion = false;                    \
    try                                              \
    {                                                \
      OPERATION;                                     \
    }                                                \
    catch (const tst::FailedAssertion&)              \
    { failedAssertion = true; }                      \
    ASSERT(failedAssertion);                         \
  }

#define ASSERT_EQUAL(Value, Expected)                \
  if (!(Value == Expected))                          \
  {                                                  \
    throw tst::FailedAssertion(                      \
      __LINE__, __FILE__,                            \
      std::string(#Value) + " == " + #Expected +     \
      "\n  Was: " + std::to_string(Value) +            \
      "\n  Expected: " + std::to_string(Expected));    \
  }
  
#define TEST(NAME)                                   \
  class test_##NAME                                  \
  {                                                  \
  template<typename F>                               \
  test_##NAME(F Function)                            \
  {                                                  \
    tst::Test::AddTest(#NAME, Function);             \
  }                                                  \
                                                     \
  static test_##NAME ourTest;                        \
};                                                   \
test_##NAME test_##NAME::ourTest = []()
  
namespace tst
{
  namespace Test
  {
    template<typename F> void AddTest(const std::string& Name, F Function);
  
    Dll_tst void AddTest(const tst::Case& Case);
  
    Dll_tst void RunTests();
  }
}

template<typename F>
void tst::Test::AddTest(const std::string& Name, F Function)
{
  AddTest(tst::Case(Name, Function));
}

#endif