#pragma once

#include "Common.hpp"
#include "TestObject.hpp"

namespace CBUnit
{
  class AfterEach: public TestObject
  {
    friend class AfterEachDeclaration;
    friend class TestRunner;
  public:
    AfterEach(RunFunction function, const char* filename, uint32_t lineNumber);
    void run() override;
  private:
    RunFunction _function;
  };
}