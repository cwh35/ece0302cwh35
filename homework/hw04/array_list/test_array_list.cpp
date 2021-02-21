#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;
}
TEST_CASE("Test the insert function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(1,4);
  REQUIRE(list.getEntry(1) == 4);
}
TEST_CASE("Test the remove function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  REQUIRE(list.remove(2));
}
TEST_CASE("Test the isEmpty function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  list.clear();
  REQUIRE(list.isEmpty());
}
TEST_CASE("Test the setEntry function", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  list.setEntry(3,4);
  REQUIRE(list.getEntry(3) ==4);
}
TEST_CASE("Test the copy constructor", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  ArrayList<int> list2(list);
  REQUIRE(list2.getEntry(2) == 2);
}
TEST_CASE("Test the copy assignment", "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(1,5);
  list.insert(2,2);
  list.insert(3,9);
  list.insert(4,7);
  ArrayList<int> list2;
  list2.insert(1,30);
  list2.insert(2,40);
  list2.insert(3,99);
  list2.insert(4,72);
  list = list2;
  REQUIRE(list.getLength() == 4);
  REQUIRE(list.getEntry(2) == 40);
}