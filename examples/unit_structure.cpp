#include "cbunit.hpp"
#include "cbunit_macros.hpp"

fixture("Structure", []() {
  beforeEach([]() {
    std::cout << "Before Each" << std::endl;
  });

  afterEach([]() {
    std::cout << "After Each" << std::endl;
  });

  scenario("scenario 1", []() {
   
  });

  scenario("scenario 2", []() {
   
  });

  group("test group", []() {
    beforeEach([]() {
      std::cout << "  Before Each Group" << std::endl;
    });

    afterEach([]() {
      std::cout << "  After Each Group" << std::endl;
    });

    scenario("scenario 3", []() {
   
    });
    
    scenario("scenario 4", []() {
    
    });
  });
});