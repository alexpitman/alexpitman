#include "functional/SignalMap.h"

#include "test/Test.h"

#include <string>

using namespace fun;

TEST(SignalMap0)
{
  SignalMap<std::string, void> s;
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
  
  int value = 0;
  {
    auto c1 = s.Register("a", [&value]() { value++; });
    ASSERT_EQUAL(value, 0);

    ASSERT(s.HasConnections("a"));
    ASSERT(!s.HasConnections("b"));
    
    s.Notify("b");
    ASSERT_EQUAL(value, 0);
    
    s.Notify("a");
    ASSERT_EQUAL(value, 1);
    
    {
      auto c2 = s.Register("b", [&value]() { value += 2; });
      
      ASSERT(s.HasConnections("a"));
      ASSERT(s.HasConnections("b"));
      
      s.Notify("b");
      ASSERT_EQUAL(value, 3);
    }
    
    s.Notify("b");
    ASSERT_EQUAL(value, 3);
    
    s.Notify("a");
    ASSERT_EQUAL(value, 4);
  }
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
};

TEST(SignalMap1)
{
  SignalMap<std::string, void, int> s;
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
  
  int value = 0;
  {
    auto c1 = s.Register("a", [&value](int increment) { value += increment; });
    ASSERT_EQUAL(value, 0);

    ASSERT(s.HasConnections("a"));
    ASSERT(!s.HasConnections("b"));
    
    s.Notify("b", 42);
    ASSERT_EQUAL(value, 0);
    
    s.Notify("a", 42);
    ASSERT_EQUAL(value, 42);
    
    {
      auto c2 = s.Register("b", [&value](int decrement) { value -= decrement; });
      
      ASSERT(s.HasConnections("a"));
      ASSERT(s.HasConnections("b"));
      
      s.Notify("b", 42);
      ASSERT_EQUAL(value, 0);
    }
    
    s.Notify("b", 42);
    ASSERT_EQUAL(value, 0);
    
    s.Notify("a", 5);
    ASSERT_EQUAL(value, 5);
  }
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
};

TEST(SignalMap0WithReturn)
{
  SignalMap<std::string, int> s;
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
  
  {
    auto c1 = s.Register("a", []() { return 42; });

    ASSERT(s.HasConnections("a"));
    ASSERT(!s.HasConnections("b"));
    
    auto r = s.Notify("b");
    ASSERT_EQUAL(r.size(), 0);
    
    r = s.Notify("a");
    ASSERT_EQUAL(r.size(), 1);
    ASSERT_EQUAL(r[0], 42);
    
    {
      auto c2 = s.Register("b", []() { return 123; });
      
      ASSERT(s.HasConnections("a"));
      ASSERT(s.HasConnections("b"));
      
      r = s.Notify("b");
      ASSERT_EQUAL(r.size(), 1);
      ASSERT_EQUAL(r[0], 123);
    }
    
    r = s.Notify("b");
    ASSERT_EQUAL(r.size(), 0);
    
    r = s.Notify("a");
    ASSERT_EQUAL(r.size(), 1);
    ASSERT_EQUAL(r[0], 42);
  }
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
};

TEST(SignalMap1WithReturn)
{
  SignalMap<std::string, int, int> s;
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
  
  {
    auto c1 = s.Register("a", [](int value) { return value + 1; });

    ASSERT(s.HasConnections("a"));
    ASSERT(!s.HasConnections("b"));
    
    auto r = s.Notify("b", 42);
    ASSERT_EQUAL(r.size(), 0);
    
    r = s.Notify("a", 42);
    ASSERT_EQUAL(r.size(), 1);
    ASSERT_EQUAL(r[0], 43);
    
    {
      auto c2 = s.Register("b", [](int value) { return value - 1; });
      
      ASSERT(s.HasConnections("a"));
      ASSERT(s.HasConnections("b"));
      
      r = s.Notify("b", 42);
      ASSERT_EQUAL(r.size(), 1);
      ASSERT_EQUAL(r[0], 41);
    }
    
    r = s.Notify("b", 42);
    ASSERT_EQUAL(r.size(), 0);
    
    r = s.Notify("a", 44);
    ASSERT_EQUAL(r.size(), 1);
    ASSERT_EQUAL(r[0], 45);
  }
  
  ASSERT(!s.HasConnections("a"));
  ASSERT(!s.HasConnections("b"));
};

TEST(DestructionOfConnectionAfterSignalMap)
{
  std::vector<Connection> connections;

  {
    SignalMap<std::string, void> s;
    
    int value = 0;
    connections.emplace_back(s.Register("a", [&value]() { value++; }));
    ASSERT_EQUAL(value, 0);
    
    s.Notify("a");
    ASSERT_EQUAL(value, 1);
  }
};
