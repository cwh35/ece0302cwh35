#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}
TEST_CASE( "Test FindPalindrome add a non-allowable vector of words", "[FindPalindromeStringVector]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add({"kayak1", "l00p", "circle!", "mon3y"}));
}
TEST_CASE( "Test CutTest1", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.cutTest1({"kayak"}));
	REQUIRE(b.cutTest1({"odd", "even", "never", "or"}));
}
