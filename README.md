# CS261: Data Structures

CS261 focuses on the design, implementation, and analysis of fundamental data structures essential for efficient algorithm development. The course emphasizes both theoretical and practical aspects, ensuring a deep understanding of data organization and management. The projects in this repository provide hands-on experience with key data structures, reinforcing concepts through implementation and complexity analysis.

## Key Topics
- **Abstract Data Types (ADTs)**: Conceptual models such as collections, stacks, queues, and maps.
- **Data Structures**: Dynamic arrays, linked lists, binary search trees, heaps, and hash tables.
- **Algorithm Complexity Analysis**: Evaluating time and space efficiency of data structures.
- **Memory Management**: Understanding space utilization in dynamic structures.
- **C Programming**: Implementing data structures efficiently in C.
- **Git & GitHub**: Version control for managing source code.

## Course Objectives
By completing this course and its projects, one will:
- Describe properties and behaviors of fundamental ADTs.
- Implement and analyze dynamic arrays, linked lists, trees, and priority queues.
- Evaluate asymptotic time complexity of algorithms and operations.
- Compare trade-offs in efficiency, space usage, and implementation complexity.
- Develop reusable, modular data structures suited for various applications.

## Repository Structure
The repository is structured around key projects that explore different data structures:
```
cs261/ 
│── README.md 
│── .git/ 
└── projects/ 
    ├── dynamic_arrays_and_linked_lists/ 
    ├── stacks_and_queues/ 
    ├── binary_search_trees/ 
    ├── priority_queues/
```

### **Project Breakdown**
- **Dynamic Arrays & Linked Lists**: Implementing resizable arrays and pointer-based structures.
- **Stacks & Queues**: Understanding LIFO and FIFO operations with efficient implementations.
- **Binary Search Trees**: Exploring tree-based storage, search, and balancing techniques.
- **Priority Queues**: Implementing heaps and understanding efficient priority-based operations.

## Course Philosophy
As Linus Torvalds states, *"Bad programmers worry about the code. Good programmers worry about data structures and their relationships."*  
This course transitions from writing code to designing efficient, scalable, and maintainable data structures—bridging the gap between hobbyist programming and professional software development.

## Projects

The projects in this repository focus on implementing fundamental data structures in C, reinforcing key concepts such as dynamic memory allocation, complexity analysis, and data organization. Each project builds upon the previous, forming a comprehensive data structure library.

### **Dynamic Arrays & Linked Lists**
Located in: [`projects/dynamic_arrays_and_linked_lists/`](./projects/dynamic_arrays_and_linked_lists/)

This project explores two foundational data structures: **dynamic arrays** and **singly-linked lists**.

#### [**Dynamic Array Implementation**](./projects/dynamic_arrays_and_linked_lists/dynarray.c)
A **dynamic array** is an array that automatically resizes as elements are added. This project involves implementing core operations such as insertion, deletion, and resizing.

| Function         | Description |
|-----------------|-------------|
| `dynarray_create()`  | Allocates and initializes a new dynamic array. |
| `dynarray_free()`  | Releases memory allocated for the dynamic array. |
| `dynarray_size()`  | Returns the number of elements stored in the array. |
| `dynarray_insert()`  | Adds a new element at the end of the array. If capacity is exceeded, the array resizes (typically doubles in size). |
| `dynarray_remove()`  | Removes an element at a specified index and shifts subsequent elements forward. |
| `dynarray_get()`  | Retrieves an element at a given index. |
| `dynarray_set()`  | Overwrites the value of an element at a given index. |

##### **Concepts Covered**
- **Abstract Data Types (ADTs)**: Demonstrates the **indexed collection** ADT.
- **Memory Management**: Efficient allocation and resizing of dynamically allocated memory.
- **Complexity Analysis**: Understanding **O(1) amortized insertion**, **O(n) removal**, and **O(1) access**.




#### [**Singly-Linked List Implementation**](./projects/dynamic_arrays_and_linked_lists/list.c)
A **singly-linked list** consists of nodes where each node holds a value and a pointer to the next node. Unlike arrays, linked lists do not require contiguous memory allocation.

| Function         | Description |
|-----------------|-------------|
| `list_create()`  | Allocates and initializes a new linked list. |
| `list_free()`  | Releases all memory held by the linked list. |
| `list_insert()`  | Inserts a new value at the head of the list. |
| `list_remove()`  | Removes the first occurrence of a specified value. |
| `list_position()`  | Returns the index of a specified value (or `-1` if not found). |
| `list_reverse()`  | Reverses the linked list in place. |

##### **Concepts Covered**
- **Linear Data Structures**: Introduction to **sequential access storage**.
- **Memory Efficiency**: Avoids resizing overhead by allocating nodes dynamically.
- **Algorithm Complexity**: Understanding **O(1) insertion** and **O(n) search/removal**.

---

### **Stack & Queue Implementations**
Located in: [`projects/stacks_and_queues/`](./projects/stacks_and_queues/)

