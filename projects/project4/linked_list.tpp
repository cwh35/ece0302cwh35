#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
  delete head;
  head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  size = 0;
  for(int i=1; i<x.getLength()+1; i++)
  {
    insert(i, x.getEntry(i));
  }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  LinkedList<T> temporary; //variable used to swap
  temporary = x; //places value of x in variable temporary
  x = y; //sets y equal to x
  y = temporary; //sets x (or temporary) equal to y
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  clear();
  for(int i=1; i<x.getLength()+1; i++)
  {
    insert(i, x.getEntry(i));
  }
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if (size == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  return size;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  Node<T> *newNode = new Node<T>; //create new node and allocate memory

  if(position < 1 || position > size+1)
  {
    return false; //If position is not within the limits
  }
  else if (position == 1)
  {
    newNode->setItem(item); //set the item
    newNode->setNext(head); //make node point to former first node
    head = newNode; //set head pointer point to the new node
    size++; //increment size
    return true;
  }
  else
  {
    Node<T> *previous = head;
    Node<T> *post = head;

    for(int i=1; i<position-1; i++)
    {
      previous = previous->getNext();
    }
    post = previous->getNext();

    newNode->setItem(item);
    newNode->setNext(post);

    previous->setNext(newNode);
    size++;
  }
  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  Node<T> *post = head;
  Node<T> *previous;
  if(position < 1 || position > size+1)
  {
    return false;
  }
  else if (position == 1)
  {
    head = post->getNext();
    delete post;
    size--;
    return true;
  }
  else
  {
    for(int i = 1; i<position +1; i++)
    {
      previous = post;
      post = post->getNext();
    }
    previous->setNext(post->getNext());
    delete post;
    size--;
    return true;
  }
}

template <typename T>
void LinkedList<T>::clear()
{
  head = nullptr;
  size = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  Node<T> *post = head;
  for(int i = 1; i < position; i++)
  {
    post = post->getNext();
  }
  return post->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  Node<T> *post = head;
  for(int i = 1; i < position; i++)
  {
    post = post->getNext();
  }
  post->setItem(newValue);
}
