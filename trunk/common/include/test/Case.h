#ifndef __TST_CASE_H
#define __TST_CASE_H

#include "test/Dll.h"

#include <functional>

namespace tst
{
  class Dll_tst Case
  {
  public:
  
    template<typename F> Case(const std::string& Name,
                              F Function);
    
    void Run() const;
    
  private:
  
    std::string myName;
    std::function<void()> myTestFunction;
  };
}

template<typename F>
tst::Case::Case(const std::string& Name,
                F Function)
: myName(Name),
  myTestFunction(Function)
{
}

#endif