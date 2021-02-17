#include "cbunit.hpp"
#include "cbunit_macros.hpp"
#include "Expect/Traits/New/ExpectRoot.hpp"
#include "Expect/Traits/New/ExpectInteger.hpp"

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
      ::CBUnit::Expect<uint64_t> uint64_t_x(6, __FILE__, __LINE__);
      uint64_t_x.to.be.greaterThan(5);
      uint64_t_x.to.be.at.least(6);
    });
  });
});