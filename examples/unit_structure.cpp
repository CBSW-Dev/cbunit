#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("This is an empty fixture") {
}

fixture("This is a fixture containing scenarios") {
  scenario("this is a passing scenario") {
    expect(1).to.equal(1); //pass
  }

  scenario("this is a failing scenario") {
    expect(1).to.equal(0); //fail
  }
}


fixture("This is a fixture containing before each and after each") {
  beforeEach() {
    std::cout << "Running Before Each\r\n";
  }

  afterEach() {
    std::cout << "Running After Each\r\n";
  }

  scenario("this is a scenario") {
    expect(1).to.equal(1); //pass
  }

   scenario("this is another scenario") {
    expect(1).to.equal(1); //pass
  }
}