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
      double y = 90.1;
      std::string str = "abcef";
      // expect(x).to.equal(5);
      // expect(x).to.be.greaterThan(5);
      // expect(x).to.be.greaterThanOrEqual(5);
      // expect(x).to.be.lessThan(5);
      // expect(x).to.be.lessThanOrEqual(5);
      // expect(x).to.be.at.least(7);
      // expect(x).to.be.at.most(7);
      bool z;
      void* otherptr;
      void* ptr = otherptr;
      expect(ptr).to.be.null();
      expect(y).to.be.within(0.11).of(90.0);
      //expect(z).to.equal(true);
      expect(str).to.contain("bce");
    });
  });
});


class Calculator
{
public:
  int add(int x, int y)
  {
    return x+y;
  }
};

fixture("Calculator", []() {
  scenario("should add two integers", []() {
    Calculator calculator;
    expect(calculator.add(5, 7)).to.equal(12);
  });
});