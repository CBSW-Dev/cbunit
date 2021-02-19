#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Pointer", []() {
  scenario("should have the equals language chain", []() {
    void* pointer = reinterpret_cast<void*>(0x12345678);
    expect(pointer).to.equal(reinterpret_cast<void*>(0x12345678)); //pass
    expect(pointer).to.equal(reinterpret_cast<void*>(0x87654321)); //fail
  });

  scenario("should have the not equals language chain", []() {
    void* pointer = reinterpret_cast<void*>(0x12345678);
    expect(pointer).not.to.equal(reinterpret_cast<void*>(0x87654321)); //pass
    expect(pointer).not.to.equal(reinterpret_cast<void*>(0x12345678)); //fail
  });

  scenario("should have the to.be.null language chain", []() {
    void* nullPointer = nullptr;
    void* nonNullPointer = reinterpret_cast<void*>(0x12345678);
    expect(nullPointer).to.be.null(); //pass
    expect(nonNullPointer).to.be.null(); //fail
  });

  scenario("should have the to.be.valid language chain", []() {
    void* nullPointer = nullptr;
    void* nonNullPointer = reinterpret_cast<void*>(0x12345678);
    expect(nonNullPointer).to.be.valid(); //pass
    expect(nullPointer).to.be.valid(); //fail
  });

  scenario("should have the to.have.address language chain", []() {
    void* nullPointer = nullptr;
    void* nonNullPointer = reinterpret_cast<void*>(0x12345678);
    expect(nullPointer).to.have.address(0x00000000); //pass
    expect(nonNullPointer).to.have.address(0x12345678); //pass

    expect(nullPointer).to.have.address(0x00000001); //fail
    expect(nonNullPointer).to.have.address(0xFEDBC120); //fail
  });
});