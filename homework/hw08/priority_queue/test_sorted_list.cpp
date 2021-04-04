#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"

TEST_CASE("Testing Sorted List", "[sorted list]")
{
  typedef SortedList<int, DynamicArrayList<int> > slst;
  
}
TEST_CASE("Testing insert function", "[sorted list]")
{
  typedef SortedList<int, DynamicArrayList<int> > slst;
  slst sortedlist;

  sortedlist.insert(9);
  sortedlist.insert(50);
  sortedlist.insert(23);
  sortedlist.insert(8);
  sortedlist.insert(11);
  REQUIRE(sortedlist.getEntry(2) == 11);
  REQUIRE(sortedlist.getEntry(4) == 50);
  REQUIRE(sortedlist.getEntry(0) == 8);
}
TEST_CASE("Testing remove function", "[sorted list]")
{
  typedef SortedList<int, DynamicArrayList<int> > slst;
  slst sortedlist;

  sortedlist.insert(9);
  sortedlist.insert(50);
  sortedlist.insert(23);
  sortedlist.insert(8);
  sortedlist.insert(11);
  sortedlist.insert(68);
  sortedlist.insert(700);
  sortedlist.insert(4213);
  sortedlist.insert(14);
  sortedlist.remove(50);
  sortedlist.remove(68);
  REQUIRE(sortedlist.getEntry(5) == 700);
  REQUIRE(sortedlist.getEntry(6) == 4213);
}
TEST_CASE("Testing getPosition function", "[sorted list]")
{
  typedef SortedList<int, DynamicArrayList<int> > slst;
  slst sortedlist;

  sortedlist.insert(9);
  sortedlist.insert(50);
  sortedlist.insert(23);
  sortedlist.insert(8);
  sortedlist.insert(11);
  sortedlist.insert(68);
  sortedlist.insert(700);
  sortedlist.insert(4213);
  sortedlist.insert(14);
  sortedlist.remove(50);
  sortedlist.remove(68);
  REQUIRE(sortedlist.getPosition(8) == 0);
  REQUIRE(sortedlist.getPosition(4213) == 6);
}