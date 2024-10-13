#include <stdio.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head=NULL;

//INSERT AT FRONT
int InsertAtFront()
{
    int value;
    printf("Enter the Data: ");
    scanf("%d",&value);

    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->link=head;         //the link part of the currently added node will direct to previous first node whose address was stored in head
    head=newnode;               //currently added node's address will be stored to head as it becomes the first node
}


//INSERT AT REAR
int InsertAtRear()
{
    int value;
    printf("Enter the Data: ");
    scanf("%d",&value);

    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->link=NULL;

    if(head==NULL)                   //if we are calling this function first i.e it is the first entry
    {
        head=newnode;               //set head value to currently added node's address
    }
    else                            
    {
        struct Node *temp=head;        //created a temporarity variable containing the address of first variable in the linked list (value in the head)
        while (temp->link!=NULL)       //do this until the last of the list reaches i.e, the address of last node is in temp
        {
            temp=temp->link;            //access the node and assign it's link part to temp i.e, assign next node's address to temp each time the loop runs
        }
        temp->link=newnode;             //now change the last node's link part from NULL to newly created node as we are entering node at the end
    }
}


int InsertAtPosition()
{
    int position,value;
    printf("Enter the Position to Insert the Data: ");  //enter position to be inserted at
    scanf("%d",&position);
    printf("Enter the Data: ");
    scanf("%d",&value);

    if(position==1)                                     //if user is aking to enter value at position 1 i.e, at starting of the list, then call the Insert At Front function
    {
        InsertAtFront();
        return;
    }

    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));     //Allocate Memory
    newnode->data=value;                        //feed data to Node
    struct Node *temp=head;                     //created a temporarity variable containing the address of first variable in the linked list (value in the head) 
    for(int i=0;temp!=NULL&&i<position;i++)     //do this until either temp becomes NULL(end of list reaches)-OR-run this loop i[position] times so that temp has the address of the node that is the specified position 
    {
        temp=temp->link;                        //access the node and assign it's link part to temp i.e, assign next node's address to temp each time the loop runs
    }

    if(temp==NULL)                                  //after the for loop end, if the temp contains the value NULL, that means it reached End of the List
    {
        printf("Position Out of Range!!");
        free(newnode);                              //free the previously allocated memory
        return;
    }

    //since temp points to node in the specifies position
    newnode->link=temp->link;          //link part of newnode should carry the link part of current node there so that it points to the next node withput interuption          
    temp->link=newnode;             //now assign link part of the current node in the position with address of newnode so that it points towards this node
} 


int main()
{
    int op;
    while (1)
    {
        printf("\n1. INSERT AT FRONT\n2. INSERT A REAR\n3. INSERT AT SPECIFIED POSITION\n4. DELETE FROM FRONT\n5. DELETE FROM REAR\n6. DELETE FROM SPECIFIED POSITION\n7. DISPLAY\n8. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d",&op);

        if(op==1)
        {
            InsertAtFront();
        }
        else if(op==2)
        {
            InsertAtRear();
        }
        else if(op==3)
        {
            printf("INSERT AT SPECIFIED POSTION");
        }
        else if(op==4)
        {
            printf("DELETE FROM FRONT");
        }
        else if(op==5)
        {
            printf("DELETE FROM REAR");
        }
        else if(op==6)
        {
            printf("DELETE FROM SPECIFIED POSITION");
        }
        else if(op==7)
        {
            printf("DISPLAY ");
        }
        else if(op==8)
        {
            printf("------EXITING PROGRAM------");
            break;
        }
        else
        {
            printf("INVALID OPERATION - PLEASE TRY AGAIN!!");
        }
    }
    
}