# DSA Assignment 2

This repository contains solutions for Assignment #2 in Data Structure and Algorithms (COMP202).

## Tasks

1. **prog_1.c**: Check if a mathematical expression has balanced parentheses using a stack.
2. **prog_2.c**: Convert infix expression to postfix and evaluate it.
3. **prog_3.c**: Implement reverse traversal in a linked list.
4. **prog_4.c**: Implement doubly linked list with insert and delete operations.
5. **prog_5.c**: Implement undirected graph using adjacency matrix with BFS and DFS traversal.
6. **prog_6.c**: Build min and max heaps from an unsorted array.
7. **prog_7.c**: Implement Dijkstra's algorithm for shortest path in a weighted graph.
8. **prog_8.c**: Generate random integers and sort using user-selected algorithm (Bubble, Selection, Insertion, Merge Sort), with comparison and swap counts.

## Files

- `prog_<q>.c`: C source code for each task.
- `doc_<q>.md`: Documentation for each program.
- `Assignment.md`: Original assignment description.

## How to Run

Compile each C file using a C compiler (e.g., `gcc prog_1.c -o prog_1`) and run the executable.

## Submission

- Code and docs are in separate files as per guidelines.
- Repository name: `dsa_assignment`.
- Commits made gradually during development.
## Testing Instructions

Each program can be compiled and run independently:

```bash
# Compile
gcc prog_1.c -o prog_1

# Run
./prog_1
```

## Program Descriptions

### prog_1.c - Balanced Parentheses Checker
Uses stack data structure to verify if mathematical expressions have properly balanced parentheses including (), {}, and [].

### prog_2.c - Infix to Postfix Converter
Converts infix expressions to postfix notation and evaluates the result using stack-based algorithms.

### prog_3.c - Linked List Reverse Traversal
Implements singly linked list with recursive reverse traversal and list reversal functionality.

### prog_4.c - Doubly Linked List
Complete doubly linked list implementation with insert/delete operations at beginning, end, and arbitrary positions.

### prog_5.c - Graph Traversals
Undirected graph using adjacency matrix with BFS (Breadth-First Search) and DFS (Depth-First Search) implementations.

### prog_6.c - Heap Operations
Build min and max heaps from unsorted arrays with insert and delete operations maintaining heap properties.

### prog_7.c - Dijkstra's Algorithm
Find shortest paths from source vertex to all other vertices in weighted directed graph using Dijkstra's algorithm.

### prog_8.c - Sorting Algorithm Comparison
Compare performance of Bubble, Selection, Insertion, and Merge Sort by counting comparisons and swaps.

## Author
Sujan Bhatta - DSA Assignment 2 - COMP202

## License
Educational use only.

## Build Instructions

Use the provided Makefile to build all programs:

```bash
# Build all programs
make

# Build specific program
make prog_1

# Clean compiled files
make clean

# Run specific program (example)
make run_1
```

## Requirements
- GCC compiler
- C standard library
- Make utility (optional, for Makefile)

## Assignment Details
- Course: COMP202 - Data Structures and Algorithms
- Assignment: 2
- Total Programs: 8
- Each program includes complete documentation
