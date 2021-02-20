#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	// TODO need to implement this recursive function!
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	pallyVector.resize(0); //Reset the size of the vector
}

FindPalindrome::~FindPalindrome()
{
	pallyVector.swap(pallyVector); //Deallocates memory from vector
}

int FindPalindrome::number() const
{
	return numOfPallys; //Returns the number of palindromes
}

void FindPalindrome::clear()
{
	pallyVector.clear(); //Clears the vector
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	locale loc;
	int counter = 0; //Counts the amount of characters in a vector
	int freq[26] = {0}; //Counts the frequency of a character in a string 
	int j = 0, k;
	vector<string> dummyVec = stringVector;


	for (int i=0; i<dummyVec.size(); i++)
	{
		convertToLowerCase(dummyVec[i]);
		j=0;

		while (dummyVec[i][j] != '\0')//runs through characters til the end of string
		{
			if(dummyVec[i][j] >= 'a' && dummyVec[i][j] <= 'z')//Checks if it is alpha character
			{
				k = dummyVec[i][j] - 'a';
				++freq[k];//increase freq count for letter
			}
			++j;//loops to next character
		}
	}

	for(int i = 0; i < 26; i++)
	{
		if(freq[i]%2 != 0){
			counter++;
		}
	}
	if(counter > 1)
	{
		return false;
	}
	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	string newValue = value;

	locale loc;
	convertToLowerCase(newValue);
	for (int i=0; i<value.size(); i++) //Checks if palindrome contains acceptable characters
	{
		if (value[i] <= 'z' && value[i] >= 'a' || value[i] <='Z' && value[i] >= 'A')
		{
			//Empty if to check valid characters
		}
		else
		{
			return false;
		}	
	}
	for (int i=0; i<pallyVector.size(); i++)
	{
		convertToLowerCase(pallyVector[i]);
		if (newValue == pallyVector[i]) //Checks for duplicate strings
		{
			return false; //Returns false if above condition is true
		}
	}
	pallyVector.push_back(newValue); //Adds string to the vector
	return true;
	
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	vector<string>newValue = stringVector;

	for (int i=0; i<stringVector.size(); i++) //Checks if palindrome contains acceptable characters
	{
		for(int j = 0; j < stringVector[i].size(); j++)
		{
			if (stringVector[i][j] <= 'z' && stringVector[i][j] >= 'a' || stringVector[i][j] <='Z' && stringVector[i][j] >= 'A')
			{
				//Empty if to check valid characters
			}
			else
			{
				return false;
			}
		}	
	
		for (int j=0; j<newValue.size(); j++) //Run through the vector
		{
			convertToLowerCase(newValue[j]); 
			for(int k = 0; k < pallyVector.size(); k++)
			{
				convertToLowerCase(pallyVector[k]);
				if (newValue[j] == pallyVector[k]) //Checks for duplicate strings
				{
					return false; //Returns false if above condition is true
				}
			}
		}
		pallyVector.push_back(stringVector[i]); //Adds vector of strings to the vector
	}
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	vector<vector<string>> returnThingie;
	return returnThingie;
}

