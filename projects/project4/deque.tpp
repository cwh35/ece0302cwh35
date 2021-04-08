#include "deque.hpp"


//constructor
template<typename T>
Deque<T>::Deque()
{}

//constructor with parameter
template<typename T>
Deque<T>::Deque(const Deque& x)
{
    l = x.l;
}

//destructor
template<typename T>
Deque<T>::~Deque()
{}

//copy constructor
template<typename T>
Deque<T>& Deque<T> :: operator=(const Deque& x)
{
    l = x.l;
    return *this;
}

template<typename T>
bool Deque<T>::isEmpty() const noexcept
{
    return l.isEmpty();
}

template<typename T>
void Deque<T>::pushFront(const T & item)
{
    l.insert(1,item); //insert into the first position
}
  
template<typename T>
void Deque<T>::popFront()
{
    if(isEmpty()) //check if queue is empty
    {
        throw std::runtime_error ("Nothing to deque");
    }
    l.remove(1); //remove first position
}

template<typename T>
T Deque<T>::front() const
{
    if(isEmpty()) //check if queue is empty
    {
        throw std::runtime_error ("Nothing to deque");
    }
    return l.getEntry(1); //get the item in the first position
}

template<typename T>
void Deque<T>::pushBack(const T & item)
{
    l.insert(l.getLength()+1, item);
}

template<typename T>
void Deque<T>::popBack()
{
    if(isEmpty()) //check if queue is empty
    {
        throw std::runtime_error ("Nothing to deque");
    }
    l.remove(l.getLength());
}

template<typename T>
T Deque<T>::back() const
{
    if(isEmpty()) //check if queue is empty
    {
        throw std::runtime_error ("Nothing to deque");
    }
    return l.getEntry(l.getLength());
}


