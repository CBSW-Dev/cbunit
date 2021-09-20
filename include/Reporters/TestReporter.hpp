#pragma once

#include "TestStructure/Fixture.hpp"
#include "TestStructure/Scenario.hpp"
#include "TestStructure/TestStatistics.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  class TestReporter
  {
  public:
    virtual ~TestReporter();
    virtual void begin() = 0;
    virtual void beginFixture(Fixture& fixture) = 0;
    virtual void endFixture(Fixture& fixture) = 0;
    virtual void beginScenario(Scenario& scenario) = 0;
    virtual void passScenario(Scenario& scenario) = 0;
    virtual void skipScenario(Scenario& scenario) = 0;
    virtual void failScenario(Scenario& scenario, const TestError& error) = 0;
    virtual void end(const TestStatistics& statistics) = 0;
  };
}