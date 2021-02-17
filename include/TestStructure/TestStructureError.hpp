#pragma once

#include "Common.hpp"

namespace CBUnit
{
  class TestStructureError
  {
  public:
    TestStructureError(const std::string& message, const char* filename, uint32_t lineNumber);

    const std::string& message() const;
    const char* filename() const;
    uint32_t lineNumber() const;
  private:
    std::string _message;
    const char* _filename;
    uint32_t _lineNumber;
  };
}