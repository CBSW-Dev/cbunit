#include "main.hpp"
#include "TestStructureError.hpp"
#include <iostream>

int main()
{
  int result = -1;
  try 
  {
    result = testMain(::CBUnit::TestRunner::instance());
  }
  catch (const ::CBUnit::TestStructureError& error)
  {
    std::cout << error.message() << "\r\n  at " << error.filename() << ":" << error.lineNumber() << std::endl;
  }
  return result;
}