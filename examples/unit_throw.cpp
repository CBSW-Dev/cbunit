#include "cbunit.hpp"
#include "cbunit_macros.hpp"

void testFunction()
{
  throw std::string("ABCDEFG");
}

fixture("Throw") {
  scenario("should throw the error") {
    expect([]() {
      testFunction();
    }).to.throwException<std::string>(); //pass

    expect([]() {
      testFunction();
    }).to.throwException<int>(); //false
  }

  scenario("should not throw the error") {
    expect([]() {
      testFunction();
    }).not.to.throwException<int>(); //pass

    expect([]() {
      testFunction();
    }).not.to.throwException<std::string>(); //false
  }

   scenario("should throw the error with an error check") {
    expect([]() {
      testFunction();
    }).to.throwException<std::string>([](const std::string& error) {
      expect(error).to.equal("ABCDEFG");
    }); //pass

    expect([]() {
      testFunction();
    }).to.throwException<std::string>([](const std::string& error) {
      expect(error).to.equal("123");
    }); //fail
  }
}