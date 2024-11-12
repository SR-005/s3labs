#include <stdio.h> 
void buildtree(int a[], int i, int item)  
{ 
    int ch, val; 
    a[i] = item;

    printf("\nDo you want to create a left child for %d (1/0): ", item); 
    scanf("%d", &ch); 
    if (ch == 1)  
    { 
        printf("\nEnter the left child: "); 
        scanf("%d", &val); 
        buildtree(a, 2 * i, val); 
    }

    printf("\nDo you want to create a right child for %d (1/0): ", item); scanf("%d", &ch); 
    if (ch == 1)  
    { 
        printf("Enter the right child: "); 
        scanf("%d", &val); 
        buildtree(a, 2 * i + 1, val); 
    } 
} 

void deleteNode(int a[], int i)  
{ 
    if (i >= 100 || a[i] == -1)  
    { 
        printf("\nNode at index %d does not exist.\n", i); 
        return; 
    } 

    printf("\nNode at index %d deleted\n", i); 
    a[i] = -1; 
}

void preorder(int a[], int i)  
{ 
    if (i >= 100 || a[i] == -1) 
    return; 
    printf("%d ", a[i]); 
    preorder(a, 2 * i); 
    preorder(a, 2 * i + 1); 
}

void inorder(int a[], int i)  
{ 
    if (i >= 100 || a[i] == -1) 
    return;

    inorder(a, 2 * i); 
    printf("%d ", a[i]); 
    inorder(a, 2 * i + 1); 
} 

void postorder(int a[], int i)  
{ 
    if (i >= 100 || a[i] == -1) 
        return; 
    postorder(a, 2 * i); 
    postorder(a, 2 * i + 1); 
    printf("%d ", a[i]); 
}

int main()  
{
    int i, a[100], item, delindex; 
    for (i = 0; i < 100; i++)  
    { 
        a[i] = -1; 
    } 

    printf("\nEnter the root node: "); 
    scanf("%d", &item); 
    buildtree(a, 1, item); 

    printf("\nBinary tree array before deletion:\n"); 
    for (i = 1; i <= 16; i++)  
    { 
        if (a[i] == -1) 
            printf(" "); 
        else 
            printf("%d\t", a[i]); 
    } 

    printf("\nInorder traversal before deletion: "); 
    inorder(a, 1); 

    printf("\nPostorder traversal before deletion: "); 
    postorder(a, 1); 

    printf("\nPreorder traversal before deletion: "); 
    preorder(a, 1); 

    printf("\n\nEnter the index of the node to delete: "); 
    scanf("%d", &delindex); 
    deleteNode(a, delindex); 

    printf("\nBinary tree array after deletion:\n");
    for (i = 1; i <= 16; i++)  
    { 
        if (a[i] == -1) 
            printf(" ");
        else 
            printf("%d\t", a[i]); 
    } 
    return 0; 
}
