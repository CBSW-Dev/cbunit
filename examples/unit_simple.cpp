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
      const char* cstring = "Hello";
      std::string string = "Hello";
      
      expect(cstring).string.to.contain("el");
      expect(string).length.to.equal(5);
      expect(cstring).size.to.equal(sizeof(void*));
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