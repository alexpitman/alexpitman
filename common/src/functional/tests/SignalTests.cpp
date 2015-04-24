#include "functional/Signal.h"

#include "test/Test.h"

using namespace fun;

TEST(Signal0)
{
  Signal<void> s;
  
  int value = 0;
  auto c1 = s.Register([&value]() { value++; });
  ASSERT_EQUAL(value, 0);

  s.Notify();
  ASSERT_EQUAL(value, 1);
  
  {
    auto c2 = s.Register([&value]() { value++; });
    s.Notify();
    ASSERT_EQUAL(value, 3);
  }
  
  s.Notify();
  ASSERT_EQUAL(value, 4);
};

TEST(Signal1)
{
  Signal<void, int> s;
  
  int value = 0;
  auto c1 = s.Register([&value](int increment) { value += increment; });
  ASSERT_EQUAL(value, 0);

  s.Notify(1);
  ASSERT_EQUAL(value, 1);
  
  {
    auto c2 = s.Register([&value](int increment) { value += increment; });
    s.Notify(2);
    ASSERT_EQUAL(value, 5);
  }
  
  s.Notify(2);
  ASSERT_EQUAL(value, 7);
};

TEST(Signal0WithReturn)
{
  Signal<int> s;
  
  auto c1 = s.Register([]() { return 42; });

  auto r = s.Notify();
  ASSERT_EQUAL(r.size(), 1);
  ASSERT_EQUAL(r[0], 42);
  
  {
    auto c2 = s.Register([]() { return 123; });
    r = s.Notify();
    ASSERT_EQUAL(r.size(), 2);
    ASSERT_EQUAL(r[0], 42);
    ASSERT_EQUAL(r[1], 123);
  }
  
  r = s.Notify();
  ASSERT_EQUAL(r.size(), 1);
  ASSERT_EQUAL(r[0], 42);
};

TEST(Signal1WithReturn)
{
  Signal<int, int> s;
  
  auto c1 = s.Register([](int value) { return value + 1; });

  auto r = s.Notify(42);
  ASSERT_EQUAL(r.size(), 1);
  ASSERT_EQUAL(r[0], 43);
  
  {
    auto c2 = s.Register([](int value) { return value - 1; });
    r = s.Notify(42);
    ASSERT_EQUAL(r.size(), 2);
    ASSERT_EQUAL(r[0], 43);
    ASSERT_EQUAL(r[1], 41);
  }
  
  r = s.Notify(23);
  ASSERT_EQUAL(r.size(), 1);
  ASSERT_EQUAL(r[0], 24);
};

TEST(DestructionOfConnectionAfterSignal)
{
  std::vector<Connection> connections;

  {
    Signal<void> s;
    
    int value = 0;
    connections.emplace_back(s.Register([&value]() { value++; }));
    ASSERT_EQUAL(value, 0);
    
    s.Notify();
    ASSERT_EQUAL(value, 1);
  }
};
