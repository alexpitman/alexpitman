#include "functional/Signal.h"

#include "test/Test.h"

using namespace fun;

TEST(Signal0)
{
  Signal<void> s;
  
  ASSERT(!s.HasConnections());
  
  int value = 0;
  
  {
    auto c1 = s.Register([&value]() { value++; });
    ASSERT_EQUAL(value, 0);

    ASSERT(s.HasConnections());
    
    s.Notify();
    ASSERT_EQUAL(value, 1);
    
    {
      auto c2 = s.Register([&value]() { value++; });
      s.Notify();
      ASSERT_EQUAL(value, 3);
    }
    
    ASSERT(s.HasConnections());
    
    s.Notify();
    ASSERT_EQUAL(value, 4);
  }
  
  ASSERT(!s.HasConnections());
};

TEST(Signal1)
{
  Signal<void, int> s;
  
  ASSERT(!s.HasConnections());
  
  int value = 0;
  
  {
    auto c1 = s.Register([&value](int increment) { value += increment; });
    ASSERT_EQUAL(value, 0);

    ASSERT(s.HasConnections());
    
    s.Notify(1);
    ASSERT_EQUAL(value, 1);
    
    {
      auto c2 = s.Register([&value](int increment) { value += increment; });
      s.Notify(2);
      ASSERT_EQUAL(value, 5);
    }
    
    ASSERT(s.HasConnections());
    
    s.Notify(2);
    ASSERT_EQUAL(value, 7);
  }
  
  ASSERT(!s.HasConnections());
};

TEST(Signal0WithReturn)
{
  Signal<int> s;
  
  ASSERT(!s.HasConnections());
  
  {
    auto c1 = s.Register([]() { return 42; });

    ASSERT(s.HasConnections());
    
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
    
    ASSERT(s.HasConnections());
    
    r = s.Notify();
    ASSERT_EQUAL(r.size(), 1);
    ASSERT_EQUAL(r[0], 42);
  }
  
  ASSERT(!s.HasConnections());
};

TEST(Signal1WithReturn)
{
  Signal<int, int> s;
  
  ASSERT(!s.HasConnections());
  
  {
    auto c1 = s.Register([](int value) { return value + 1; });

    ASSERT(s.HasConnections());

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
    
    ASSERT(s.HasConnections());
    
    r = s.Notify(23);
    ASSERT_EQUAL(r.size(), 1);
    ASSERT_EQUAL(r[0], 24);
  }
  
  ASSERT(!s.HasConnections());
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
