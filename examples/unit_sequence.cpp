#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Sequence") {
  scenario("should have the equals language chain (vector)") {
    std::vector<int> vector = {1, 2, 3, 4};
    std::vector<int> same = {1, 2, 3, 4};
    std::vector<int> different = {10, 1, 8, 2};
    expect(vector).to.equal(same); //pass
    expect(vector).to.equal(different); //fail
  }

  scenario("should have the equals language chain (list)") {
    std::list<int> list = {1, 2, 3, 4};
    std::list<int> same = {1, 2, 3, 4};
    std::list<int> different = {10, 1, 8, 2};
    expect(list).to.equal(same); //pass
    expect(list).to.equal(different); //fail
  }

  scenario("should have the equals language chain (deque)") {
    std::deque<int> deque = {1, 2, 3, 4};
    std::deque<int> same = {1, 2, 3, 4};
    std::deque<int> different = {10, 1, 8, 2};
    expect(deque).to.equal(same); //pass
    expect(deque).to.equal(different); //fail
  }

  scenario("should have the not equals language chain") {
    std::vector<int> vector = {1, 2, 3, 4};
    std::vector<int> same = {1, 2, 3, 4};
    std::vector<int> different = {10, 1, 8, 2};
    expect(vector).not.to.equal(different); //pass
    expect(vector).not.to.equal(same); //fail
  }

  scenario("should have the contain language chain") {
    std::vector<int> vector = {1, 2, 3, 4};
    expect(vector).to.contain(3); //pass
    expect(vector).to.contain(5); //fail
  }

  scenario("should have the length language chain") {
    std::vector<int> vector = {1, 2, 3, 4};
    expect(vector).length.to.equal(4); //pass
    expect(vector).length.to.equal(5); //fail
  }
}