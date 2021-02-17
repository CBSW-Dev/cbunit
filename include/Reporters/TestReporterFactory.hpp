#pragma once

#include "TestReporter.hpp"
#include "OutputStreams/OutputStream.hpp"

namespace CBUnit
{
  class TestReporterFactory
  {
  public:
    static TestReporter* createTestReporter(const std::string& reporterName, OutputStream& outputStream);
  };
}