This project focuses on implementing two essential data structures: **stack** and **queue**, using a linked list and dynamic array as their underlying storage mechanisms, respectively.

#### [**Stack Implementation**](./projects/stacks_and_queues/stack.c)
A **stack** follows the Last-In-First-Out (LIFO) principle, where elements are added and removed from the top.

| Function         | Description |
|-----------------|-------------|
| `stack_create()`  | Allocates and initializes a new stack. |
| `stack_free()`    | Frees the memory used by the stack. |
| `stack_isempty()` | Checks if the stack is empty. |
| `stack_push()`    | Inserts a new element at the top. |
| `stack_top()`     | Returns the top element without removing it. |
| `stack_pop()`     | Removes and returns the top element. |

##### **Concepts Covered**
- **Abstract Data Types (ADTs)**: Stack as a LIFO collection.
- **Memory Management**: Using a linked list for dynamic storage.
- **Complexity Analysis**: Understanding **O(1)** operations for push, pop, and top.

#### [**Queue Implementation**](./projects/stacks_and_queues/queue.c)
A **queue** follows the First-In-First-Out (FIFO) principle, where elements are added at the back and removed from the front.

| Function         | Description |
|-----------------|-------------|
| `queue_create()`  | Allocates and initializes a new queue. |
| `queue_free()`    | Frees the memory used by the queue. |
| `queue_isempty()` | Checks if the queue is empty. |
| `queue_enqueue()` | Inserts a new element at the back. |
| `queue_front()`   | Returns the front element without removing it. |
| `queue_dequeue()` | Removes and returns the front element. |

##### **Concepts Covered**
- **Abstract Data Types (ADTs)**: Queue as a FIFO collection.
- **Memory Management**: Using a dynamic array for efficient storage.
- **Complexity Analysis**: Understanding **O(1)** operations for enqueue, dequeue, and front.

---

### **Binary Search Tree Implementation**
Located in: [`projects/binary_search_trees/`](./projects/binary_search_trees/)

This project involves implementing a **binary search tree (BST)** for managing key/value pairs. The BST enforces the property that all keys in the left subtree are less than a node’s key, while all keys in the right subtree are greater than or equal to it.

#### [**Binary Search Tree Implementation**](./projects/binary_search_trees/bst.c)

The BST is implemented using nodes defined as follows:
```c
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};
```
Nodes are organized based on integer keys, facilitating efficient insertions, lookups, and removals.

| Function         | Description |
|-----------------|-------------|
| bst_create() | Allocates, initializes, and returns a new BST. |
| bst_free() | Frees the memory held by the BST (excluding individual element memory). | 
| bst_size() | Recursively calculates and returns the total number of nodes in the BST. |
| bst_insert() | Inserts a new key/value pair while maintaining the BST property. |
| bst_remove() | Removes the first encountered node with the specified key. |
| bst_get() | Retrieves the value associated with a specified key. |

##### **Concepts Covered**
- **Abstract Data Types (ADTs):** Managing key/value pairs within a BST structure.
- **Memory Management:** Dynamic allocation and recursive deallocation.
- **Algorithm Complexity:** Recursive operations for insertion, removal, and size computation.
- **Data Organization:** Structuring data for efficient search, insertion, and deletion.

#### Testing Your Work
Compile and test the BST implementation using the provided Makefile and test_bst.c:
```bash
make
./test_bst
```
For memory management verification, run the tests through valgrind.

---

### **Heap-Based Priority Queue Implementation**
Located in: [`projects/priority_queues/`](./projects/priority_queues/)

This project involves implementing a **priority queue (PQ)** using a **minimizing binary heap**. The heap structure ensures that the element with the lowest priority value is always accessible at the root, providing efficient insertion and removal of elements based on their priority.

#### [**Priority Queue Implementation**](./projects/priority_queues/pq.c)
The PQ is implemented using a minimizing binary heap, where lower priority values correspond to higher priority elements. The following operations are supported:

| Function         | Description |
|-----------------|-------------|
| `pq_create()`  | Allocates, initializes, and returns a new priority queue (PQ). |
| `pq_free()`    | Frees all memory used by the priority queue, excluding the individual elements. |
| `pq_isempty()` | Checks if the PQ is empty. |
| `pq_insert()`  | Inserts a new value with a specified priority into the PQ. |
| `pq_first()`   | Returns the highest-priority value (lowest priority) without removing it. |
| `pq_first_priority()` | Returns the priority value of the highest-priority element without removing it. |
| `pq_remove_first()` | Removes and returns the highest-priority value from the PQ. |

##### **Concepts Covered**
- **Binary Heap**: Min-heap structure where the smallest key is always at the root.
- **Algorithm Complexity**: **O(log n)** for insertions and removals, **O(1)** for accessing the highest-priority element.
- **Data Organization**: Organizing elements by priority for efficient access and modification.

##### **Testing Your Work**
Compile and test the priority queue implementation using the provided `Makefile` and `test_pq.c`:
```bash
make
./test_pq
```
For memory management verification, run the tests through valgrind.