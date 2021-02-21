#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "Test", "[LinkedList]" ) {

  LinkedList<int> list;
}
TEST_CASE("Test the insert function", "[LinkedList]")
{
  LinkedList<int> list;
  REQUIRE(list.insert(1,4));
  REQUIRE(list.getEntry(1) == 4);
}
TEST_CASE("Test the remove function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  REQUIRE(list.remove(2));
}
TEST_CASE("Test the isEmpty function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  list.clear();
  REQUIRE(list.isEmpty());
}
TEST_CASE("Test the setEntry function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  list.setEntry(3,4);
  REQUIRE(list.getEntry(3) ==4);
}
TEST_CASE("Test the copy constructor", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  LinkedList<int> list2(list);
  REQUIRE(list2.getEntry(2) == 2);
}
TEST_CASE("Test the copy assignment", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  LinkedList<int> list2;
  list2.insert(1,30);
  list2.insert(2,40);
  list2.insert(3,99);
  list2.insert(4,72);
  list = list2;
  REQUIRE(list.getLength() == 4);
  REQUIRE(list.getEntry(2) == 40);
}
TEST_CASE("Test the swap function", "[LinkedList]")
{
  LinkedList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  LinkedList<int> list2;
  list2.insert(1,30);
  list2.insert(2,40);
  list2.insert(3,99);
  list2.insert(4,72);
  LinkedList<int> list3;
  list3.swap(list, list2);
  REQUIRE(list.getEntry(3) == 99);
}