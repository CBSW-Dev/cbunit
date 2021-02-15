#include "cbunit.hpp"
#include "cbunit_macros.hpp"

#include <iostream>

fixture("Simple Test", []() {
  group("Simple Group", []() {
    group("Nested Group", []() {
      scenario("Simple Scenario 1", []() {
        std::cout << "This is the test"<< std::endl;
      });
    });
  });

  scenario("Fixture Scenario", []() {
    std::cout << "This is the test"<< std::endl;
  });

  group("Second Group", []() {
    scenario("Simple Scenario 2", []() {
      std::cout << "This is the test"<< std::endl;
    });
  });
});

scenario("Failing Scenario", []() {
  std::cout << "This is the test"<< std::endl;
});