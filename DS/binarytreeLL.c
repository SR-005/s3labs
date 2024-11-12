#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* root=NULL;

void InsertNode()
{
    int value;
    printf("Enter the Value to Insert: ");
    scanf("%d",&value);

    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;
        return;
    }

    struct Node* queue[100];
    int front=0,rear=0;
    queue[rear]=root;
    rear++;

    while(rear>front)
    {
        struct Node* current=queue[front];
        front++;

        if(current->left==NULL)
        {
            current->left=newnode;
            return;
        }
        else
        {
            queue[rear]=current->left;
            rear++;
        }
        if(current->right==NULL)
        {
            current->right=newnode;
            return;
        }
        else
        {
            queue[rear]=current->right;
            rear++;
        }
    }
}

struct Node* DeleteNode(struct Node* root,int value)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==value)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else
        {
            root->data=-1;
            return root;
        }
    }
    root->left=DeleteNode(root->left,value);
    root->right=DeleteNode(root->right,value);
    return root;
}

void Inorder(struct Node* root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        if(root->data==-1)
        {
            printf(" ");
        }
        else
        {
            printf("%d ",root->data);
        }
        Inorder(root->right);
    }
}

void Preorder(struct Node* root)
{
    if(root!=NULL)
    {
        if(root->data==-1)
        {
            printf(" ");
        }
        else
        {
            printf("%d ",root->data);
        }
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct Node* root)
{
    if(root!=NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        if(root->data==-1)
        {
            printf(" ");
        }
        else
        {
            printf("%d ",root->data);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.INSERT NODES\n2.INORDER\n3.PREORDER\n4.POSTORDER\n5.DELETE A NODE\n6.EXIT\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            InsertNode();
        }
        else if(choice==2)
        {
            printf("Inorder Traversal:\n");
            Inorder(root);
        }        
        else if(choice==3)
        {
            printf("Preorder Traversal:\n");
            Preorder(root);
        }
        else if(choice==4)
        {
            printf("Postorder Traversal:\n");
            Postorder(root);
        }
        else if(choice==5)
        {
            int value;
            printf("Enter the value of node to be deleted: ");
            scanf("%d",&value);
            root=DeleteNode(root,value);
        }
        else if(choice==6)
        {
            printf("-----------------EXITING PROGRAM---------------\n");
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
    return 0;
}