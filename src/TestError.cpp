#include "TestError.hpp"

namespace CBUnit
{
  TestError::TestError(const std::string& message, const char* filename, uint32_t lineNumber):
    _message(message),
    _filename(filename),
    _lineNumber(lineNumber)
  {}

  const std::string& TestError::message() const
  {
    return _message;
  }

  const char* TestError::filename() const
  {
    return _filename;
  }

  uint32_t TestError::lineNumber() const
  {
    return _lineNumber;
  }
}