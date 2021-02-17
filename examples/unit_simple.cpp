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
      //expect(0).to.be.at.least(1);
      uint32_t x = 7;
      expect(x).to.equal(5);
      expect(x).to.be.greaterThan(5);
      expect(x).to.be.greaterThanOrEqual(5);
      expect(x).to.be.lessThan(5);
      expect(x).to.be.lessThanOrEqual(5);
      expect(x).to.be.at.least(7);
      expect(x).to.be.at.most(7);
    });
  });
});