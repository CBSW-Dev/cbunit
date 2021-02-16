#include "Reporters/SpecTestReporter.hpp"

namespace CBUnit
{
  SpecTestReporter::SpecTestReporter(OutputStream& ostream):
    _ostream(ostream)
  {}

  void SpecTestReporter::begin() 
  {
     _ostream << "\r\n";
  }

  void SpecTestReporter::beginFixture(Fixture& fixture) 
  {
    _ostream << fixture.name() << "\r\n";
  }

  void SpecTestReporter::endFixture(Fixture& fixture) {}

  void SpecTestReporter::beginGroup(Group& group) 
  {
    ++_depth;
    printTabs();
    _ostream << group.name() << "\r\n";
  }

  void SpecTestReporter::endGroup(Group& group) 
  {
    --_depth;
  }

  void SpecTestReporter::beginScenario(Scenario& scenario) 
  {
    ++_depth;
  }
  
  void SpecTestReporter::passScenario(Scenario& scenario) 
  {
    printTabs();
    _ostream << _ostream.green << scenario.name() << _ostream.reset << "\r\n";
    --_depth;
  }

  void SpecTestReporter::failScenario(Scenario& scenario) 
  {
    printTabs();
    _ostream << _ostream.red << scenario.name() << _ostream.reset << "\r\n";
    --_depth;
  }

  void SpecTestReporter::end(const TestStatistics& statistics)
  {
    _ostream << "\r\n\r\n";

    _ostream << statistics.passes() << " Complete (" << statistics.millisecondsElapsed() << "ms)\r\n\r\n";
  }

  void SpecTestReporter::printTabs()
  {
    static constexpr const char* tab = "  "; 
    for (uint32_t i = 0; i < _depth; ++i)
    {
      _ostream << tab;
    }
  }
}