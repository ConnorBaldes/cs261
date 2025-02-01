## 1. Implement a stack

In this assignment, you'll implement two new ADTs on top of the data structures you implemented in the previous assignment.  The first ADT you'll implement for this assignment is a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)).

A stack is a data type that only allows its user to work with one end of the collection being stored, which is referred to as the "top".  Each new element must be inserted at the top of the stack, and only the element at the top of the stack (which is always the most recently added) may be removed.  This constraint means that elements in a stack are ordered in "last in, first out" (or LIFO) order.  In this way, the stack ADT behaves much like a physical stack, for example, a stack of books or of dishes, where we can only add and remove items to and from the top of the stack.

The stack functions you'll need to implement are outlined briefly below:
  * **`stack_create()`** - This function should allocate, initialize, and return a pointer to a new stack structure.

  * **`stack_free()`** - This function should free the memory held within a stack structure created by `stack_create()`.  Note that this function only needs to free the memory held by the stack itself.  It does not need to free the individual elements stored in the stack.  This is the responsibility of the calling function.

  * **`stack_isempty()`** - This function should return 1 if the stack is empty and 0 otherwise.

  * **`stack_push()`** - This function should insert a new element on top of the stack.  **This operation must have O(1) average runtime complexity.**

  * **`stack_top()`** - This function should return the value stored at the top of the stack without removing it.  **This operation must have O(1) average runtime complexity.**

  * **`stack_pop()`** - This function should pop a value from the stack and return the popped value.  **This operation must have O(1) average runtime complexity.**

Importantly, the stack you build **MUST** use a linked list as its underlying data storage. 

## 2. Implement a queue

A [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)).  A queue is a two-ended data structure where all elements must be inserted at one end of the queue (the "back") and can only be removed from the other end of the queue (the "front").  In this way, elements stored in a queue are ordered in "first in, first out" (FIFO) order.  In other words, each element removed from a queue will always be the one that was inserted before all the other elements stored in the queue.  Thus, the queue ADT works much like a line like you'd encounter at a grocery store or amusement park, where the first ones to enter the line are the first ones who get to check out or ride a ride (much of the world outside the US actually calls a line like this a "queue").


The queue functions you'll need to implement are outlined briefly below:

  * **`queue_create()`** - This function should allocate, initialize, and return a pointer to a new queue structure.

  * **`queue_free()`** - This function should free the memory held within a queue structure created by `queue_create()`.  Note that this function only needs to free the memory held by the queue itself.  It does not need to free the individual elements stored in the queue.  This is the responsibility of the calling function.

  * **`queue_isempty()`** - This function should return 1 if the queue is empty and 0 otherwise.

  * **`queue_enqueue()`** - This function should insert a new element at the back of the queue.  **This operation must have O(1) average runtime complexity.**

  * **`queue_front()`** - This function should return the value stored at the front of the queue without removing it.  **This operation must have O(1) average runtime complexity.**

  * **`queue_dequeue()`** - This function should dequeue a value from the queue and return the dequeued value.  **This operation must have O(1) average runtime complexity.**

Importantly, the queue you build **MUST** use a dynamic array as its underlying data storage. Also, note that, as with the data structures you implemented in assignment 1, values in the queue will be stored as void pointers.

## Testing your work

In addition to the skeleton code provided here, you are also provided with some application code in `test_stack.c` and `test_queue.c` to help verify that your stack and queue implementations, respectively, are behaving the way you want them to.  In particular, the testing code calls the functions from `stack.c` and `queue.c`, passing them appropriate arguments, and then prints the results.  You can use the provided `Makefile` to compile all of the code in the project together, and then you can run the testing code as follows:
```
make
./test_stack
./test_queue
```
Example output of these two testing programs using correct implementations of the stack and queue is provided in the `example_output/` directory.

In order to verify that your memory freeing functions work correctly, it will be helpful to run the testing applications through `valgrind`.
