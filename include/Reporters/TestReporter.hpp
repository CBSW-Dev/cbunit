#pragma once

#include "Fixture.hpp"
#include "Group.hpp"
#include "Scenario.hpp"
#include "TestStatistics.hpp"

namespace CBUnit
{
  class TestReporter
  {
  public:
    virtual ~TestReporter();
    virtual void begin() = 0;
    virtual void beginFixture(Fixture& fixture) = 0;
    virtual void endFixture(Fixture& fixture) = 0;
    virtual void beginGroup(Group& group) =0 ;
    virtual void endGroup(Group& group) = 0;
    virtual void beginScenario(Scenario& scenario) = 0;
    virtual void passScenario(Scenario& scenario) = 0;
    virtual void failScenario(Scenario& scenario) = 0;
    virtual void end(const TestStatistics& statistics) = 0;
  };
}