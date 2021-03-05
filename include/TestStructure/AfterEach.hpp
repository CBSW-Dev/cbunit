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
    void run() override;
  private:
    AfterEach(RunFunction function, const char* filename, uint32_t lineNumber);
  };

  class AfterEachDeclaration
  {
  public:
   AfterEachDeclaration(RunFunction function);
  };
}