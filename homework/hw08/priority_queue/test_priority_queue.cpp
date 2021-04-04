#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

TEST_CASE("Testing Priority Queue", "[priority queue]")
{
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  REQUIRE(pq.isEmpty());
  pq.add(60);
  pq.add(7);
  pq.add(102);
  pq.add(79);
  REQUIRE(pq.peek() == 102);

  pq.remove();
  REQUIRE(pq.peek() == 79);
  
}

