#pragma once

#define CBUNIT_FIXTURE(...)                                                                             \
                                                                                                        \
static ::CBUnit::Fixture::ScenarioList _cbunit_fixture_scenarios;                                       \
static ::CBUnit::BeforeEach* _cbunit_fixture_beforeEach = nullptr;                                      \
static ::CBUnit::AfterEach* _cbunit_fixture_afterEach = nullptr;                                        \
static ::CBUnit::Fixture _cbunit_fixture( __VA_ARGS__,                                                  \
                                          _cbunit_fixture_scenarios,                                    \
                                          _cbunit_fixture_beforeEach,                                   \
                                          _cbunit_fixture_afterEach,                                    \
                                          __FILE__,                                                     \
                                          __LINE__                                                      \
                                        );                                                              \
namespace Scenarios
