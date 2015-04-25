#ifndef __FUNCTIONAL_SIGNAL_MAP_H
#define __FUNCTIONAL_SIGNAL_MAP_H

#include "Signal.h"

#include <map>

namespace fun
{
  template<typename KEY, typename RETURN, typename... ARGS>
  class SignalMap
  {
  public:

    typedef Signal<RETURN, ARGS...> T_Signal;
    typedef typename T_Signal::T_Callback T_Callback;
  
    SignalMap() : myMap() {}
    
    // No copy (move only).
    SignalMap(const SignalMap<KEY, RETURN, ARGS...>&) = delete;
    SignalMap& operator=(const SignalMap<KEY, RETURN, ARGS...>&) = delete;
  
    // Default move operations.
    SignalMap(SignalMap<KEY, RETURN, ARGS...>&&) = default;
    SignalMap& operator=(SignalMap<KEY, RETURN, ARGS...>&&) = default;
    
    bool HasConnections(const KEY& Key) const
    {
      auto found = myMap.find(Key);
      if (found != myMap.end())
      {
        return found->second.HasConnections();
      }
      return false;
    }
    
    Connection Register(const KEY& Key, const T_Callback& Callback)
    {
      Connection c = myMap[Key].Register(Callback);
      c.myRemoveFunction = std::bind(&SignalMap::Remove, this, Key, c.myRemoveFunction);
      return c;
    }
  
    template<typename std::enable_if<std::is_same<RETURN, void>::value>::type* = nullptr>
    void Notify(const KEY& Key, ARGS... Args) const
    {
      auto found = myMap.find(Key);
      if (found != myMap.end())
      {
        found->second.Notify(std::forward<ARGS>(Args)...);
      }
    }
    
    template<typename std::enable_if<!std::is_same<RETURN, void>::value>::type* = nullptr>
    std::vector<RETURN>
    Notify(const KEY& Key, ARGS... Args) const
    {
      auto found = myMap.find(Key);
      if (found != myMap.end())
      {
        return found->second.Notify(std::forward<ARGS>(Args)...);
      }
      
      return std::vector<RETURN>();
    }
  
  private:
  
    void Remove(const KEY& Key, const std::function<void()>& RemoveFunction)
    {
      RemoveFunction();
      
      auto found = myMap.find(Key);
      if (found != myMap.end() && !found->second.HasConnections())
      {
        myMap.erase(found);
      }
    }
  
    std::map<KEY, T_Signal> myMap;
  };
}

#endif