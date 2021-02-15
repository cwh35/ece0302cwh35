#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Empty Test", "[LimitedSizeBag]"){
  REQUIRE(true);
}
TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
TEST_CASE("Testing the add function", "[LimitedSizeBag2]")
{
  LimitedSizeBag<int> b;
  REQUIRE(b.add(5));
  REQUIRE(b.contains(5));
}
TEST_CASE("Testing the remove function", "[LimitedSizeBag3]")
{
  LimitedSizeBag<int> b;
  b.add(6);
  b.add(12);
  b.add(90);
  b.add(45);
  REQUIRE(b.remove(12));
  REQUIRE(b.contains(12) == 0);
}
TEST_CASE("Testing the isEmpty function", "[LimitedSizeBag4]")
{
  LimitedSizeBag<int> b;
  b.add(6);
  b.add(12);
  b.add(90);
  b.add(45);
  b.clear();
  REQUIRE(b.isEmpty());
}
TEST_CASE("Testing the getFrequencyOf function", "[LimitedSizeBag5]")
{
  LimitedSizeBag<int> b;
  b.add(6);
  b.add(12);
  b.add(90);
  b.add(45);
  b.add(12);
  REQUIRE(b.getFrequencyOf(12) == 2);
}
