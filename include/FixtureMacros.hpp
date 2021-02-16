#pragma once

#define CBUNIT_FIXTURE(...)                                                 \
                                                                            \
namespace {                                                                 \
  CBUNIT_FILEINFO                                                           \
  CBUNIT_LINEINFO                                                           \
  ::CBUnit::FixtureDeclaration CBUNIT_CONCAT(_cbunit_fixture, __COUNTER__)(__VA_ARGS__);  \
}