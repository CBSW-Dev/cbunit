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
    void run() override;
  private:
    BeforeEach(RunFunction function, const char* filename, uint32_t lineNumber);
  };

  class BeforeEachDeclaration
  {
  public:
    BeforeEachDeclaration(RunFunction function);
  };
}