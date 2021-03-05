#include "TestStructure/Fixture.hpp"
#include "TestStructure/TestRunner.hpp"
#include "TestStructure/FileInfo.hpp"
#include "TestStructure/LineInfo.hpp"

namespace CBUnit
{
  Fixture::Fixture(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObjectContainer(name, attributes, function, filename, lineNumber)
  {}

  void Fixture::run()
  {
    _function();

    for (auto object: _objects)
    {
      if (_beforeEach)
      {
        _beforeEach->run();
      }
      object->run();
      if (_afterEach)
      {
        _afterEach->run();
      }
      delete object;
    }
    delete _beforeEach;
    delete _afterEach;

  }

  FixtureDeclaration::FixtureDeclaration(const char* name, RunFunction function)
  {
    TestRunner::instance().addFixture(new Fixture(name, {}, function, FileInfo::file, LineInfo::line));
  }

  FixtureDeclaration::FixtureDeclaration(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function)
  {
    TestRunner::instance().addFixture(new Fixture(name, attributes, function, FileInfo::file, LineInfo::line));
  }
}