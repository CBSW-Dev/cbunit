#pragma once

#include "TestReporter.hpp"

#include "OutputStreams/OutputStream.hpp"

namespace CBUnit
{
  class FinalisingTestReporter: public TestReporter
  {
  public:
    FinalisingTestReporter(OutputStream& ostream);
    void end(const TestStatistics& statistics) override;
  protected:
    OutputStream& _ostream;
  };
}