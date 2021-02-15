#include "Group.hpp"
#include "TestRunner.hpp"
#include "FileInfo.hpp"
#include "LineInfo.hpp"

#include <iostream>

namespace CBUnit
{
  Group::Group(const char* name, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, function, filename, lineNumber)
  {}

  void Group::run()
  {
    std::cout << "Running Group: " << _name << std::endl;

    _function();
  }

  GroupDeclaration::GroupDeclaration(const char* name, RunFunction function)
  {
    TestRunner::instance().addGroup(new Group(name, function, FileInfo::file, LineInfo::line));
  }
}