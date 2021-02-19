#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Floating Point", []() {
  scenario("should have the equals language chain", []() {
    float floatingPoint = 17.0f;
    expect(floatingPoint).to.equal(17.0f); //pass
    expect(floatingPoint).to.equal(1.0f); //fail
  });

  scenario("should have the not equals language chain", []() {
    float floatingPoint = 17.0f;
    expect(floatingPoint).not.to.equal(216.5f); //pass
    expect(floatingPoint).not.to.equal(17.0f); //fail
  });

  scenario("should have the be.greaterThan language chain", []() {
    double floatingPoint = 17.0;
    expect(floatingPoint).to.be.greaterThan(16.5); //pass
    expect(floatingPoint).to.be.greaterThan(17.0); //fail
    expect(floatingPoint).to.be.greaterThan(17.5); //fail
  });

   scenario("should have the be.greaterThanOrEqual language chain", []() {
    float floatingPoint = 17.0f;
    expect(floatingPoint).to.be.greaterThanOrEqual(16.5f); //pass
    expect(floatingPoint).to.be.greaterThanOrEqual(17.0f); //pass
    expect(floatingPoint).to.be.greaterThanOrEqual(17.5f); //fail
  });

   scenario("should have the be.lessThan language chain", []() {
    double floatingPoint = 17.0;
    expect(floatingPoint).to.be.lessThan(17.5); //pass
    expect(floatingPoint).to.be.lessThan(17.0); //fail
    expect(floatingPoint).to.be.lessThan(16.5); //fail
  });

   scenario("should have the be.lessThanOrEqual language chain", []() {
    float floatingPoint = 17.0f;
    expect(floatingPoint).to.be.lessThanOrEqual(17.5); //pass
    expect(floatingPoint).to.be.lessThanOrEqual(17.0f); //pass
    expect(floatingPoint).to.be.lessThanOrEqual(16.5f); //fail
  });

  scenario("should have the be.at.least language chain", []() {
    double floatingPoint = 17.0;
    expect(floatingPoint).to.be.at.least(16.5); //pass
    expect(floatingPoint).to.be.at.least(17.0); //pass
    expect(floatingPoint).to.be.at.least(17.5); //fail
  });

  scenario("should have the be.at.most language chain", []() {
    double floatingPoint = 17.0;
    expect(floatingPoint).to.be.at.most(17.5); //pass
    expect(floatingPoint).to.be.at.most(17.0); //pass
    expect(floatingPoint).to.be.at.most(16.5); //fail
  });

   scenario("should have the be.within(x).of language chain", []() {
    double floatingPoint = 17.05;
    expect(floatingPoint).to.be.within(0.1).of(17.0); //pass
    expect(floatingPoint).to.be.within(0.1).of(17.1); //pass
    expect(floatingPoint).to.be.within(0.04).of(17.1); //fail
  });
});