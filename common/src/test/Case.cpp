#include "test/Case.h"

#include "test/FailedAssertion.h"

#include <windows.h>

#include <iostream>
#include <string>

void tst::Case::Run() const
{
  auto outputHandle = ::GetStdHandle(STD_OUTPUT_HANDLE);
  
  CONSOLE_SCREEN_BUFFER_INFO info;
  ::GetConsoleScreenBufferInfo(outputHandle, &info);
  
  std::string failReason;
  
  try
  {
    myTestFunction();

    ::SetConsoleTextAttribute(outputHandle, FOREGROUND_GREEN);
    std::cout << "  PASSED";
  }
  catch (const tst::FailedAssertion& Exception)
  {
    failReason = Exception.ToString();
  
    ::SetConsoleTextAttribute(outputHandle, FOREGROUND_RED);
    std::cout << "  FAILED";
  }
  ::SetConsoleTextAttribute(outputHandle, info.wAttributes);
  
  std::cout << " : " << myName << std::endl;
  
  if (!failReason.empty())
  {
    std::cout << std::endl << failReason << std::endl << std::endl;
  }
}
