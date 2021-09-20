#pragma once

#define CBUNIT_SCENARIO_NAME(id) CBUNIT_CONCAT(_cbunit_scenario_, id)
#define CBUNIT_SCENARIO_FUNC(id) CBUNIT_CONCAT(_cbunit_scenario_function_, id)

#define _CBUNIT_SCENARIO(id,...)                                                                                  \
                                                                                                                  \
static void CBUNIT_SCENARIO_FUNC(id)();                                                                           \
static ::CBUnit::Scenario CBUNIT_SCENARIO_NAME(id)( ::CBUnit::Fixture::instance,                                  \
                                                    __VA_ARGS__,                                                  \
                                                    &CBUNIT_SCENARIO_FUNC(id),                                    \
                                                    __FILE__,                                                     \
                                                    __LINE__                                                      \
                                                  );                                                              \
static void CBUNIT_SCENARIO_FUNC(id)()

#define CBUNIT_SCENARIO(...) _CBUNIT_SCENARIO(__COUNTER__, __VA_ARGS__)
