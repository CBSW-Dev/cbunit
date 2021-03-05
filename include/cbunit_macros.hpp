#pragma once

#include "TestStructure/FixtureMacros.hpp"
#include "TestStructure/GroupMacros.hpp"
#include "TestStructure/ScenarioMacros.hpp"
#include "TestStructure/BeforeEachMacros.hpp"
#include "TestStructure/AfterEachMacros.hpp"
#include "TestStructure/TestErrorMacros.hpp"
#include "Expect/ExpectMacros.hpp"

#define fixture(...)                      CBUNIT_FIXTURE(__VA_ARGS__)
#define group(...)                        CBUNIT_GROUP(__VA_ARGS__)
#define scenario(...)                     CBUNIT_SCENARIO(__VA_ARGS__)
#define beforeEach(...)                   CBUNIT_BEFORE_EACH(__VA_ARGS__)
#define afterEach(...)                    CBUNIT_AFTER_EACH(__VA_ARGS__)
#define failTest(...)                     CBUNIT_FAIL_TEST(__VA_ARGS__)
#define skipTest                          ::CBUnit::TestAttributes::Skip
#define expect                            CBUNIT_EXPECT