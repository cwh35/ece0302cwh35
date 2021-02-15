#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
TEST_CASE("Testing the add function", "[DynamicBag2]")
{
  DynamicBag<int> b;
  REQUIRE(b.add(5));
  REQUIRE(b.contains(5));
}
TEST_CASE("Testing the remove function", "[DynamicBag3]")
{
  DynamicBag<int> b;
  b.add(6);
  b.add(12);
  b.add(90);
  b.add(45);
  REQUIRE(b.remove(12));
  REQUIRE(b.contains(12) == 0);
}
TEST_CASE("Testing the isEmpty function", "[DynamicBag4]")
{
  DynamicBag<int> b;
  b.add(6);
  b.add(12);
  b.add(90);
  b.add(45);
  b.clear();
  REQUIRE(b.isEmpty());
}
TEST_CASE("Testing the getFrequencyOf function", "[DynamicBag5]")
{
  DynamicBag<int> b;
  b.add(6);
  b.add(12);
  b.add(90);
  b.add(45);
  b.add(12);
  REQUIRE(b.getFrequencyOf(12) == 2);
}