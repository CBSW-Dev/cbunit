#include "Reporters/FinalisingTestReporter.hpp"

namespace CBUnit
{
  FinalisingTestReporter::FinalisingTestReporter(OutputStream& ostream):
    _ostream(ostream)
  {}

  void FinalisingTestReporter::end(const TestStatistics& statistics)
  {
    _ostream << "\r\n";

    if (statistics.skipCount() != 0)
    {
      _ostream << _ostream.darkGrey << statistics.skipCount() << " skipped\r\n";
    }
    uint32_t totalRunCount = statistics.passCount() + statistics.failureCount();
    if (statistics.failures().empty())
    {
      _ostream << _ostream.green << totalRunCount << " complete "
            << _ostream.reset << "(" << statistics.millisecondsElapsed() << "ms)\r\n\r\n";
    }
    else
    {
      _ostream << _ostream.red << statistics.failures().size() << " of " << totalRunCount << " failed "
            << _ostream.reset << "(" << statistics.millisecondsElapsed() << "ms)\r\n\r\n";

      uint32_t i = 0;
      for (auto failure: statistics.failures())
      {
        _ostream << i++ << ") " << failure.scenario << ": " << _ostream.red << failure.error.message()
            << _ostream.darkGrey << "\r\n  at " << failure.error.filename() << ":" << failure.error.lineNumber() << _ostream.reset << "\r\n\r\n";
      }
    }
  }
}