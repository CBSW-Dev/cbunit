#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Boolean", []() {
  scenario("should have the equals language chain", []() {
    bool boolean = true;
    expect(boolean).to.equal(true); //pass
    expect(boolean).to.equal(false); //fail
  });

  scenario("should have the not equals language chain", []() {
    bool boolean = true;
    expect(boolean).not.to.equal(false); //pass
    expect(boolean).not.to.equal(true); //fail
  });
});