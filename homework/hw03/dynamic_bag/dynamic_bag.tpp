#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() 
{
  dynamBag = new T[arraySize];
  index = 0;
}
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x) //Copy constructor
{
  arraySize = x.getCurrentSize();
  index = 0;
  dynamBag = new T[arraySize];
  for (int i = 0; i<arraySize; i++)
  {
    dynamBag[i] = x.dynamBag[i];
  }
}
template<typename T>
DynamicBag<T>::~DynamicBag()
{
  delete [] dynamBag;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  
  arraySize = x.getCurrentSize();
  clear();
  for (int i = 0; i<arraySize; i++)
  {
    add(x.dynamBag[i]);
  }
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  if (index < arraySize)
  {
    dynamBag[index] = item;
    index++;
    return true;
  }
  else
  {
    return false;
  }
} 

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  bool valid;
  int count = 0;
  if(contains(item) == false) //Checks to see if item is in the bag
  {
    valid =  false;
    return valid;
  }
  while (dynamBag[count] != item)//Gets the position of the item to be removed
  {
    count++;
    valid = true;
  }
  for (count; count<getCurrentSize(); count++)
  {
      dynamBag[count] = dynamBag[count + 1];
  }
  index--;
  return valid; 
  
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if (getCurrentSize() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return index;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for (int i = 0; i<arraySize; i++)
  {
    if (dynamBag[i] == item)
    {
      return true;
    }
  }
  return false;
}

template<typename T>
void DynamicBag<T>::clear()
{
  index = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  int count = 0;
  for (int i = 0; i<arraySize; i++)
  {
    if (dynamBag[i] == item)
    {
      count++;
    }
  }
  return count;
};
