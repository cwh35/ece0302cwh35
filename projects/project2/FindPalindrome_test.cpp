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
	INFO("Hint: add a vector of strings non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add({"kayak1", "l00p", "circle!", "mon3y"}));
	REQUIRE(!b.add({"kayak", "loo p", "circle", "money"}));
}
TEST_CASE( "Test CutTest1", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.cutTest1({"kayak"}));
	REQUIRE(b.cutTest1({"odd", "even", "never", "or"}));
	REQUIRE(b.cutTest1({"odd", "even", "nevveer", "or"}) == false);
	REQUIRE(b.cutTest1({"oDd", "eVenn", "never", "oR"}));
	REQUIRE(b.cutTest1({"oddd", "evenN", "never", "or"}) == false);
	REQUIRE(b.cutTest1({"kayak"}));
}
TEST_CASE( "Test CutTest2", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.cutTest2({"kayak", "han"},{"kayak", "nah"}));
	REQUIRE(b.cutTest2({"race", "car"},{ "ear", "racc"}));
	REQUIRE(b.cutTest2({"rAce", "Car"},{ "eaR", "raCC"}));
	REQUIRE(b.cutTest2({"racec", "car"},{ "ear", "rac"}));
	REQUIRE(b.cutTest2({"race", "car"},{ "ea", "rrr"}) == false);
	REQUIRE(b.cutTest2({"Hannah", "civic"},{ "civ", "han"}));
	REQUIRE(b.cutTest2({"test"}, {"testing"}));
	REQUIRE(b.cutTest2({"testing"}, {"test"}));
}
TEST_CASE( "Test if sentence is a palindrome", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.add("A"));
	REQUIRE(b.add("Santa"));
	REQUIRE(b.add("at"));
	REQUIRE(b.add("NASA"));
}
TEST_CASE ("Test if string vector is a palindrome", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.add({"A", "Santa", "At", "NASA"}));
	REQUIRE(b.add({"yellow", "blue", "green"}));
}
TEST_CASE ("Test if the number function", "[FindPalindrome.number]")
{
	FindPalindrome b;
	REQUIRE(b.add({"odd", "even", "never", "or"}));
	REQUIRE(b.number() == 1);
	
	b.clear();

	REQUIRE(b.add({"A", "nice", "At", "NASA"}));
	REQUIRE(b.number() == 0);
}
TEST_CASE( "Test the clear function", "[FindPalindrome.clear]")
{
	FindPalindrome b;
	REQUIRE(b.add("never"));
	REQUIRE(b.add("odd"));
	REQUIRE(b.add("or"));
	REQUIRE(b.add("even"));


	REQUIRE(b.number() == 1);
	b.clear();

	REQUIRE(b.number() == 0);
}
TEST_CASE( "Test the to Vector", "[FindPalindrome.toVector]")
{
	FindPalindrome b;
	REQUIRE(b.add("a"));
	REQUIRE(b.add("aa"));
	REQUIRE(b.add("aaa"));

	REQUIRE(b.number() == 6);
	std::vector<std::vector<std::string>> converted = b.toVector();
	std::vector<std::string> compareValue1 = {"a","aa","aaa"};
	std::vector<std::string> compareValue2 = {"a","aaa","aa"};
	std::vector<std::string> compareValue3 = {"aa","a","aaa"};
	REQUIRE(converted[0] == compareValue1);
	REQUIRE(converted[1] == compareValue2);
	REQUIRE(converted[2] == compareValue3);

}