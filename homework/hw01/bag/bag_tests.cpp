#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bag.hpp"

// force template expansion
template class Bag<int>;

TEST_CASE("Empty Test", "[Bag]")
{
  REQUIRE(true);
}
TEST_CASE("For isEmpty","[Test1]")
{
  Bag<int> Bag; 
  REQUIRE(Bag.isEmpty()); 
}
TEST_CASE("Test for Bag size", "[Test2]")
{
  Bag<int> Bag; 
  Bag.add(5); 
  bool bagSize;

  if(Bag.getCurrentSize() == 1)
  {
    bagSize = true;
  }
  else
  {
    bagSize = false;
  }
  REQUIRE(bagSize);
}
TEST_CASE("Test for adding an item", "[Test3]")
{
  Bag<int> Bag;
  REQUIRE(Bag.add(7));
}
TEST_CASE("Test for frequency of an item", "[Test4]")
{
  Bag<int> Bag;
  Bag.add(9);
  Bag.add(7);
  Bag.add(4);
  Bag.add(9);
  REQUIRE(Bag.getFrequencyOf(9) == 2);
}
TEST_CASE("Test for if the bag contains a certain item", "[Test5]")
{
  Bag<int> Bag;
  Bag.add(10);
  Bag.add(5);
  Bag.add(22);
  Bag.add(59);
  REQUIRE(Bag.contains(22));
}
TEST_CASE("Test for removing an item", "[Test6]")
{
  Bag<int> Bag;
  Bag.add(10);
  Bag.add(5);
  Bag.add(22);
  Bag.add(59);
  Bag.add(9);
  Bag.add(7);
  Bag.add(4);
  Bag.add(9);
  REQUIRE(Bag.remove(10));
}