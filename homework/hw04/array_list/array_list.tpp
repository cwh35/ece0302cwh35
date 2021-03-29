#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() 
{
  size = 20;
  array = new T[size]; //allocate new memory for the array
  elements = 0;
}

template <typename T>
ArrayList<T>::~ArrayList() 
{
  delete [] array;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs)
{
  size = 20;
  array = new T[size];
  elements = 0;

  for (int i=0; i<rhs.getLength(); i++)
  {
    insert(i+1, rhs.array[i]);
  }
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs)
{
  clear();
  for (int i=0; i<rhs.getLength(); i++)
  {
    insert(i+1, rhs.array[i]);
  }
  return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const
{
  if (getLength() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
std::size_t ArrayList<T>::getLength() const
{
  return elements;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item)
{
  if (elements == size)
  {
    incrArraySize(); //increase the array size
  }
  else if (elements > size)
  {
    return false;
  }
  for (int i=elements-1; i>=0; i--)
  {
    if (i >= position)
    {
      array[i+1] = array[i];
    }
  }
  elements++;
  array[position-1] = item;
  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position)
{
  
  if (position > elements || position <= 0)
  {
    return false; //Check to see if position is valid
  }
  for (int i = position; i < getLength(); i++)
  {
    array[i-1] = array[i];
  }
  elements--;
  return true; 
}

template <typename T>
void ArrayList<T>::clear() 
{
  elements = 0;
  delete [] array;
  array = new T[20];
  size = 20;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const 
{
  return array[position-1];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) 
{
  array[position-1] = newValue;
}

template <typename T> void ArrayList<T>::incrArraySize()
{
  int *newArr;
  int *oldArr = array;
  newArr = new int[size*2];//Allocate new dynamic array

  for (int i=0; i<size; i++)
  {
    newArr[i] = oldArr[i]; //allocate new memory for the array
  }
  size =size*2;
  delete [] array;
  array = newArr;
}