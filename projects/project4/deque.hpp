#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include "linked_list.hpp"
template <typename T>
class Deque: public AbstractDeque<T>{

  public:
  
  //constructor
  Deque();

  //constructor with parameter
  Deque(const Deque& x);

  //destructor
  ~Deque();

  //copy constructor
  Deque<T>& operator=(const Deque& x);

  /** Returns true if the deque is empty, else false
   */
  bool isEmpty() const noexcept;

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
  void pushFront(const T & item);

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popFront();

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  T front() const;

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
  void pushBack(const T & item);

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popBack();

  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  T back() const;

  private:
  LinkedList<T> l; //using composition
};

#include "deque.tpp"

#endif
