#pragma once

#include "FixtureMacros.hpp"
#include "GroupMacros.hpp"
#include "ScenarioMacros.hpp"
#include "TestErrorMacros.hpp"

#define fixture(...)                      CBUNIT_FIXTURE(__VA_ARGS__)
#define group(...)                        CBUNIT_GROUP(__VA_ARGS__)
#define scenario(...)                     CBUNIT_SCENARIO(__VA_ARGS__)
#define failTest(...)                     CBUNIT_FAIL_TEST(__VA_ARGS__)
#define skipTest                          ::CBUnit::TestAttributes::Skip