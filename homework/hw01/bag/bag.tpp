#include "bag.hpp"                                                                                                     

template <typename T> Bag<T>::Bag() 
{
    bag.resize(0);
}

template <typename T> Bag<T>::~Bag() {}

template <typename T> std::size_t Bag<T>::getCurrentSize() const 
{ 
    return bag.size(); 
}

template <typename T> bool Bag<T>::isEmpty() const 
{ 
    if (bag.size() == 0)
    {
        return true;
    }
    else
    {
        return false; 
    }
}

template <typename T> bool Bag<T>::add(const T& entry) 
{ 
    bag.push_back(entry);
        return true;
}

template <typename T> bool Bag<T>::remove(const T& entry) 
{ 
    for(int i=0; i<bag.size(); i++)
    {
        if (bag[i] == entry)
        {
            bag.erase(i+bag.begin());
            return true;
        }
    }
    return false;
}


template <typename T> void Bag<T>::clear() 
{
    bag.clear();
}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const 
{ 
    int count=0;
    for (int i=0; i<bag.size(); i++)
    {
        if(bag[i] == entry)
        {
            count++;
        }
    }
    return count; 
}

template <typename T> bool Bag<T>::contains(const T& entry) const 
{ 
    for (int i=0; i<bag.size(); i++)
    {
        if(bag[i] == entry)
        {
            return true;
        }
    } 
    return false; 
}

