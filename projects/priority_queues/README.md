## Implement a heap-based priority queue
A PQ is a structure that orders data elements by priority.  Specifically, elements can be inserted into a PQ in any order, but when removing an element from a PQ, the highest-priority element is always removed first.

You must build your PQ using a [binary heap](https://en.wikipedia.org/wiki/Binary_heap).  A binary heap is a data structure that takes the form of a binary tree.  There are two different kinds of binary heaps:
  * A minimizing binary heap is organized so that the element with the *lowest* key is always at the root of the tree.
  * A maximizing binary heap is organized so that the element with the *highest* key is always at the root of the tree.
In this assignment, you will specifically base your PQ implementation on a minimizing binary heap.


The PQ functions you'll need to implement are outlined briefly below.  All of these functions use the type `struct pq`, which represents the PQ itself and which you'll have to define in `pq.c`. Here are the functions you'll have to implement:

  * **`pq_create()`** - This function should allocate, initialize, and return a pointer to a new PQ structure.

  * **`pq_free()`** - This function should free all the memory held within a PQ structure created by `pq_create()` without any memory leaks.  Note that this function only needs to free the memory held by the PQ itself.  It does not need to free the individual elements stored in the PQ.  This is the responsibility of the calling function.

  * **`pq_isempty()`** - This function should return 1 if the PQ is empty and 0 otherwise.

  * **`pq_insert()`** - This function should insert a new value with specified priority into the PQ.  **This operation must have O(log n) runtime complexity.**

  * **`pq_first()`** - This function should return the first value (i.e. the highest-priority value) from a PQ *without* removing it.  **This operation must have O(1) runtime complexity.**

  * **`pq_first_priority()`** - This function should return the *priority value* associated with the first element in a PQ *without* removing that element.  **This operation must have O(1) runtime complexity.**

  * **`pq_remove_first()`** - This function should remove the first value (i.e. the highest-priority value) from a PQ and return that value.  **This operation must have O(log n) runtime complexity.**

Your priority queue must be implemented using a minimizing binary heap as the underlying data structure.  This means that within the priority queue you implement, *lower* priority values should correspond to elements with *higher* priority.  In other words, the first element in the priority queue should be the one with the *lowest* priority value among all elements in the collection.  For example, your priority queue should return an element with priority value 0 before it returns one with priority value 10.

## Testing your work

In addition to the skeleton code provided here, you are also provided with some application code in `test_pq.c` to help verify that your PQ implementation, is behaving the way you want it to.  In particular, the testing code calls the functions from `pq.c`, passing them appropriate arguments, and then prints the results.  You can use the provided `Makefile` to compile all of the code in the project together, and then you can run the testing code as follows:
```
make
./test_pq
```
Example output of the testing program using a correct PQ implementation is provided in the `example_output/` directory.

In order to verify that your memory freeing functions work correctly, it will be helpful to run the testing application through `valgrind`.
