## 1. Implement a dynamic array

A dynamic array is simply an array that automatically grows to meet the demand for capacity as new elements are added.  Specifically, a dynamic array is a structure that simply manages a regular array, and, whenever a new element is inserted into the dynamic array, it checks to see whether the underlying array has enough space to hold the new element.  If it does, the dynamic array simply inserts the new element.  If there isn't enough space, however, the dynamic array increases the size of the underlying array (typically doubling it in size), so that there's room for the new element.  If you've used a vector from the C++ STL, then you've used a dynamic array, since that's what a C++ vector is.

The dynamic array functions you'll need to implement are outlined briefly below.  

  * **`dynarray_create()`** - This function should allocate, initialize, and return a pointer to a new dynamic array structure.

  * **`dynarray_free()`** - This function should free the memory held within a dynamic array structure created by `dynarray_create()`.  Note that this function only needs to free the `data` array itself.  It does not need to free the individual elements held within that array.  This is the responsibility of the calling function.

  * **`dynarray_size()`** - This function should return the number of elements stored in a dynamic array (*not* the capacity of the array).

  * **`dynarray_insert()`** - This function should insert a new element *at the end* of a dynamic array.  In other words, if the array currently contains `n` elements (in indices `0` through `n-1`), then the new element (the `n+1`'th element) should always be inserted at index `n`.  Also, see the information below on storing elements as `void*`.  If there is not enough space in the dynamic array to store the element being inserted, this function should double the size of the array.

  * **`dynarray_remove()`** - This function should remove the element at a specified index from a dynamic array.  After the element is removed, there will be a "hole" where the element used to be.  All elements after the removed one (i.e. with higher indices) should be moved forward one spot to fill that hole.  In other words, if the element at index `i` is removed, then the element at index `i+1` should be moved forward to index i, the element at index `i+2` should be moved forward to index `i+1`, the element at index `i+3` should be moved forward to index `i+2`, and so forth.

  * **`dynarray_get()`** - This function should return the element value stored at a specified index in a dynamic array.  Again, see the info below on using `void*` values.

  * **`dynarray_set()`** - This function should update (i.e. overwrite) the value of an element at a specified index in a dynamic array.  Again, see the info below on using `void*` values.

## 2. Implement a singly-linked list

In general, a linked list is a data structure in which each data element is stored in its own *link* structure.  A linked list is a linear data structure, like an array, where the elements are stored in sequence.  Each link in a lined list holds exactly one data element and is allocated only when needed (i.e. when the data element it contains is inserted into the list).  In addition, each link in a linked list points to either one or two adjacent links in the list.  A singly-linked list, which you'll implement here, is a list where each link points only to the next link in the list.


The linked list functions you'll need to implement are outlined briefly below.  The functions here will make use of two different structures:
  * **`struct link`** - This structure represents a single link in the linked list.  It has one field in which to store the data element associated with the link and one field that will point to the next link in the list.
  * **`struct list`** - This structure represents an entire list and contains a single field to represent the head of the list.  This is the structure with which the user of your list implementation will interact.

  * **`list_create()`** - This function should allocate, initialize, and return a pointer to a new linked list structure.

  * **`list_free()`** - This function should free the memory held within a linked list structure created by `list_create()`, including any memory allocated to the individual links themselves.  Note, though, that this function should not free the *values* held in the individual links.  That is the responsibility of the calling function.

  * **`list_insert()`** - This function should insert a new value *at the beginning* (i.e. as the head) of a linked list.  Importantly, this function will need to allocate a new `struct link` in which to store the new value and add that link at the head of the list.  The current head should become the next element after the new one.

  * **`list_remove()`** - This function should remove the *first instance* of a specified value from a linked list.  If multiple instances of the specified value exist in the list, only the first (i.e. the one closest to the head) should be removed.  If the specified value doesn't exist in the list, this function doesn't need to do anything.  This function will be passed a *function pointer* that you can use to determine whether the value to be removed matches any of the values stored in the list.  See the information below on function pointers for more about how they work.  Importantly, this function will also need to free the memory held by the link being removed (it does not need to free the stored value itself, just the link).

  * **`list_position()`** - This function should return the list position (i.e. the 0-based "index") of the first instance of a specified value within a linked list.  If multiple instances of the specified value exist in the list, the "index" of the first one (i.e. the one closest to the head) should be returned.  If no instances of the specified value exist in the list, this function should return the special value -1.  This function will be passed a *function pointer* that you can use to determine whether the value to be located matches any of the values stored in the list.  Again, see the information below on function pointers for more about how they work.

  * **`list_reverse()`** - This function should reverse a linked list *in place*, that is within the memory of the existing list, without allocating new memory.

## A note on using void pointers

The data structure implementations you'll write in this assignment use void pointers (i.e. `void*`) to store data.  You may not be familiar with the way void pointers work.  Simply put, void pointers are a mechanism that can be used to store *any* pointer type.  In other words, you can think of a void pointer as a generic pointer, capable of pointing to values of any type.  They are often used in C/C++ data structure implementations to allow those data structures to store data of many different types without needing to change the underlying source code of the data structure for each type.

Working with void pointers means you, the data structure implementor, don't have to worry about the *content* that's being stored in your data structures.  The structures themselves are agnostic to the content.  When outside functions call operations on your data structures, they will pass in values of *some* pointer type.  It is up to those calling functions to remember the type of data being stored in your data structures and to handle it accordingly.  In other words, when a calling function inserts data into your data structures, it will arrive as a `void*`, and your function can just take that `void*` and put it in the right place without doing anything additional to it.  Similarly, when one of your data structures returns a stored value to a calling function, it can simply return the `void*` it stored earlier without doing any additional casting, etc.

## A note on function pointers

Often, particular operations for a given data structure will need to be able to make *comparisons* involving the stored values they hold.  This can be challenging when the data structure doesn't know what *type* of values it's holding, as is the case here, where our data structures are storing `void*` values without additional type information.  It is common in these situations, where a data structure must compare values stored as `void*`, for the data structure to require the calling function itself to provide a mechanism for performing these comparisons.  In C code, this is typically done by requiring the calling function to pass the data structure *a pointer to a function* that can compare the values stored in the data structure.  This is known as a function pointer.

In this assignment, some of the linked list functions must be passed function pointers to be used when comparing values to determine what elements exist within the list.  When a pointer to a function is passed to another function, it must match a pre-specified function prototype.  The prototype required by the function pointers specified in those linked list functions looks like this:
```C
int cmp(void* a, void* b);
```
In other words, the function pointer must point to a function that returns an `int` and accepts exactly two `void*` arguments.  In this case, the function will return 0 if the argument `a` should be considered as equal to the argument `b`, and it will return a non-zero value otherwise.

It is important to note that, again, the linked list functions here can be agnostic to what the functions specified by these pointers are actually doing.  They just need to call the function at the right time, passing the right parameters and doing the right thing with the return value.  For example, within the `list_remove()` function, you'll want to use the provided function pointer to perform comparisons between the value to be removed and the values stored in the list.  In particular, if the value to be removed is stored in `val` and you're currently comparing to the value stored in a link called `link`, you can use the comparison function specified by the function pointer `cmp` like this:
```C
cmp(val, link->val)
```
This will return 0 if `val` and `link->val` are equal and a non-zero value otherwise.

It will be instructive here to look in `test.c` to see how functions are actually passed as pointers into `list_remove()` and `list_position()`.  You can also refer to these tutorials for more in function pointers in general:
  * https://www.cprogramming.com/tutorial/function-pointers.html
  * https://www.learn-c.org/en/Function_Pointers

## Testing work

You have been provided with some application code in `test_dynarray.c` and `test_list.c` to help verify that your dynamic array and linked list implementations, respectively, are behaving the way you want them to.  In particular, the testing code calls the functions from `dynarray.c` and `list.c`, passing them appropriate arguments, and then prints the results.  You can use the provided `Makefile` to compile all of the code in the project together, and then you can run the testing code as follows:
```
make
./test_dynarray
./test_list
```
Example output of these two testing programs using correct implementations of the dynamic array and linked list is provided in the `example_output/` directory.

In order to verify that your memory freeing functions work correctly, it will be helpful to run the testing application through `valgrind`.
