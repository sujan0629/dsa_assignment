# Documentation for prog_7.c

## Problem Statement
Implement Dijkstra's algorithm to find the shortest path from a source vertex to all other vertices in a weighted directed graph.

## Algorithm Overview
Dijkstra's algorithm is a greedy algorithm that finds the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights.

## Key Concepts
- **Distance Array**: Stores shortest distance from source to each vertex
- **Visited Array**: Tracks processed vertices
- **Parent Array**: Stores parent of each vertex in shortest path tree
- **Greedy Choice**: Always select unvisited vertex with minimum distance

## Algorithm Steps
1. Initialize all distances to infinity except source (distance = 0)
2. For each vertex:
   - Select unvisited vertex with minimum distance
   - Mark it as visited
   - Update distances of all adjacent unvisited vertices
3. Repeat until all vertices are visited or remaining are unreachable

## Key Functions

### `int minDistance(int dist[], bool visited[], int vertices)`
- Finds unvisited vertex with minimum distance value
- Returns index of minimum distance vertex
- **Time**: O(V)

### `void dijkstra(int graph[MAX][MAX], int vertices, int src)`
- Main algorithm implementation
- Computes shortest paths from source to all vertices
- **Time Complexity**: O(V²) for adjacency matrix
- **Space Complexity**: O(V)

### `void printPath(int parent[], int j)`
- Recursively prints path from source to vertex j
- Uses parent array to backtrack

### `void printSolution(int dist[], int parent[], int vertices, int src)`
- Displays results: distance and path for each vertex

## Time Complexity Analysis
- **Basic Implementation**: O(V²) using adjacency matrix
- **With Min-Heap**: O((V + E) log V) using adjacency list and priority queue
- Where V = number of vertices, E = number of edges

## Limitations
- Works only with non-negative edge weights
- For negative weights, use Bellman-Ford algorithm

## Applications
- GPS navigation systems
- Network routing protocols
- Social network analysis
- Robot path planning

## Sample Output
```
Enter number of vertices: 5
Enter number of edges: 7
Enter edges (src dest weight):
0 1 4
0 2 1
1 3 1
2 1 2
2 3 5
3 4 3
1 4 7

Source vertex: 0

Vertex    Distance    Path
0 -> 1    3           0 2 1
0 -> 2    1           0 2
0 -> 3    4           0 2 1 3
0 -> 4    7           0 2 1 3 4
```
