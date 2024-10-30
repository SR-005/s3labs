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
    struct Node* head=NULL;
    struct Node* prev=NULL;

    for(i=0;i<terms;i++)
    {
        printf("Enter the Coefficient: ");
        scanf("%d",&coefficient);
        printf("Enter it's Power: ");
        scanf("%d",&power);

        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->coeff=coefficient;
        newnode->pow=power;
        newnode->link=NULL;
        
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

void Display(struct Node* head)
{
    struct Node* cursor=head;
    while(cursor!=NULL)
    {
        printf("%dx^%d ",cursor->coeff,cursor->pow);
        cursor=cursor->link;
    }
    printf("\n\n");
    return;
}

struct Node* Multipoly(struct Node* head1, struct Node* head2)
{
    int coefficient=0, power=0;
    struct Node* result=NULL;
    struct Node* prev=NULL;
    struct Node* cursor1=head1;
    struct Node* cursor2=head2;

    while(cursor1!=NULL)
    {
        while(cursor2!=NULL)
        {
            coefficient=cursor1->coeff * cursor2->coeff;
            power=cursor1->pow + cursor2->pow;
            struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
            newnode->coeff=coefficient;
            newnode->pow=power;
            newnode->link=NULL;

            if(result==NULL)
            {
                result=newnode;
                prev=newnode;
            }
            else
            {
                prev->link=newnode;
                prev=newnode;
            }
            cursor2=cursor2->link;
        }
        cursor1=cursor1->link;
    }

    struct Node* temp=result;
    while(temp!=NULL)
    {
        struct Node* tlink=temp->link;
        while(tlink!=NULL)
        {
            if(temp->pow==tlink->pow)
            {
                temp->coeff = temp->coeff + tlink->coeff;
                struct Node* toFree=tlink;
                tlink=tlink->link;
                temp->link=tlink;
                free(toFree);
            }
            else
            {
                tlink=tlink->link;
            }
        }
        temp=temp->link;
    }
    return result;
}

int main()
{
    printf("ENTER THE FIRST POLYNOMIAL:\n");
    struct Node* head1=polynomial();
    printf("FIRST POLYNOMIAL:\n");
    Display(head1);
    printf("ENTER THE SECOND POLYNOMIAL:\n");
    struct Node* head2=polynomial();
    printf("SECOND POLYNOMIAL:\n");
    Display(head2);

    struct Node* mhead=Multipoly(head1,head2);
    printf("RESULTANT POLYNOMIAL:\n");
    Display(mhead);
}