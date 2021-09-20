#pragma once

#define CBUNIT_BEFORE_EACH                                                                          \
                                                                                                    \
namespace CBUnit                                                                                    \
{                                                                                                   \
  namespace {                                                                                       \
    class BeforeEachDeclaration                                                                     \
    {                                                                                               \
    public:                                                                                         \
      BeforeEachDeclaration(::CBUnit::BeforeEach& object) {_cbunit_fixture_beforeEach = &object;}   \
    };                                                                                              \
  }                                                                                                 \
}                                                                                                   \
                                                                                                    \
static void _cbunit_beforeEachFunction();                                                           \
::CBUnit::BeforeEach _cbunit_beforeEach(_cbunit_beforeEachFunction, __FILE__, __LINE__);            \
::CBUnit::BeforeEachDeclaration _cbunit_beforeEachDeclaration(_cbunit_beforeEach);                  \
static void _cbunit_beforeEachFunction
