#include "Reporters/MinTestReporter.hpp"

namespace CBUnit
{
  MinTestReporter::MinTestReporter(OutputStream& ostream):
    FinalisingTestReporter(ostream)
  {}

  void MinTestReporter::begin() {}
  
  void MinTestReporter::beginFixture(Fixture& fixture) {}

  void MinTestReporter::endFixture(Fixture& fixture) {}

  void MinTestReporter::beginGroup(Group& group) {}

  void MinTestReporter::endGroup(Group& group) {}

  void MinTestReporter::beginScenario(Scenario& scenario) {}
  
  void MinTestReporter::passScenario(Scenario& scenario) {}

  void MinTestReporter::skipScenario(Scenario& scenario)  {}

  void MinTestReporter::failScenario(Scenario& scenario, const TestError& error) {}
}