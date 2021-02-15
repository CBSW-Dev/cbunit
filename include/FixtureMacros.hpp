#pragma once

#define CBUNIT_FIXTURE(FixtureName, TestFunction)                           \
                                                                            \
namespace {                                                                 \
  CBUNIT_FILEINFO                                                           \
  CBUNIT_LINEINFO                                                           \
  ::CBUnit::FixtureDeclaration _cbunit_fixture(FixtureName, TestFunction);  \
}