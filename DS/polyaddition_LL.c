#include <stdio.h>
#include <stdlib.h>
 struct Node
 {
    int coeff;
    int pow;
    struct Node* link;
 };

struct Node* polynomial()
{
    int i,terms,coefficient,power;
    printf("Enter the Number of Terms: ");
    scanf("%d",&terms);
    for(i=0;i<terms;i++)
    {
        printf("Enter the Coefficient: ");
        scanf("%d",&coefficient);
        printf("Enter it's Power: ");
        scanf("%d",&power);

        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->coeff=coefficient;
        newnode->pow=power;
        
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            prev->link=newnode;
        }
        prev=newnode;
    }
    return head;
}

 int main()
 {
    printf("ENTER THE FIRST POLYNOMIAL:\n");
 }
 