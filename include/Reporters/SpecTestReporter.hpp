#pragma once

#include "TestReporter.hpp"

#include "OutputStreams/OutputStream.hpp"


namespace CBUnit
{
  class SpecTestReporter: public TestReporter
  {
  public:
    SpecTestReporter(OutputStream& ostream);
    void begin() override;
    void beginFixture(Fixture& fixture) override;
    void endFixture(Fixture& fixture) override;
    void beginGroup(Group& group) override;
    void endGroup(Group& group) override;
    void beginScenario(Scenario& scenario) override;
    void passScenario(Scenario& scenario) override;
    void skipScenario(Scenario& scenario) override;
    void failScenario(Scenario& scenario, const TestError& error) override;
    void end(const TestStatistics& statistics) override;
  private:
    void printTabs();
    OutputStream& _ostream;
    uint32_t _depth = 0;
    uint32_t _failureCount = 0;
  };
}