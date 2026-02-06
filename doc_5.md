# Documentation for prog_5.c

## Problem Statement
Implement an undirected graph using adjacency matrix and perform BFS (Breadth-First Search) and DFS (Depth-First Search) traversals.

## Data Structures

### Queue (for BFS)
- **Fields**:
  - `int items[MAX]`: Array to store vertices
  - `int front, rear`: Queue pointers

### Stack (for DFS)
- **Fields**:
  - `int items[MAX]`: Array to store vertices
  - `int top`: Stack pointer

### Graph
- **Fields**:
  - `int vertices`: Number of vertices
  - `int adjMatrix[MAX][MAX]`: Adjacency matrix

## Key Functions

### Graph Operations
- `void initGraph(Graph *g, int vertices)`: Initialize graph with given vertices
- `void addEdge(Graph *g, int src, int dest)`: Add undirected edge
- `void displayGraph(Graph *g)`: Display adjacency matrix

### BFS Algorithm
1. Start from a vertex and mark it visited
2. Enqueue the vertex
3. While queue is not empty:
   - Dequeue a vertex
   - Visit all unvisited adjacent vertices
   - Mark them visited and enqueue them
4. **Time Complexity**: O(V²) for adjacency matrix
5. **Space Complexity**: O(V) for queue and visited array

### DFS Algorithm
1. Start from a vertex and push to stack
2. While stack is not empty:
   - Pop a vertex
   - If not visited, mark visited
   - Push all unvisited adjacent vertices
3. **Time Complexity**: O(V²) for adjacency matrix
4. **Space Complexity**: O(V) for stack and visited array

## Adjacency Matrix
- Undirected graph: Matrix is symmetric
- adjMatrix[i][j] = 1 if edge exists between vertices i and j
- adjMatrix[i][j] = 0 otherwise

## Applications
- **BFS**: Shortest path in unweighted graph, level-order traversal
- **DFS**: Topological sorting, cycle detection, path finding

## Sample Output
```
Enter number of vertices: 5
Enter number of edges: 5
Enter edges: 
0 1
0 2
1 3
2 3
3 4

BFS Traversal starting from vertex 0: 0 1 2 3 4
DFS Traversal starting from vertex 0: 0 2 3 4 1
```

## Graph Representation Comparison
- **Adjacency Matrix**: O(V²) space, O(1) edge lookup, good for dense graphs
- **Adjacency List**: O(V+E) space, O(V) edge lookup, good for sparse graphs

## Additional Graph Algorithms
- Topological Sort
- Cycle Detection
- Connected Components
- Minimum Spanning Tree (Prim's, Kruskal's)
