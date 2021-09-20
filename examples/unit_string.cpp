#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("String") {
  scenario("should have the equals language chain") {
    std::string string = "Banana";
    expect(string).to.equal("Banana"); //pass
    expect(string).to.equal("Orange"); //fail
  }

  scenario("should have the not equals language chain") {
    std::string string = "Banana";
    expect(string).not.to.equal("Orange"); //pass
    expect(string).not.to.equal("Banana"); //fail
  }

  scenario("should have the contain language chain") {
    std::string string = "Banana";
    expect(string).to.contain("nan"); //pass
    expect(string).to.contain("cat"); //fail
  }

  scenario("should have the length language chain") {
    std::string string = "Banana";
    expect(string).length.to.equal(6); //pass
    expect(string).length.to.equal(5); //fail
  }
}