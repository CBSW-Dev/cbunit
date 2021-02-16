#include "Reporters/DotTestReporter.hpp"

namespace CBUnit
{
  DotTestReporter::DotTestReporter(OutputStream& ostream):
    _ostream(ostream)
  {}

  void DotTestReporter::begin() 
  {
     _ostream << "\r\n";
  }

  void DotTestReporter::beginFixture(Fixture& fixture) {}

  void DotTestReporter::endFixture(Fixture& fixture) {}

  void DotTestReporter::beginGroup(Group& group) {}

  void DotTestReporter::endGroup(Group& group) {}

  void DotTestReporter::beginScenario(Scenario& scenario) {}
  
  void DotTestReporter::passScenario(Scenario& scenario) 
  {
    _ostream << _ostream.green << "."  << _ostream.reset;
  }

  void DotTestReporter::failScenario(Scenario& scenario, const TestError& error) 
  {
    _ostream << _ostream.red << "."  << _ostream.reset;
  }

  void DotTestReporter::end(const TestStatistics& statistics) 
  {
    _ostream << "\r\n\r\n";
  }
}