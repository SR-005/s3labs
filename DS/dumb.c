#include <stdio.h>
#include <stdlib.h>

// Linked List Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new linked list node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the linked list binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the linked list binary tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal for linked list binary tree
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal for linked list binary tree
void preorderTraversal(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal for linked list binary tree
void postorderTraversal(Node* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Array Implementation
#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;

// Function to insert a node in the array binary tree
void insertArray(int data) {
    if (size < MAX_SIZE) {
        array[size] = data;
        size++;
    } else {
        printf("Array is full\n");
    }
}

// Function to delete a node from the array binary tree
void deleteArray(int data) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == data) {
            array[i] = array[size - 1]; // Replace with the last element
            size--;
            return;
        }
    }
    printf("Key not found in the array\n");
}

// Inorder traversal for array binary tree
void inorderTraversalArray(int index) {
    if (index < size) {
        inorderTraversalArray(2 * index + 1); // Left child
        printf("%d ", array[index]);           // Node
        inorderTraversalArray(2 * index + 2); // Right child
    }
}

// Preorder traversal for array binary tree
void preorderTraversalArray(int index) {
    if (index < size) {
        printf("%d ", array[index]);           // Node
        preorderTraversalArray(2 * index + 1); // Left child
        preorderTraversalArray(2 * index + 2); // Right child
    }
}

// Postorder traversal for array binary tree
void postorderTraversalArray(int index) {
    if (index < size) {
        postorderTraversalArray(2 * index + 1); // Left child
        postorderTraversalArray(2 * index + 2); // Right child
        printf("%d ", array [index]);             // Node
    }
}

int main() {
    Node* root = NULL;

    // Linked List Binary Tree Operations
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Linked List Binary Tree Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Linked List Binary Tree Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Linked List Binary Tree Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 20);

    printf("Linked List Binary Tree Inorder Traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // Array Binary Tree Operations
    insertArray(50);
    insertArray(30);
    insertArray(20);
    insertArray(40);
    insertArray(70);
    insertArray(60);
    insertArray(80);

    printf("Array Binary Tree Inorder Traversal: ");
    inorderTraversalArray(0);
    printf("\n");

    printf("Array Binary Tree Preorder Traversal: ");
    preorderTraversalArray(0);
    printf("\n");

    printf("Array Binary Tree Postorder Traversal: ");
    postorderTraversalArray(0);
    printf("\n");

    deleteArray(20);

    printf("Array Binary Tree Inorder Traversal after deletion: ");
    inorderTraversalArray(0);
    printf("\n");

    return 0;
}
