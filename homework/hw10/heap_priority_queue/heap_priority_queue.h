
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:
    
    // return true if the priority queue is empty
    bool isEmpty();
    
    // insert item into the queue
    void add(const T& item);
    
    // remove highest priority item from the queue
    void remove();
    
    // get the item with the highest priority from the queue
    T peek();
    
private:
    
    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    if(lst.isEmpty())
    {
        return true;
    }
    return false;
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    int k = lst.getLength(); //1 indexing
    int j = (k-1)/2; //j is the position of the parent 
    int count = 0;

    if(lst.getLength() == 0)
    {
        lst.insert(0, item); //this becomes the root node
    }
    else
    {
        lst.insert(k, item); //insert the item at the last position of the heap
        while((j>=0) && (lst.getEntry(j) < item)) //need to shift if item is greater than parent
        {
            if(j==0)
            {
                count++;
            }
            if(count > 1)
            {
                break;
            }

            lst.setEntry(k, lst.getEntry(j));
            k = j; //k becomes the parent
            j = (k-1)/2;
        }
        lst.setEntry(k, item);
    }
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    if(lst.getLength() == 0)
    {
        lst.remove(0);
    }
    else
    {
        lst.setEntry(0, lst.getEntry(lst.getLength()-1)); //get the last item in the heap and set it as the root
        lst.remove(lst.getLength()-1); //remove the last item

        bool count = true;
        int child = 0;
        int i = 0; 
        int leftChild = 0;
        int rightChild = 0;

        while(count)
        {
            child = i; //set max equal to position of the parent node, starting at the root node
            leftChild = 2*i + 1;
            rightChild = 2*i + 2;

            if(leftChild < lst.getLength() && lst.getEntry(leftChild) > lst.getEntry(child)))
            {
                child = leftChild;
            }
            if(rightChild < lst.getLength() && lst.getEntry(rightChild) > lst.getEntry(child))
            {
                child = rightChild;
            }
            if(child != i) //if max gets changed to a left or right child
            {
                //swaps the parent and a child node
                T temp = lst.getEntry(i); //takes the root value, stores it in temp
                lst.setEntry(i, lst.getEntry(child)); //sets position i equal to child's value
                lst.setEntry(child, temp); //set child's position to temp's value
                i = child;
            }
            else
            {
                count = false;
            }
            
        }

    }
    
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
