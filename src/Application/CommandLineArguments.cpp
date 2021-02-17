#include "Application/CommandLineArguments.hpp"
#include "Application/InvalidArgumentError.hpp"
namespace CBUnit
{

  CommandLineArguments::ArgumentsMap CommandLineArguments::argumentsMap =
  {
    {"--reporter", &CommandLineArguments::parseReporter},
    {"--output", &CommandLineArguments::parseOutput}
  };

  Settings CommandLineArguments::parse(int argc, const char** argv)
  {
    Settings settings;
    for (int i = 1; i < argc; ++i)
    {
      std::string argument = argv[i];
      ArgumentsMap::const_iterator it= argumentsMap.find(argument);
      if (it == argumentsMap.end())
      {
        throw InvalidArgumentError{argument};
      }
      else
      {
        it->second(i, argv, settings);
      }
    }
    return settings;
  }

  void CommandLineArguments::parseReporter(int& argc, const char** argv, Settings& settings)
  {
    settings.reporter = argv[++argc];
  }

  void CommandLineArguments::parseOutput(int& argc, const char** argv, Settings& settings)
  {
    settings.output = argv[++argc];
  }
}