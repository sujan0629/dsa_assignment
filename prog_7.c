#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 20
#define INF INT_MAX

// Find vertex with minimum distance value
int minDistance(int dist[], bool visited[], int vertices) {
    int min = INF, min_index = -1;
    
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Print shortest path from source to destination
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    
    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Print solution
void printSolution(int dist[], int parent[], int vertices, int src) {
    printf("\n=== Shortest Paths from Source %d ===\n", src);
    printf("Vertex\t\tDistance\tPath\n");
    
    for (int i = 0; i < vertices; i++) {
        if (i != src) {
            printf("%d -> %d\t\t", src, i);
            if (dist[i] == INF) {
                printf("INF\t\tNo path\n");
            } else {
                printf("%d\t\t", dist[i]);
                printPath(parent, i);
                printf("\n");
            }
        }
    }
}

// Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int vertices, int src) {
    int dist[MAX];           // Shortest distance from source
    bool visited[MAX];       // Visited vertices
    int parent[MAX];         // Parent array to store path
    
    // Initialize
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        // Pick minimum distance vertex
        int u = minDistance(dist, visited, vertices);
        
        if (u == -1) break; // Remaining vertices unreachable
        
        visited[u] = true;
        
        // Update distances of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] != 0 && 
                dist[u] != INF && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    printSolution(dist, parent, vertices, src);
}

// Display graph
void displayGraph(int graph[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix (Weighted Graph):\n");
    printf("   ");
    for (int i = 0; i < vertices; i++) {
        printf("%3d", i);
    }
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 0) {
                printf("  -");
            } else {
                printf("%3d", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX][MAX] = {0};
    int vertices, edges, src, dest, weight, choice, source;
    
    printf("Dijkstra's Shortest Path Algorithm\n");
    printf("===================================\n\n");
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    // Initialize graph
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            graph[src][dest] = weight;
            // For undirected graph, uncomment the line below:
            // graph[dest][src] = weight;
        }
    }
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Display graph\n");
        printf("2. Run Dijkstra's algorithm\n");
        printf("3. Add edge\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayGraph(graph, vertices);
                break;
                
            case 2:
                printf("Enter source vertex: ");
                scanf("%d", &source);
                if (source >= 0 && source < vertices) {
                    dijkstra(graph, vertices, source);
                } else {
                    printf("Invalid source vertex!\n");
                }
                break;
                
            case 3:
                printf("Enter edge (src dest weight): ");
                scanf("%d %d %d", &src, &dest, &weight);
                if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                    graph[src][dest] = weight;
                    printf("Edge added\n");
                } else {
                    printf("Invalid vertices!\n");
                }
                break;
                
            case 4:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
