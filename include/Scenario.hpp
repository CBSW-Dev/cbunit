#pragma once

#include "Common.hpp"
#include "TestObject.hpp"

namespace CBUnit
{
  class Scenario: public TestObject
  {
    friend class ScenarioDeclaration;
    friend class TestRunner;
  private:
    Scenario(const char* name, RunFunction function, const char* filename, uint32_t lineNumber);

    void run();
  };

  class ScenarioDeclaration
  {
  public:
    ScenarioDeclaration(const char* name, RunFunction function);
  };
}