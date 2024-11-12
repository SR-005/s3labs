#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
struct Node* root = NULL; // Declare root outside main

void insertNode() 
{ 
    int value;
    printf("Enter value to insert: "); 
    scanf("%d", &value);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 

    if (root == NULL) 
    { 
        root = newNode; 
        return; 
    } 

    struct Node* queue[100]; // Assuming a maximum of 100 nodes in the queue
    int front = 0, rear = 0; 
    queue[rear++] = root; 

    while (front < rear) 
    { 
        struct Node* current = queue[front++]; 
        if (current->left == NULL) 
        { 
            current->left = newNode; 
            return; 
        } 
        else 
        { 
            queue[rear++] = current->left; 
        } 
        if (current->right == NULL) 
        { 
            current->right = newNode; 
            return; 
        } 
        else 
        { 
            queue[rear++] = current->right; 
        } 
    } 
} 

void inorderTraversal(struct Node* root) 
{ 
    if (root != NULL) 
    { 
        inorderTraversal(root->left); 
        if (root->data == -1) 
        { 
            printf(" ");  
        } 
        else 
        { 
            printf("%d ", root->data); 
        } 
        inorderTraversal(root->right); 
    } 
} 

void preorderTraversal(struct Node* root) { 
    if (root != NULL) 
    { 
        if (root->data == -1) 
        { 
            printf(" "); 
        } 
        else 
        { 
            printf("%d ", root->data); 
        } 
        preorderTraversal(root->left); 
        preorderTraversal(root->right); 
    } 
} 

void postorderTraversal(struct Node* root) 
{ 
    if (root != NULL) 
    { 
        postorderTraversal(root->left); 
        postorderTraversal(root->right); 
        if (root->data == -1) 
        { 
            printf(" ");  
        } 
        else 
        { 
            printf("%d ", root->data); 
        } 
    } 
} 

struct Node* deleteNode(struct Node* root, int value) 
{ 
    if (root == NULL) 
    { 
        return root; 
    } 
    if (root->data == value) 
    { 
        if (root->left == NULL && root->right == NULL) 
        { 
            free(root); 
            return NULL; 
        } 
        else 
        { 
            root->data = -1;  
            return root; 
        } 
    } 
    root->left = deleteNode(root->left, value); 
    root->right = deleteNode(root->right, value); 
    return root; 
} 

int main() 
{ 
    int choice, value; 
    
    while (1) 
    { 
        printf("\nMenu:\n"); 
        printf("1. Insert Node\n"); 
        printf("2. Inorder Traversal\n"); 
        printf("3. Preorder Traversal\n"); 
        printf("4. Postorder Traversal\n"); 
        printf("5. Delete Node\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        if (choice == 1) 
        { 
            insertNode(); // No need to pass root
        } 
        else if (choice == 2) 
        { 
            printf("Inorder Traversal: "); 
            inorderTraversal(root); 
            printf("\n"); 
        }
        else if (choice == 3) 
        { 
            printf("Preorder Traversal: "); 
            preorderTraversal(root); 
            printf("\n"); 
        } 
        else if (choice == 4) 
        { 
            printf("Postorder Traversal: "); 
            postorderTraversal(root); 
            printf("\n"); 
        } 
        else if (choice == 5) 
        { 
            printf("Enter value to delete: "); 
            scanf("%d", &value); 
            root = deleteNode(root, value); 
        } 
        else if (choice == 6) 
        { 
            break; 
        } 
        else 
        { 
            printf("Invalid choice. Please try again.\n"); 
        } 
    } 
    return 0; 
} 