#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Sequence", []() {
  scenario("should have the equals language chain", []() {
    std::vector<int> vector = {1, 2, 3, 4};
    std::vector<int> same = {1, 2, 3, 4};
    std::vector<int> different = {10, 1, 8, 2};
    expect(vector).to.equal(same); //pass
    expect(vector).to.equal(different); //fail
  });

  scenario("should have the not equals language chain", []() {
    std::vector<int> vector = {1, 2, 3, 4};
    std::vector<int> same = {1, 2, 3, 4};
    std::vector<int> different = {10, 1, 8, 2};
    expect(vector).not.to.equal(different); //pass
    expect(vector).not.to.equal(same); //fail
  });

  scenario("should have the contain language chain", []() {
    std::vector<int> vector = {1, 2, 3, 4};
    expect(vector).to.contain(3); //pass
    expect(vector).to.contain(5); //fail
  });
});