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

struct Node* Addpoly(struct Node* head1, struct Node* head2)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->coeff=0;
    temp->pow=0;
    temp->link=NULL;

    struct Node* prev=temp;
    struct Node* cursor1=head1;
    struct Node* cursor2=head2;

    while(cursor1!=NULL&&cursor2!=NULL)
    {
        if(cursor1->pow < cursor2->pow)
        {
            prev->link=cursor2;
            prev=cursor2;
            cursor2=cursor2->link;
        }
        else if(cursor1->pow > cursor2->pow)
        {
            prev->link=cursor1;
            prev=cursor1;
            cursor1=cursor1->link;
        }
        else
        {
            cursor1->coeff=cursor1->coeff+cursor2->coeff;
            prev->link=cursor1;
            prev=cursor1;
            cursor1=cursor1->link;
            cursor2=cursor2->link;
        }
    }

    if(cursor1!=NULL)
    {
        prev->link=cursor1;
    }
    if(cursor2!=NULL)
    {
        prev->link=cursor2;
    }
    return temp->link;
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

    struct Node* mhead=Addpoly(head1,head2);
    printf("RESULTANT POLYNOMIAL:\n");
    Display(mhead);
}