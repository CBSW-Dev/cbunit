#include "Application/main.hpp"
#include "Application/CommandLineArguments.hpp"
#include "Application/InvalidArgumentError.hpp"
#include "Application/InvalidArgumentValueError.hpp"
#include "TestStructure/TestStructureError.hpp"
#include "OutputStreams/OutputStreamFactory.hpp"
#include "Reporters/TestReporterFactory.hpp"
#include <iostream>

int main(int argc, char** argv)
{
  int result = EXIT_FAILURE;
  ::CBUnit::TestReporter* reporter = nullptr;
  ::CBUnit::OutputStream* output = nullptr;
  try 
  {
    ::CBUnit::Settings settings = ::CBUnit::CommandLineArguments::parse(argc, const_cast<const char**>(argv));
    settings.validate();
    output = ::CBUnit::OutputStreamFactory::createOutputStream(settings.output);
    reporter = ::CBUnit::TestReporterFactory::createTestReporter(settings.reporter, *output);
    ::CBUnit::TestRunner::instance().setReporter(*reporter);
    result = testMain(::CBUnit::TestRunner::instance());
  }
  catch (const ::CBUnit::InvalidArgumentError& error)
  {
    std::cout << "Invalid argument: " << error.argument << std::endl;
  }
  catch (const ::CBUnit::InvalidArgumentValueError& error)
  {
    std::cout << "Argument " << error.argument << " has invalid value " << error.value << std::endl;
  }
  catch (const ::CBUnit::TestStructureError& error)
  {
    std::cout << error.message() << "\r\n  at " << error.filename() << ":" << error.lineNumber() << std::endl;
  }
  delete reporter;
  delete output;
  return result;
}