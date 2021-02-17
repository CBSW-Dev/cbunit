#include "Application/Settings.hpp"
#include "Application/InvalidArgumentValueError.hpp"
namespace CBUnit
{
  namespace
  {
    std::list<std::string> validReporters = {"", "spec", "min", "dot"};
    std::list<std::string> validOutputStreams = {"", "ansi8", "ansi16", "ansi256"};
  }

  void Settings::validate()
  {
    auto itReporter = std::find(validReporters.begin(), validReporters.end(), reporter);
    if (itReporter == validReporters.end())
    {
      throw InvalidArgumentValueError{"--reporter", reporter};
    }

    auto itOutput = std::find(validOutputStreams.begin(), validOutputStreams.end(), output);
    if (itOutput == validOutputStreams.end())
    {
      throw InvalidArgumentValueError{"--output", output};
    }
  }
}