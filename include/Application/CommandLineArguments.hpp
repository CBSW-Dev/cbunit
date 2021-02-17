#pragma once

#include "Settings.hpp"

namespace CBUnit
{
  class CommandLineArguments
  {
  public:
    static Settings parse(int argc, const char** argv);
  private:
    using CommandLineArgumentFunction = void(*)(int&, const char**, Settings&);
    using ArgumentsMap = std::map<std::string, CommandLineArgumentFunction>;
    static ArgumentsMap argumentsMap;
    static void parseReporter(int& argc, const char** argv, Settings& settings);
    static void parseOutput(int& argc, const char** argv, Settings& settings);
  };
}