#pragma once

#include "TestStructure/FixtureMacros.hpp"
#include "TestStructure/ScenarioMacros.hpp"
#include "TestStructure/BeforeEachMacros.hpp"
#include "TestStructure/AfterEachMacros.hpp"
#include "TestStructure/TestErrorMacros.hpp"
#include "Expect/ExpectMacros.hpp"

#define fixture                           CBUNIT_FIXTURE
#define scenario                          CBUNIT_SCENARIO
#define beforeEach                        CBUNIT_BEFORE_EACH
#define afterEach                         CBUNIT_AFTER_EACH
#define failTest                          CBUNIT_FAIL_TEST
#define skipTest                          ::CBUnit::TestAttributes::Skip
#define expect                            CBUNIT_EXPECT