#pragma once

#include "TestReporter.hpp"

#include "OutputStreams/OutputStream.hpp"


namespace CBUnit
{
  class DotTestReporter: public TestReporter
  {
  public:
    DotTestReporter(OutputStream& ostream);
    void begin() override;
    void beginFixture(Fixture& fixture) override;
    void endFixture(Fixture& fixture) override;
    void beginGroup(Group& group) override;
    void endGroup(Group& group) override;
    void beginScenario(Scenario& scenario) override;
    void passScenario(Scenario& scenario) override;
    void failScenario(Scenario& scenario) override;
    void end(const TestStatistics& statistics) override;
  private:
    OutputStream& _ostream;
  };
}