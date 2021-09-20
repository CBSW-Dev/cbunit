#pragma once

#include "Common.hpp"
#include "TestObject.hpp"

namespace CBUnit
{
  class Fixture;

  class Scenario: public TestObject
  {
    friend class Fixture;
    friend class TestRunner;
  public:
    Scenario(Fixture& fixture, const char* name, RunFunction function, const char* filename, uint32_t lineNumber);
    Scenario(Fixture& fixture, const char* name, TestAttributes attributes, RunFunction function, const char* filename, uint32_t lineNumber);
    Scenario(Fixture& fixture, const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber);

    void run() override;
  private:
    RunFunction _function;
  };
}