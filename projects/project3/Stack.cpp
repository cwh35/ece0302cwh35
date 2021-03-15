//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	delete headPtr;
	headPtr = nullptr;
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if(currentSize == 0)
	{
		return true;
	}
	return false; //returns false if loop is not true
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNode = new Node<ItemType>;
	newNode->setItem(newItem);
	newNode->setNext(headPtr);
	headPtr = newNode; //Sets newNode as the top of the stack
	currentSize++; //Increases the size of the stack
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	ItemType returnItem;

	if(isEmpty())
	{
		throw logic_error("There is nothing in the Stack");
	}
	else
	{
		returnItem = headPtr->getItem(); //Returns the top item in the stack
		return returnItem;
	}
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if (headPtr == NULL) //checks to see if anything is in the stack
	{
		return false;
	}
	else
	{
		headPtr = headPtr->getNext();
		currentSize--;
	}
	return true;
	
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	headPtr = nullptr;
	currentSize = 0;
}  // end clear

