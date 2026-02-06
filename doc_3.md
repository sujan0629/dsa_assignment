# Documentation for prog_3.c

## Problem Statement
Implement reverse traversal in a singly linked list using recursion and also provide functionality to reverse the list itself.

## Data Structures

### Node
- **Fields**:
  - `int data`: Data value
  - `struct Node *next`: Pointer to next node

## Key Functions

### `Node* createNode(int data)`
Creates and initializes a new node with given data.

### `void insertAtBeginning(Node **head, int data)`
Inserts a new node at the beginning of the list. Time: O(1)

### `void insertAtEnd(Node **head, int data)`
Inserts a new node at the end of the list. Time: O(n)

### `void forwardTraversal(Node *head)`
Traverses and prints the list from head to tail. Time: O(n)

### `void reverseTraversalRecursive(Node *head)`
Recursively traverses the list in reverse order. Uses call stack to print in reverse.

### `Node* reverseList(Node *head)`
Reverses the linked list itself by changing pointers:
1. Use three pointers: prev, current, next
2. Iterate and reverse next pointers
3. Return new head

## Time Complexity
- Insert at beginning: O(1)
- Insert at end: O(n)
- Forward traversal: O(n)
- Reverse traversal: O(n) with O(n) space for recursion stack
- Reverse list: O(n) with O(1) extra space

## Sample Output
```
1. Insert at beginning
2. Insert at end
3. Forward traversal
4. Reverse traversal
5. Reverse the list

Forward: 1 2 3 4 5
Reverse: 5 4 3 2 1
```

## Memory Management
- Dynamic memory allocation using malloc
- Proper deallocation should be implemented in production code
- Memory leaks possible if nodes not freed

## Use Cases
- Undo functionality in applications
- Browser history navigation
- Music playlist management
