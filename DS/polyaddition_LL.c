#include <stdio.h>
#include <stdlib.h>
 struct Node                         //node creation
 {
    int coeff;                      //coefficient
    int pow;                        //power
    struct Node* link;
 };

struct Node* polynomial()               //function to create a polynomial
{
    int i,terms,coefficient,power;
    printf("Enter the Number of Terms: ");       //total number of terms in the polynomial
    scanf("%d",&terms);
    struct Node* head=NULL;                     //initialize a new pointer head that stores the  address of the first node
    struct Node* prev=NULL;                     //intialize a new pointer  prev that stores the address of the previous node


    for(i=0;i<terms;i++)
    {
        printf("Enter the Coefficient: ");      //input  coefficient and  power of each term
        scanf("%d",&coefficient);
        printf("Enter it's Power: ");
        scanf("%d",&power);

        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));     //allocate memory for the new node and store it's address in  newnode
        newnode->coeff=coefficient;         //set the coefficient of the term as given by user
        newnode->pow=power;              //set the power of the term as given by user
        newnode->link=NULL;             //set link section to NULL as there is no next node currently
        
        if(head==NULL)             //if it is the first term of the polynomial
        {
            head=newnode;               //give the address of  the new node to head i.e, head now points to the newnode as first node
        }
        else                            //else                            
        {   
            prev->link=newnode;        //keep the current node's address in previous node's link section so that it points to this node
        }
        prev=newnode;                  //update the  previous node to the new node so that it can point to the next node in the next iteration
    }
    return head;
}

void Display(struct Node* head)             //function to display polynomials
{
    struct Node* cursor=head;               //initialize a pointer 'cursor' with the address of the first node of that linked list i.e, head
    while(cursor!=NULL)                 //while  the cursor is not NULL i.e, it has not reached the end of the linked list
    {
        printf("%dx^%d ",cursor->coeff,cursor->pow);     //print the data
        cursor=cursor->link;                    //assign the current node's address to the  cursor so that it can point to the next node in the next iteration
    }
    printf("\n\n");
    return;
}

struct Node* Addpoly(struct Node* head1, struct Node* head2)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));    //allocate memory for a node
    temp->coeff=0;          //keep the coefficient part of the term as 0
    temp->pow=0;            //keep the power of the term also as 0
    temp->link=NULL;        

    struct Node* prev=temp;      //create a pointer 'prev' with the address of the currently created node 
    struct Node* cursor1=head1;     //initialize a pointer 'cursor1' pointing to the first Node of POLYNOMIAL1
    struct Node* cursor2=head2;     //initialize a pointer 'cursor2' pointing to the first Node of POLYNOMIAL2

    while(cursor1!=NULL&&cursor2!=NULL)         //while both the terms are not over i.e,  both the pointers have not reached the end of the linked list
    {
        if(cursor1->pow < cursor2->pow)        //if power of term in second polynomial is greater than that of in first polynomial
        {
            prev->link=cursor2;          //assign the  address of the current node of second polynomial to the link section of the previous node of the result
            prev=cursor2;               //give the address of current 
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