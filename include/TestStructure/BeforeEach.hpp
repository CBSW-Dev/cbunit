#pragma once

#include "Common.hpp"
#include "TestObject.hpp"

namespace CBUnit
{
  class BeforeEach: public TestObject
  {
    friend class BeforeEachDeclaration;
    friend class TestRunner;
  public:
    BeforeEach(RunFunction function, const char* filename, uint32_t lineNumber);

    void run() override;
  private:
    RunFunction _function;
  };
}