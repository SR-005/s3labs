#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Adjacency matrix representation
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

            // Push adjacent nodes to stack (right child first for correct DFS)
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

        // Enqueue adjacent nodes (left child first)
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// Function to add an edge to the adjacency matrix
void addEdge(int u, int v) {
    if (u < MAX_NODES && v < MAX_NODES) {
        adj[u][v] = 1; // Directed graph
    }
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
    int firstNode = -1; // To store the first entered node
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(u, v); // Add the edge
        if (firstNode == -1) {
            firstNode = u; // Store the first entered node
        }
    }

    // Perform DFS and BFS starting from the first entered node
    printf("DFS Traversal: ");
    DFS(firstNode); // Starting from the first entered node

    printf ("BFS Traversal: ");
    BFS(firstNode); // Starting from the first entered node

    return 0;
}