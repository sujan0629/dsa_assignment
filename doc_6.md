# Documentation for prog_6.c

## Problem Statement
Build min heap and max heap from an unsorted array and perform heap operations.

## Data Structures
- **Array-based Heap**: Complete binary tree stored in array
- **Indexing**: 
  - Parent of node i: (i-1)/2
  - Left child of node i: 2*i + 1
  - Right child of node i: 2*i + 2

## Key Functions

### Heapify Operations

#### `void maxHeapify(int arr[], int n, int i)`
- Maintains max heap property for subtree rooted at index i
- Compares node with children and swaps with largest
- Recursively heapifies affected subtree
- **Time**: O(log n)

#### `void minHeapify(int arr[], int n, int i)`
- Maintains min heap property for subtree rooted at index i
- Compares node with children and swaps with smallest
- Recursively heapifies affected subtree
- **Time**: O(log n)

### Build Heap Operations

#### `void buildMaxHeap(int arr[], int n)`
- Converts unsorted array into max heap
- Starts from last non-leaf node and heapifies bottom-up
- **Time**: O(n) - tighter analysis than O(n log n)

#### `void buildMinHeap(int arr[], int n)`
- Converts unsorted array into min heap
- Starts from last non-leaf node and heapifies bottom-up
- **Time**: O(n)

### Insert Operations

#### `void insertMaxHeap(int arr[], int *n, int value)`
- Inserts element at end, then bubbles up to maintain max heap property
- **Time**: O(log n)

#### `void insertMinHeap(int arr[], int *n, int value)`
- Inserts element at end, then bubbles up to maintain min heap property
- **Time**: O(log n)

### Delete Operations

#### `int deleteMax(int arr[], int *n)`
- Removes root (maximum element)
- Replaces root with last element
- Heapifies down from root
- **Time**: O(log n)

#### `int deleteMin(int arr[], int *n)`
- Removes root (minimum element)
- Replaces root with last element
- Heapifies down from root
- **Time**: O(log n)

## Heap Properties
- **Max Heap**: Parent ≥ Children
- **Min Heap**: Parent ≤ Children
- **Complete Binary Tree**: All levels filled except possibly last, filled left to right

## Applications
- Priority queues
- Heap sort (O(n log n))
- Finding k largest/smallest elements
- Median maintenance

## Sample Output
```
Enter 6 elements: 4 10 3 5 1 8

Original array: 4 10 3 5 1 8
Max Heap: 10 5 8 4 1 3
Min Heap: 1 3 4 5 10 8
```
