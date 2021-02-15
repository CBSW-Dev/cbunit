#include "TestStructureError.hpp"

namespace CBUnit
{
  TestStructureError::TestStructureError(const std::string& message, const char* filename, uint32_t lineNumber):
    _message(message),
    _filename(filename),
    _lineNumber(lineNumber)
  {}

  const std::string& TestStructureError::message() const
  {
    return _message;
  }

  const char* TestStructureError::filename() const
  {
    return _filename;
  }
    
  uint32_t TestStructureError::lineNumber() const
  {
    return _lineNumber;
  }
}