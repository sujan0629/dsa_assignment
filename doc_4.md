# Documentation for prog_4.c

## Problem Statement
Implement a doubly linked list with comprehensive insert and delete operations.

## Data Structures

### Node
- **Fields**:
  - `int data`: Data value
  - `struct Node *prev`: Pointer to previous node
  - `struct Node *next`: Pointer to next node

## Key Functions

### Insert Operations

#### `void insertAtBeginning(Node **head, int data)`
- Creates new node and inserts at the beginning
- Updates prev pointer of old head
- Time: O(1)

#### `void insertAtEnd(Node **head, int data)`
- Traverses to end and inserts new node
- Updates prev and next pointers
- Time: O(n)

#### `void insertAtPosition(Node **head, int data, int pos)`
- Inserts node at specified position
- Handles boundary conditions
- Time: O(n)

### Delete Operations

#### `void deleteFromBeginning(Node **head)`
- Removes first node and updates head
- Sets new head's prev to NULL
- Time: O(1)

#### `void deleteFromEnd(Node **head)`
- Traverses to last node and removes it
- Updates second-last node's next to NULL
- Time: O(n)

#### `void deleteByValue(Node **head, int value)`
- Searches for node with given value
- Updates adjacent nodes' pointers
- Time: O(n)

### Display Operations

#### `void displayForward(Node *head)`
- Traverses from head to end using next pointers
- Time: O(n)

#### `void displayBackward(Node *head)`
- Goes to end, then traverses back using prev pointers
- Time: O(n)

## Advantages of Doubly Linked List
- Bidirectional traversal
- Easy deletion given node pointer
- More efficient for certain operations

## Disadvantages
- Extra memory for prev pointer
- Slightly more complex pointer manipulation

## Sample Output
```
Forward: 1 2 3 4 5
Backward: 5 4 3 2 1

Inserted 10 at beginning
Forward: 10 1 2 3 4 5
```
