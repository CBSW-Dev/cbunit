#pragma once

#include "FinalisingTestReporter.hpp"

namespace CBUnit
{
  class DotTestReporter: public FinalisingTestReporter
  {
  public:
    DotTestReporter(OutputStream& ostream);
    void begin() override;
    void beginFixture(Fixture& fixture) override;
    void endFixture(Fixture& fixture) override;
    void beginScenario(Scenario& scenario) override;
    void passScenario(Scenario& scenario) override;
    void skipScenario(Scenario& scenario) override;
    void failScenario(Scenario& scenario, const TestError& error) override;
    void end(const TestStatistics& statistics) override;
  };
}