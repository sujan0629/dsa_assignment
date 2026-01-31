#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// Queue for BFS
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Stack for DFS
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Graph structure
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;

// Initialize queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

// Enqueue
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) return;
    
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = value;
}

// Dequeue
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) return -1;
    
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isStackEmpty(Stack *s) {
    return s->top == -1;
}

// Push to stack
void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->items[++(s->top)] = value;
    }
}

// Pop from stack
int pop(Stack *s) {
    if (isStackEmpty(s)) return -1;
    return s->items[(s->top)--];
}

// Initialize graph
void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add edge to undirected graph
void addEdge(Graph *g, int src, int dest) {
    if (src >= 0 && src < g->vertices && dest >= 0 && dest < g->vertices) {
        g->adjMatrix[src][dest] = 1;
        g->adjMatrix[dest][src] = 1;
    }
}

// Display adjacency matrix
void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    printf("  ");
    for (int i = 0; i < g->vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->vertices; i++) {
        printf("%d ", i);
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// BFS traversal
void BFS(Graph *g, int startVertex) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);
    
    printf("\nBFS Traversal starting from vertex %d: ", startVertex);
    
    visited[startVertex] = 1;
    enqueue(&q, startVertex);
    
    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// DFS traversal
void DFS(Graph *g, int startVertex) {
    int visited[MAX] = {0};
    Stack s;
    initStack(&s);
    
    printf("\nDFS Traversal starting from vertex %d: ", startVertex);
    
    push(&s, startVertex);
    
    while (!isStackEmpty(&s)) {
        int currentVertex = pop(&s);
        
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }
        
        for (int i = g->vertices - 1; i >= 0; i--) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(&s, i);
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int vertices, edges, src, dest, choice, startVertex;
    
    printf("Undirected Graph - BFS and DFS Traversal\n");
    printf("=========================================\n\n");
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    initGraph(&g, vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Display graph\n");
        printf("2. BFS traversal\n");
        printf("3. DFS traversal\n");
        printf("4. Add edge\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayGraph(&g);
                break;
                
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &startVertex);
                BFS(&g, startVertex);
                break;
                
            case 3:
                printf("Enter starting vertex: ");
                scanf("%d", &startVertex);
                DFS(&g, startVertex);
                break;
                
            case 4:
                printf("Enter edge (src dest): ");
                scanf("%d %d", &src, &dest);
                addEdge(&g, src, dest);
                printf("Edge added\n");
                break;
                
            case 5:
                printf("Exiting...\n");
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
