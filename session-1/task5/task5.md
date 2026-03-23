
# Queue

## Dynamic array data structure

Data: { int value }

Queue: { int blockSize, int size, Data *data[], int front, int back }

## Queue functions

### Memory management: 

create data structures, reallocate data structures, free data structures

### Queue operations: 

`join()` and `leave()`

### Display: 

Traversal operations are now a simple for-loop between back and front indices

## Tasks


### 1. Implement the queue

- The array-based stack can be used as a starting point
    - Plan your changes carefully
    - Sketch out operations before implementing
    - Implement incrementally and compile regularly
    - For example:
        1. define the `Queue` data structure
        2. implement and test the `createQueue()` function
        3. implement and test the `join()` function
        4. implement and test the `leave()` function
- Modify `stack_structures.h`
    - Define a queue structure by adding the `front` and `back` indices
    - It makes sense for `back` to be the "upper" index as that is where we join
- Modify `stack.c` and `stack.h`
    - Define `join()` and `leave()` operations
    - ensure to suitably modify `front` and `back` indices
- Rename files appropriately and modify the `Makefile` 
    - test compilation
    - test with `valgrind`

### 2. Compare the implementations

- Compare to the struct implementation in Task 4
    - Which parts are simpler?
    - Which are more complex?

- Which implementation would be preferred in general?

### 3. Challenge task

- How would you manage memory in the queue better?
- Implement a `shiftQueue()` function that removes the "hole" at the start
- When, or how often, would you use this function to be more efficient?