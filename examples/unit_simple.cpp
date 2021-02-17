#include "cbunit.hpp"
#include "cbunit_macros.hpp"

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
      expect(1).to.equal(0);
      expect(1).to.be.above(0);
    });
  });
});