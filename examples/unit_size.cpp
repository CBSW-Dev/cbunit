#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Size") {
  scenario("should have the size language chain") {
    uint32_t value;
    expect(value).size.to.equal(4); //pass
    expect(value).size.to.equal(9); //fail
  }

  scenario("should have the size language chain for different types") {
    void* value;
    expect(value).size.to.equal(sizeof(void*)); //pass
    expect(value).size.to.equal(9); //fail
  }
}