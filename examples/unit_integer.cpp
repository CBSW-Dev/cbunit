#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Integer", []() {
  scenario("should have the equals language chain", []() {
    int integer = 17;
    expect(integer).to.equal(17); //pass
    expect(integer).to.equal(212); //fail
  });

  scenario("should have the not equals language chain", []() {
    int integer = 17;
    expect(integer).not.to.equal(212); //pass
    expect(integer).not.to.equal(17); //fail
  });

  scenario("should have the be.greaterThan language chain", []() {
    uint32_t integer = 17;
    expect(integer).to.be.greaterThan(12); //pass
    expect(integer).to.be.greaterThan(17); //fail
    expect(integer).to.be.greaterThan(19); //fail
  });

   scenario("should have the be.greaterThanOrEqual language chain", []() {
    uint32_t integer = 17;
    expect(integer).to.be.greaterThanOrEqual(12); //pass
    expect(integer).to.be.greaterThanOrEqual(17); //pass
    expect(integer).to.be.greaterThanOrEqual(19); //fail
  });

   scenario("should have the be.lessThan language chain", []() {
    uint32_t integer = 17;
    expect(integer).to.be.lessThan(19); //pass
    expect(integer).to.be.lessThan(17); //fail
    expect(integer).to.be.lessThan(12); //fail
  });

   scenario("should have the be.lessThanOrEqual language chain", []() {
    uint32_t integer = 17;
    expect(integer).to.be.lessThanOrEqual(19); //pass
    expect(integer).to.be.lessThanOrEqual(17); //pass
    expect(integer).to.be.lessThanOrEqual(12); //fail
  });

  scenario("should have the be.at.least language chain", []() {
    uint32_t integer = 17;
    expect(integer).to.be.at.least(12); //pass
    expect(integer).to.be.at.least(17); //pass
    expect(integer).to.be.at.least(19); //fail
  });

  scenario("should have the be.at.most language chain", []() {
    uint32_t integer = 17;
    expect(integer).to.be.at.most(19); //pass
    expect(integer).to.be.at.most(17); //pass
    expect(integer).to.be.at.most(12); //fail
  });
});