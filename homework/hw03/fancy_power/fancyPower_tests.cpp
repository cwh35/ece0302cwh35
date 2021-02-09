#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Test case", "fancyPower"){

  REQUIRE(fancyPower(2,2) == 4);
  
}
TEST_CASE("Test case 2", "fancyPower2"){

  REQUIRE(fancyPower(3,2) == 8);
  
}
TEST_CASE("Test case3", "fancyPower3"){

  REQUIRE(fancyPower(7,2) == 128);
  
}
