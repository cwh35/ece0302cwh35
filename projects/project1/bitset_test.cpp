#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE( "Test bitset construction", "[bitset]" ) 
{
    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}
TEST_CASE( "Test bitset construction with parameter", "[bitset2]")
{
    Bitset b(6);
    REQUIRE(b.size() == 6);
    REQUIRE(b.good());
}
TEST_CASE("Test bitset consturction with strings", "[bitset3]")
{
    Bitset b("111000");
    REQUIRE(b.size() == 6);
    REQUIRE(b.good());
}
TEST_CASE("Test bitset set function", "[bitset3]")
{
    Bitset b("111000");
    b.set(5);
    REQUIRE(b.test(5) == 1);
}
TEST_CASE("Test bitset reset function", "[bitset4]")
{
    Bitset b("101100");
    b.reset(3);
    REQUIRE(b.test(3) == 0);
}
TEST_CASE("Test bitset toggle function", "[bitset5]")
{
    Bitset b("100011");
    b.toggle(4);
    REQUIRE(b.test(4) == 0);
}
TEST_CASE("Test bitset string function", "[bitset6]")
{
    Bitset b("110111");
    REQUIRE(b.asString() == "110111");
}