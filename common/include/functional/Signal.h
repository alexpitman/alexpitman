#ifndef __FUNCTIONAL_SIGNAL_H
#define __FUNCTIONAL_SIGNAL_H

#include "Connection.h"
#include "types.h"

#include <algorithm>
#include <functional>
#include <memory>
#include <type_traits>
#include <vector>

namespace fun
{
  class I_SignalInternals {};

  template<typename RETURN, typename... ARGS>
  class Signal
  {
  public:
  
    typedef std::function<RETURN(ARGS...)> T_Callback;
  
    struct S_SignalInternals;
  
    Signal()
    : myInternals(std::make_shared<S_SignalInternals>())
    {
      myInternals->myNextHandleIdentifier = 1;
    }
  
    // No copy (move only).
    Signal(const Signal<RETURN, ARGS...>&) = delete;
    Signal& operator=(const Signal<RETURN, ARGS...>&) = delete;
  
    // Default move operations.
    Signal(Signal<RETURN, ARGS...>&&) = default;
    Signal& operator=(Signal<RETURN, ARGS...>&&) = default;
  
    bool HasConnections() const
    {
      return !myInternals->myCallbacks.empty();
    }
  
    Connection Register(const T_Callback& Callback)
    {
      myInternals->myCallbacks.push_back(
        S_IdenfiedCallback{myInternals->myNextHandleIdentifier++, Callback});
      
      const auto& id = myInternals->myCallbacks.back().myIdentifier;
      return Connection(myInternals,
                        std::bind(&S_SignalInternals::Remove, myInternals.get(), id));
    }

    template<typename std::enable_if<std::is_same<RETURN, void>::value>::type* = nullptr>
    void Notify(ARGS... Args) const
    {
      for (const auto& c : myInternals->myCallbacks)
      {
        c.myCallback(std::forward<ARGS>(Args)...);
      }
    }
    
    template<typename std::enable_if<!std::is_same<RETURN, void>::value>::type* = nullptr>
    std::vector<RETURN>
    Notify(ARGS... Args) const
    {
      std::vector<RETURN> returnValues;
      
      for (const auto& c : myInternals->myCallbacks)
      {
        returnValues.push_back(c.myCallback(std::forward<ARGS>(Args)...));
      }
      
      return returnValues;
    }
  
  private:
    
    struct S_IdenfiedCallback
    {
      T_HandleIdentifier myIdentifier;
      T_Callback myCallback;
    };
    
    struct S_SignalInternals : public I_SignalInternals
    {
      std::vector<S_IdenfiedCallback> myCallbacks;
      T_HandleIdentifier myNextHandleIdentifier;
      
      void Remove(T_HandleIdentifier Id)
      {
        auto found = std::find_if(
          myCallbacks.begin(),
          myCallbacks.end(),
          [&](const S_IdenfiedCallback& C)
          {
            return C.myIdentifier == Id;
          });
            
        if (found != myCallbacks.end())
        {
          myCallbacks.erase(found);
        }
      }
    };
    
    std::shared_ptr<S_SignalInternals> myInternals;
  };
}

#endif