#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() 
{
  limitedBag[25];
  index = 0;
}
template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x)
{
  index = 0;
  limitedBag[arraySize];
  for (int i = 0; i<arraySize; i++)
  {
    limitedBag[i] = x.limitedBag[i];
  }
}
    
template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag()
{}
  
template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{  
  clear();
  for (int i = 0; i<arraySize; i++)
  {
    add(x.limitedBag[i]);
  }
  return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if (index < arraySize)
  {
    limitedBag[index] = item;
    index++;
    return true;
  }
  else
  {
    return false;
  }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  bool valid;
  int count = 0;
  if(contains(item) == false) //Checks to see if item is in the bag
  {
    valid =  false;
    return valid;
  }
  while (limitedBag[count] != item)//Gets the position of the item to be removed
  {
    count++;
    valid = true;
  }
  for (count; count<getCurrentSize(); count++)
  {
      limitedBag[count] = limitedBag[count + 1];
  }
  index--;
  return valid; 
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
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
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
   return index;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  for (int i = 0; i<arraySize; i++)
  {
    if (limitedBag[i] == item)
    {
      return true;
    }
  }
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear()
{
  index = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  int count = 0;
  for (int i = 0; i<arraySize; i++)
  {
    if (limitedBag[i] == item)
    {
      count++;
    }
  }
  return count;
};
