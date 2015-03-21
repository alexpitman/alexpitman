#ifndef __TST_FAILED_ASSERTION_H
#define __TST_FAILED_ASSERTION_H

#include "test/Dll.h"

#include <string>

namespace tst
{
  class Dll_tst FailedAssertion
  {
  public:
  
    FailedAssertion(int Line, const std::string& File, const std::string& Expression)
    : myLine(Line), myFile(File), myExpression(Expression) {}
  
    FailedAssertion(int Line, std::string&& File, std::string&& Expression)
    : myLine(Line), myFile(std::move(File)), myExpression(std::move(Expression)) {}
    
    std::string ToString() const
    {
      return myFile + "\nLine: " + std::to_string(myLine) + "\n" + myExpression;
    }
    
  private:
    int myLine;
    std::string myFile;
    std::string myExpression;
  };
}

#endif