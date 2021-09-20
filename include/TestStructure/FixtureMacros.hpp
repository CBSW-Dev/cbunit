#pragma once

#define CBUNIT_FIXTURE_NAME(id) CBUNIT_CONCAT(_cbunit_fixture, id)
#define CBUNIT_FIXTURE_DECLARATION(id) CBUNIT_CONCAT(_cbunit_fixture_declaration, id)

#define _CBUNIT_FIXTURE(id, ...)                                                                        \
                                                                                                        \
static ::CBUnit::Fixture CBUNIT_FIXTURE_NAME(id)( __VA_ARGS__,                                          \
                                          __FILE__,                                                     \
                                          __LINE__                                                      \
                                        );                                                              \
                                                                                                        \
static ::CBUnit::FixtureDeclaration CBUNIT_FIXTURE_DECLARATION(id)(&CBUNIT_FIXTURE_NAME(id));           \
namespace Scenarios


#define CBUNIT_FIXTURE(...) _CBUNIT_FIXTURE(__COUNTER__, __VA_ARGS__)