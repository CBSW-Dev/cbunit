
#include "Reporters/TestReporterFactory.hpp"
#include "Reporters/DotTestReporter.hpp"
#include "Reporters/MinTestReporter.hpp"
#include "Reporters/SpecTestReporter.hpp"

namespace CBUnit
{
  TestReporter* TestReporterFactory::createTestReporter(const std::string& reporterName, OutputStream& outputStream)
  {
     if (reporterName == "dot")
    {
      return new DotTestReporter(outputStream);
    }
    else if (reporterName == "min")
    {
      return new MinTestReporter(outputStream);
    }
    else
    {
      return new SpecTestReporter(outputStream);
    }
  }
}
