#pragma once

#include "TestObject.hpp"
#include "TestAttributes.hpp"
#include "BeforeEach.hpp"
#include "AfterEach.hpp"

namespace CBUnit
{
  class TestObjectContainer: public TestObject
  {
  public:
    void addObject(TestObject* testObject);
    void setBeforeEach(BeforeEach* beforeEach);
    void setAfterEach(AfterEach* afterEach);
  protected:
    TestObjectContainer(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber);
  protected:
    using Objects = std::list<TestObject*>;
    Objects _objects;

    BeforeEach* _beforeEach = nullptr;
    AfterEach* _afterEach = nullptr;
  };
}