#pragma once

#include "FinalisingTestReporter.hpp"

namespace CBUnit
{
  class MinTestReporter: public FinalisingTestReporter
  {
  public:
    MinTestReporter(OutputStream& ostream);
    void begin() override;
    void beginFixture(Fixture& fixture) override;
    void endFixture(Fixture& fixture) override;
    void beginGroup(Group& group) override;
    void endGroup(Group& group) override;
    void beginScenario(Scenario& scenario) override;
    void passScenario(Scenario& scenario) override;
    void skipScenario(Scenario& scenario) override;
    void failScenario(Scenario& scenario, const TestError& error) override;
  };
}