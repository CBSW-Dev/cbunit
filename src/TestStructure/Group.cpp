#include "TestStructure/Group.hpp"
#include "TestStructure/TestRunner.hpp"
#include "TestStructure/FileInfo.hpp"
#include "TestStructure/LineInfo.hpp"


namespace CBUnit
{
  Group::Group(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, function, filename, lineNumber)
  {}

  void Group::run()
  {
    _function();
  }

  GroupDeclaration::GroupDeclaration(const char* name, RunFunction function)
  {
    TestRunner::instance().addGroup(new Group(name, {}, function, FileInfo::file, LineInfo::line));
  }

  GroupDeclaration::GroupDeclaration(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function)
  {
    
    TestRunner::instance().addGroup(new Group(name, attributes, function, FileInfo::file, LineInfo::line));
  }
}