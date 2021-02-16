#include "cbunit.hpp"
#include "cbunit_macros.hpp"

#include <iostream>

fixture("Simple Fixture", []() {
  group("Simple Group", []() {
    group("Nested Group", []() {
      scenario("Simple Scenario 1", []() {
        
      });
    });
  });

  scenario("Fixture Scenario", []() {
  
  });

  group("Second Group", []() {
    scenario("Simple Scenario 2", []() {
      failTest("This is a test failure");
    });
  });
});


fixture("Calculator", []() {
  scenario("should add two numbers", []() {
      
  });
});
