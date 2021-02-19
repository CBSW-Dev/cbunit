#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("C String", []() {
  scenario("should have the equals language chain", []() {
    const char* cstring = "Hello";
    const char* other = cstring;
    expect(cstring).to.equal(other); //pass
    expect(cstring).to.equal(reinterpret_cast<const char*>(0x87654321)); //fail
  });

  scenario("should have the not equals language chain", []() {
    const char* cstring = "Hello";
    const char* other = cstring;
    expect(cstring).not.to.equal(reinterpret_cast<const char*>(0x87654321)); //pass
    expect(cstring).not.to.equal(other); //fail
  });

  scenario("should have the to.be.null language chain", []() {
    const char* nullCString = nullptr;
    const char* nonNullCString = "Hello";
    expect(nullCString).to.be.null(); //pass
    expect(nonNullCString).to.be.null(); //fail
  });

  scenario("should have the to.be.valid language chain", []() {
    const char* nullCString = nullptr;
    const char* nonNullCString = "Hello";
    expect(nonNullCString).to.be.valid(); //pass
    expect(nullCString).to.be.valid(); //fail
  });

  scenario("should have the to.have.address language chain", []() {
    const char* nullCString = nullptr;
    const char* nonNullCString = "Hello";
    expect(nullCString).to.have.address(0x00000000); //pass
    expect(nonNullCString).to.have.address(reinterpret_cast<std::size_t>(&nonNullCString)); //pass

    expect(nullCString).to.have.address(0x00000001); //fail
    expect(nonNullCString).to.have.address(0xFEDBC120); //fail
  });

  scenario("should access the string language chain", []() {
    const char* cstring = "Hello";
    expect(cstring).string.to.contain("el"); //pass
    expect(cstring).string.length.to.equal(5); //pass
    expect(cstring).string.length.to.equal(7); //fail
  });
});