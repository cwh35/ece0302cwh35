#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() 
{
  
  State<T> root = queue[0]; 

  if(queue.size() == 1)
  {
    queue.pop_back();
  }
  else
  {
    queue[0] = queue[queue.size()-1]; //get the last item in the heap and set it as the root
    queue.pop_back(); //remove the last item

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

      if(leftChild < queue.size() && queue[leftChild].getFCost() < queue[child].getFCost())
      {
        child = leftChild;
      }
      if(rightChild < queue.size() && queue[rightChild].getFCost() < queue[child].getFCost())
      {
        child = rightChild;
      }
      if(child != i) //if max gets changed to a left or right child
      {
        //swaps the parent and a child node
        State<T> temp = queue[i]; //takes the root value, stores it in temp
        queue[i] = queue[child]; //sets position i equal to child's value
        queue[child] = temp; //set child's position to temp's value
        i = child;
      }
      else
      {
        count = false;
      }
            
    }
    return root; 
  }
  
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost

  

}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  int k = queue.size();
  int j = (k-1)/2; //j is the position of the parent 
  int count = 0;
  State<T> s(p, cost, heur);

  if(queue.size() == 0)
  {
    queue.push_back(s); 
  }
  else
  {
    queue.push_back(s);
    while((j>=0) && (queue[j].getFCost() > s.getFCost())) //need to shift if item is greater than parent
    {
      if(j==0)
      {
        count++;
      }
      if(count > 1)
      {
        break;
      }
        queue.push_back(queue[j]);
        k = j; //k becomes the parent
        j = (k-1)/2; //j becomes the child
      }
        queue.push_back(s);
    }
  
  //implement this the same way we implemented push in the heap lecture.

}

template <typename T>
bool frontier_queue<T>::empty() {

  if(queue.size() == 0)
  {
    return true;
  }
  return false;
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  for(int i=0; i<queue.size(); i++)
  {
    if(p == queue[i].getValue())
    {
      return true;
    }
  }

  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) 
{
  for(int i = 0; i<queue.size(); i++)
  {
    if((queue[i].getPathCost() > cost) && (queue[i].getValue() == p))
    {
      queue[i].updatePathCost(cost);
      State<T> swap = queue[0];
      queue[0] = queue[i];
      queue[i] = swap;

      bool count = true;
      int child = 0;
      int j = 0; 
      int leftChild = 0;
      int rightChild = 0;
      
      while(count)
      {
        child = j; //set max equal to position of the parent node, starting at the root node
        leftChild = 2*j + 1;
        rightChild = 2*j + 2;

        if(leftChild < queue.size() && queue[leftChild].getFCost() < queue[child].getFCost())
        {
          child = leftChild;
        }
        if(rightChild < queue.size() && queue[rightChild].getFCost() < queue[child].getFCost())
        {
          child = rightChild;
        }
        if(child != j) //if max gets changed to a left or right child
        {
          //swaps the parent and a child node
          State<T> temp = queue[j]; //takes the root value, stores it in temp
          queue[j] = queue[child]; //sets position i equal to child's value
          queue[child] = temp; //set child's position to temp's value
          j = child;
        }
        else
        {
          count = false;
        }
      }
    }
  }
  
}


