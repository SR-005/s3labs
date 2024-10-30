#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coeff;
    int pow;
    struct Node* link;
};
struct Node* create(int c,int p)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->coeff=c;
    newnode->pow=p;
    newnode->link=NULL;
    return newnode;
}
struct Node* getpoly()
{
    int n,coeff=0,pow=0;
    printf("Enter the Number of Terms in the Polynomial: ");
    scanf("%d",&n);
    struct Node* head=NULL;
    struct Node* prev=NULL;
    for(int i=0;i<n;i++)
    {
        printf("Enter the Coefficient: ");
        scanf("%d",&coeff);
        printf("Enter it's Power: ");
        scanf("%d",&pow);
        struct Node* newnode=create(coeff,pow);
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

struct Node* addpoly(struct Node* head1,struct Node* head2)
{
    struct Node* temp=create(0,0);
    struct Node* prev=temp;
    struct Node* cur1=head1;
    struct Node* cur2=head2;
    while(cur1!=NULL&&cur2!=NULL)
    {
        if(cur1->pow < cur2->pow)
        {
            prev->link=cur2;
            prev=cur2;
            cur2=cur2->link;
        }
        else if(cur1->pow > cur2->pow)
        {
            prev->link=cur1;
            prev=cur1;
            cur1=cur1->link;
        }
        else
        {
            cur1->coeff=cur1->coeff+cur2->coeff;
            prev->link=cur1;
            prev=cur1;
            cur1=cur1->link;
            cur2=cur2->link;
        }
    }
    if(cur1!=NULL)
    {
        prev->link=cur1;
    }
    if(cur2!=NULL)
    {
        prev->link=cur2;
    }
    return temp->link;
}
void display(struct Node* head)
{
    struct Node* cur=head;
    while(cur!=NULL)
    {
        printf("%dx%d ",cur->coeff,cur->pow);
        cur=cur->link;
        if(cur!=NULL)
        {
            printf("+ ");
        }
    }
    printf("\n");
}
int main()
{
    printf("FIRST POLYNOMIAL:\n ");
    struct Node* head1=getpoly();
    display(head1);
    printf("SECOND POLYNOMIAL:\n ");
    struct Node* head2=getpoly();
    display(head2);
    struct Node* head=addpoly(head1,head2);
    printf("Resultant Polynomial: ");
    display(head);
}