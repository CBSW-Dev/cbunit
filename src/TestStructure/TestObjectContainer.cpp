#include "TestStructure/TestObjectContainer.hpp"

namespace CBUnit
{
  TestObjectContainer::TestObjectContainer(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, function, filename, lineNumber)
  {}

  void TestObjectContainer::addObject(TestObject* testObject)
  {
    _objects.push_back(testObject);
  }
    
  void TestObjectContainer::setBeforeEach(BeforeEach* beforeEach)
  {
    _beforeEach = beforeEach;
  }

  void TestObjectContainer::setAfterEach(AfterEach* afterEach)
  {
    _afterEach = afterEach;
  }
}