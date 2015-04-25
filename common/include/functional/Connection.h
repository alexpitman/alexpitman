#ifndef __FUNCTIONAL_CONNECTION_H
#define __FUNCTIONAL_CONNECTION_H

#include "types.h"

#include <functional>
#include <memory>

namespace fun
{
  class I_SignalInternals;

  class Connection
  {
  public:
    // Default (null) connection.
    Connection() = default;

    // No copy (move only).
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

    // Default move operations.
    Connection(Connection&&) = default;
    Connection& operator=(Connection&&) = default;
    
    // Construct a connection.
    Connection(std::shared_ptr<I_SignalInternals> Internals,
               std::function<void()>&& RemoveFunction)
    : mySignalInternals(Internals),
      myRemoveFunction(std::move(RemoveFunction))
    {
    }
    
    ~Connection()
    {
      auto ptr = mySignalInternals.lock();
      if (ptr)
      {
        myRemoveFunction();
      }
    }
    
  private:
    std::weak_ptr<I_SignalInternals> mySignalInternals;
    std::function<void()> myRemoveFunction;
    
    template<typename KEY, typename RETURN, typename... ARGS>
    friend class SignalMap;
  };
}

#endif