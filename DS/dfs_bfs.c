#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Adjacency list representation
int adj[MAX_NODES][MAX_NODES]; // adjacency matrix
int visited[MAX_NODES]; // visited array
int n; // number of nodes

// Stack structure for DFS
int stack[MAX_NODES];
int top = -1;

// Queue structure for BFS
int queue[MAX_NODES];
int front = -1;
int rear = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top < MAX_NODES - 1) {
        stack[++top] = value;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1; // Stack underflow
}

// Function to enqueue an element in the queue
void enqueue(int value) {
    if (rear < MAX_NODES - 1) {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = value;
    }
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front != -1 && front <= rear) {
        return queue[front++];
    }
    return -1; // Queue underflow
}

// Function to perform DFS
void DFS(int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0; // Initialize visited array
    }

    push(start);
    while (top != -1) {
        int node = pop();
        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;

            // Push adjacent nodes to stack
            for (int i = n - 1; i >= 0; i--) { // Reverse order for correct DFS
                if (adj[node][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
}

// Function to perform BFS
void BFS(int start) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0; // Initialize visited array
    }

    enqueue(start);
    visited[start] = 1;

    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        // Enqueue left child (next node in adjacency list)
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// Function to add an edge to the adjacency list
void addEdge(int u, int v) {
    adj[u][v] = 1; // Directed graph
    adj[v][u] = 1; // Uncomment this line for undirected graph
}

// Main function
int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Perform DFS and BFS
    printf("DFS Traversal: ");
    DFS(0); // Starting from node 0

    printf("BFS Traversal: ");
    BFS(0); // Starting from node 0

    return 0;
}