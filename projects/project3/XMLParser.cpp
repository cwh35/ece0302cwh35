// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

static std::string deleteAttributes(std::string);
bool checkSpecialChar(std::string); //checks for invalid special characters

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag = new Bag<std::string>;
	parseStack = new Stack<std::string>;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	delete elementNameBag;
	delete parseStack;
	elementNameBag = nullptr;
	parseStack = nullptr;
	tokenizedInputVector.clear();
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	std::string content = "", tag_Name = "";
	TokenStruct temp; //temporary variable for TokenStruct
	int i = 0; //counter variable for the while loop
	if(inputString == "")//If no input string
	{
		return false;
	}

	while(i < inputString.size()) //Runs through the entire string
	{
		if(inputString[i] == '<') //Checks if string contains <
		{
			temp.tokenType == START_TAG;
			i++;
			if(inputString[i] == '?')
			{
				i++;
				temp.tokenType = DECLARATION;
				while(inputString[i] != '?' && inputString[i+1] != '>')
				{
					tag_Name = tag_Name + inputString[i];
					i++;
				}
				i = i+2; //To skip past the question mark and angle bracket
				
				elementNameBag->add(tag_Name); //Adds tag_name to bag 
				temp.tokenString = tag_Name; //sets tag_name equal to the token string
				tokenizedInputVector.push_back(temp); //push tag_name into the vector
				tag_Name = "";
			}
			else if(inputString[i] == '/')//End tag
			{
				temp.tokenType = END_TAG;
				i++;
				while(inputString[i] != '>')
				{
					tag_Name = tag_Name + inputString[i];
					i++;
				}
				i++;
				
				if(!checkSpecialChar(tag_Name))//Check if the tagname is valid
				{
					clear();
					return false;
				}
				temp.tokenString = tag_Name; 				
				tokenizedInputVector.push_back(temp);
				tag_Name = ""; //Reset tag name
			}
			else{//Start and empty tag
				if(inputString[i] == ' ')
				{
					return false; //if the start tag has a space
				}
				while(inputString[i] != '>' && inputString[i] != '/')
				{	
					temp.tokenType = START_TAG;
					tag_Name = tag_Name + inputString[i];
					i++;
				}
				if(inputString[i] == '/' && inputString[i+1] == '>')
				{
					temp.tokenType = EMPTY_TAG;
					i+=2;
				}
				else if(inputString[i] == '>')
				{
					i++;
				}
				
				tag_Name = deleteAttributes(tag_Name); //deleting all elements after " "
				if(!checkSpecialChar(tag_Name))//Check if the tagname is valid
				{
					clear();
					return false;
				}		
				elementNameBag ->add(tag_Name);		
				temp.tokenString = tag_Name; //set tag_name equal to the token string
				tokenizedInputVector.push_back(temp);
				tag_Name = "";
			}

		}
		else //if it's any other character other than the ones above, it's content
		{
			int p = 0;
			bool status = false;
			while(inputString[i] != '<' && i<inputString.size())
			{
				content = content + inputString[i];
				i++;
			}
			while(p < content.size())
			{
				if(content[p] != ' ' && content[p] != '\n')
				{
					status = true;
				}
				p++;
			}
			if(!status)
			{
				content = "";
			}
			else
			{
				temp.tokenType = CONTENT;
				temp.tokenString = content;
				tokenizedInputVector.push_back(temp);
			}
			content = "";
		}
	}
	if(temp.tokenType == CONTENT && (temp.tokenString == " " || temp.tokenString == ""))
	{
		tokenizedInputVector.pop_back();
	}
	return true;
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	int i=0;
	while(i<input.size())
	{
		if(input[i] == ' ')
		{
			return input.substr(0,i); //Truncates everything after the space
		}
		i++;
	}
	return input;
}
//Function to check if the string contains any invalid characters
bool checkSpecialChar(std::string inputString)
{
	std::string invalidChar = "!\"#$%&'()*+,/;<=>?@[\\]^`{|}~";
	std::string invalidNum = "0123456789-,.";
	bool valid = true;
	for(int i=0;i<invalidNum.size();i++)
	{
		if(invalidNum[i] == inputString[0]) //Checks if the first elements is any of the elements from invalidNum
		{
			valid = false;
		}
	}
	for(int k=0; k<invalidChar.size();k++)
	{
		for(int j=0; j<inputString.size();j++)
		{
			if(invalidChar[k] == inputString[j])
			{
				valid = false;
			}
		}
	}
	return valid;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	if(tokenizedInputVector.size()==0 || tokenizedInputVector.back().tokenType == 4) //if size = 0, or last element is content
	{
		return false;
	}

	int i = 0;
	while(i < tokenizedInputVector.size())
	{
		if(tokenizedInputVector[i].tokenType == 1)
		{
			parseStack->push(tokenizedInputVector[i].tokenString);
		}
		else if (tokenizedInputVector[i].tokenType == 2)
		{
			if(parseStack->size() == 0) //If an end tag comes before a start tag
			{
				return false; 
			}
			if (parseStack->peek() == tokenizedInputVector[i].tokenString) //if top of stack matches tag
			{
				parseStack->pop(); //Pop end tag so you don't have duplicate tag names
			}
		}
		i++; //Increment the counter for the while loop
	}
	if(parseStack->isEmpty() == false) //if stack is not empty, return false
	{
		return false;
	}
	return true;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag ->clear();
	parseStack ->clear();
	tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return elementNameBag->contains(inputString);
	throw logic_error("Failed tokenizer or parse");
	
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if(tokenizedInputVector.size() == 0)
	{
		throw logic_error("Failed tokenizer or parse");
	}
	return elementNameBag->getFrequencyOf(inputString);
}

