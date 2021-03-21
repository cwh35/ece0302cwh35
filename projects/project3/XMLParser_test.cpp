#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here

TEST_CASE( "Test Bag add", "[XMLParser]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test Stack push", "[XMLParser]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
}

TEST_CASE( "Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear(); //Clear the input string token before each test case

		//Change the testString
		testString = "<hello>Hey how's it going?</hello>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();

		//Change to declaration
		testString = "<?This is a declaration. say hi everyone?>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();

		//Change to empty tag
		testString = "<Schenley Park is so nice right now/>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();

		//Add more to the tag
		testString = "<hello>Hey how's it going?</hello><Pizza>Cheese with pepperoni on top</Pizza>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();

		testString = "<?xml-script version=\"1.0\"?>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();

		testString = "This is totally content right now";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();

		testString = "Content strikes again wooooo";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		myXMLParser.clear();

		testString = "<bagelbites>Best breakfast food, no competition</bagelbites> ";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(myXMLParser.returnTokenizedInput().size() == 3);
		REQUIRE(success);
		myXMLParser.clear();
}
TEST_CASE( "Test XMLParser tokenizeInputString - failing", "[XMLParser - failing]" )
{
		XMLParser myXMLParser; 
		bool success;
		string testString;
		testString = "<he<>llo>Hey how's it going?</hello>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
		myXMLParser.clear();

		myXMLParser; 
		testString = "<he$llo>Hey how's it going?</hello>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
		myXMLParser.clear();

		myXMLParser; 
		testString = "<he^&llo>Hey how's it going?</hello>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
		myXMLParser.clear();

		myXMLParser; 
		testString = "";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
		myXMLParser.clear();

		testString = "<.test>ramen is very good</test>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
		myXMLParser.clear();

		testString = "<test>ramen is very good</1test>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
		myXMLParser.clear();

		testString = "<5test/>ramen is very good</test>";
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(!success);
		myXMLParser.clear();

}	
TEST_CASE("Testing the contains function", "[XMLParser2]")
{
	XMLParser myXMLParser;
	string testString;
	bool success;

	testString = "<donut>Welcome to Dunkin Donuts!</donut>";
	success = myXMLParser.tokenizeInputString(testString);
	REQUIRE(success);
	REQUIRE(myXMLParser.parseTokenizedInput());
	REQUIRE(myXMLParser.containsElementName("donut"));
	REQUIRE(!myXMLParser.containsElementName("pizza"));

}
TEST_CASE("Testing the getFrequencyOf function", "[XMLParser3]")
{
	XMLParser myXMLParser;
	string testString;
	bool success;

	testString = "<donut>Welcome to Dunkin Donuts!</donut>";
	success = myXMLParser.tokenizeInputString(testString);
	REQUIRE(success);
	REQUIRE(myXMLParser.parseTokenizedInput());
	REQUIRE(myXMLParser.containsElementName("donut"));
	REQUIRE(myXMLParser.frequencyElementName("donut") ==1);
	myXMLParser.clear();
}		
TEST_CASE("Testing the clear function", "[XMLParser4]")
{
	XMLParser myXMLParser;
	string testString;
	bool success;

	testString = "<donut>Welcome to Dunkin Donuts!</donut>";
	success = myXMLParser.tokenizeInputString(testString);
	REQUIRE(success);
	REQUIRE(myXMLParser.parseTokenizedInput());
	REQUIRE(myXMLParser.containsElementName("donut"));
	REQUIRE(!myXMLParser.containsElementName("pizza"));
	myXMLParser.clear();
	REQUIRE(!myXMLParser.containsElementName("donut"));
}
TEST_CASE( "Testing an XML line : end tag comes before start tag", "[XMLParser5]")
{
	XMLParser myXMLParser;
	string testString;
	bool success;
	testString = "</window>This window tag is in the wrong spot<window>";
	success = myXMLParser.tokenizeInputString(testString);
	REQUIRE(success);
	REQUIRE(!myXMLParser.parseTokenizedInput());
}


