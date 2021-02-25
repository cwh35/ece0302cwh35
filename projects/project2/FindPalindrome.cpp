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
	string sentTemp;

	if (currentStringVector.size() == 0)
	{
		sentTemp = SentToStr(candidateStringVector);
		if(isPalindrome(sentTemp))
		{
			pallyCounter++;
			pallySentences.push_back(candidateStringVector);
		}
	}
	
	vector<string> CurrTemp, CandTemp; //temporary variables for the string vectors

	for(int i=0; i<currentStringVector.size(); i++)
	{
		CurrTemp = currentStringVector;
		CandTemp = candidateStringVector;
		CandTemp.push_back(CurrTemp[i]);
		CurrTemp.erase(CurrTemp.begin() + i);
	
		if (cutTest2(CandTemp, CurrTemp))
		{
			recursiveFindPalindromes(CandTemp, CurrTemp);
		}
	}
	
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
	pallyCounter = 0;
}

FindPalindrome::~FindPalindrome()
{
	pallyVector.swap(pallyVector); //Deallocates memory from vector
}

int FindPalindrome::number() const
{
	return pallyCounter; //Returns the number of palindromes
}

void FindPalindrome::clear()
{
	pallyVector.erase(pallyVector.begin(), pallyVector.end()); //Clears the vector
	pallySentences.erase(pallySentences.begin(), pallySentences.end());
	pallyCounter = 0;
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
		if(freq[i]%2 != 0) //Checks if there is an even or odd amount of characters
		{
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
	locale loc;
	int freq[26] = {0}; //Counts the frequency of a character in a string
	int freq2[26] = {0}; 
	int j = 0, k; //j represents the position of the character
	int sizeOfChar = 0, sizeOfChar2 = 0; //size of characters
	vector<string> dummyVec1 = stringVector1;
	vector<string> dummyVec2 = stringVector2;


	for (int i=0; i<dummyVec1.size(); i++) //For loop for first half of vector
	{
		convertToLowerCase(dummyVec1[i]);
		j=0;

		while (dummyVec1[i][j] != '\0')//runs through characters til the end of string
		{
			if(dummyVec1[i][j] >= 'a' && dummyVec1[i][j] <= 'z')//Checks if it is alpha character
			{
				k = dummyVec1[i][j] - 'a';
				++freq[k];//increase freq count for letter
			}
			sizeOfChar++;
			++j;//loops to next character
		}
	}
	for (int i=0; i<dummyVec2.size(); i++) //For Loop for the second half of vector
	{
		convertToLowerCase(dummyVec2[i]);
		j=0;

		while (dummyVec2[i][j] != '\0')//runs through characters til the end of string
		{
			if(dummyVec2[i][j] >= 'a' && dummyVec2[i][j] <= 'z')//Checks if it is alpha character
			{
				k = dummyVec2[i][j] - 'a';
				++freq2[k];//increase freq count for letter
			}
			sizeOfChar2++;
			++j;//loops to next character
		}
	}

	if (sizeOfChar > sizeOfChar2)
	{
		for(int i = 0; i < 26; i++)
		{
			if (freq[i] < freq2[i])
			{
				return false;
			}
		}
	}
	else if(sizeOfChar < sizeOfChar2)
	{
		for(int i = 0; i < 26; i++)
		{
			if (freq[i] > freq2[i])
			{
				return false;
			}
		}
	}
	else
	{
		for(int i = 0; i < 26; i++)
		{
			if (freq[i] != freq2[i])
			{
				return false;
			}
		}
	}
	
	return true;
}

bool FindPalindrome::add(const string & value)
{
	string newValue = value;
	vector<string> tempVec = pallyVector;

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
	for (int i=0; i<tempVec.size(); i++)
	{
		convertToLowerCase(tempVec[i]);
		if (newValue == tempVec[i]) //Checks for duplicate strings
		{
			return false; //Returns false if above condition is true
		}
	}
	pallyVector.push_back(value); //Adds string to the vector
	pallyCounter = 0;
	pallySentences.erase(pallySentences.begin(), pallySentences.end());
	
	if (cutTest1(pallyVector))
	{
		recursiveFindPalindromes({}, pallyVector);
	}	
	else
	{
		pallySentences = {{}};
		pallyCounter= 0;
	}
	
	return true;
	
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	vector<string>newValue = stringVector; //make a not constant vector and set it equal to the parameter
	vector<string>strVectorCopy = stringVector;
	vector<string>strVectorComparison = pallyVector; //make a comparison vector for pallyVector
	for (int i=0; i<newValue.size(); i++) //Checks if palindrome contains acceptable characters
	{
		for(int j = 0; j < newValue[i].size(); j++)
		{
			if (newValue[i][j] <= 'z' && newValue[i][j] >= 'a' || newValue[i][j] <='Z' && newValue[i][j] >= 'A')
			{
				//Empty if to check valid characters
			}
			else
			{
				return false;
			}
		}	
	convertToLowerCase(newValue[i]); 
		for(int k = 0; k < strVectorComparison.size(); k++)
		{
			convertToLowerCase(strVectorComparison[k]);
			if (newValue[k] == strVectorComparison[k]) //Checks for duplicate strings
			{
				return false; //Returns false if above condition is true
			}
		}
		pallyVector.push_back(strVectorCopy[i]); //Adds vector of strings to the vector
	}
	//Call cuttest1 to see if the new vector is valid
	if (cutTest1(pallyVector))
	{
		recursiveFindPalindromes({}, pallyVector);
	}	
	else
	{
		pallySentences = {{}};
		pallyCounter= 0;
	}
	
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	return pallySentences;
}
string FindPalindrome::SentToStr(vector<string> vecToStr)
{
	string test; 
	for(int i = 0; i<vecToStr.size(); i++) //This for loop combines all strings into one word
	{
		test = test + vecToStr[i];
	}
	return test;
}

