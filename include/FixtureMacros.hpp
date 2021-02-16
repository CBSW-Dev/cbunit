#pragma once

#define CBUNIT_FIXTURE(FixtureName, TestFunction)                           \
                                                                            \
namespace {                                                                 \
  CBUNIT_FILEINFO                                                           \
  CBUNIT_LINEINFO                                                           \
  ::CBUnit::FixtureDeclaration CBUNIT_CONCAT(_cbunit_fixture, __COUNTER__)(FixtureName, TestFunction);  \
}