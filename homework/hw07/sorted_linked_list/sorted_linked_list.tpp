#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
   for(int i=0; i<getLength(); i++)
   {
     if(item < LinkedList<T>::getEntry(i))
     {
       LinkedList<T>::insert(i, item);
       return;
     }
   }
   LinkedList<T>::insert(getLength(),item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  for(int i=0; i<getLength(); i++)
   {
     if(item == LinkedList<T> :: getEntry(i))
     {
       LinkedList<T>::remove(i);
       return;
     }
   }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  bool valid;
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  valid = LinkedList<T> :: remove(position);
  if(valid == false)
  {
    throw std::range_error("Invalid Range");
  }
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  for(int i=0; i<getLength(); i++)
  {
    if(LinkedList<T>::getEntry(i) == newValue)
    {
      return i;
    }
  }
}
