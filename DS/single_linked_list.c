#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head=NULL;

//INSERT AT FRONT
void InsertAtFront()
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
void InsertAtRear()
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


void InsertAtPosition()
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
    for(int i=0;temp!=NULL&&i<position-2;i++)     //do this until either temp becomes NULL(end of list reaches)-OR-run this loop less that i[position] times so that temp has the address of the node before the specified position
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

void DeleteFromFront()
{
    if(head==NULL)                         //if head is NULL, then there is no node in the Linked List
    {
        printf("List is Empty\n"); 
        return;
    }
    struct Node* temp=head;             //created a temporarity variable containing the address of first variable in the linked list (value in the head)
    head=head->link;                    //re-assign head to the next node 
    free(temp);                         //delete the first node(temp)
}

void DeleteFromRear()
{
    if(head==NULL)                         //if head is NULL, then there is no node in the Linked List
    {
        printf("List is Empty");
        return;
    }

    if(head->link==NULL)                   //if the link section if the first node is null i.e, there is only one node present in the list
    {
        free(head);                         //delete the first node(head)
        head=NULL;                          //make the value of head pointer NULL as there is no more node left in the list
        return;                         
    }

    struct Node* temp=head;                //created a temporarity variable containing the address of first variable in the linked list (value in the head)
    while(temp->link->link!=NULL)           //loop until the pointer reaches the second last node in the list
    {
        temp=temp->link;                //access the node and assign it's link part to temp i.e, assign next node's address to temp each time the loop runs
    }
    free(temp->link);                   //delete the last node -we use temp->link aas we now sit on second last node
    temp->link=NULL;                    //make the second last node's link section NULL as the last node is now gone and the previously second last node is now the last node
}

void DeleteFromPosition()        
{
    int position;
    if(head==NULL)                        //if head is NULL, then there is no node in the Linked List
    {
        printf("List is Empty");
        return;
    }

    printf("Enter the Position to Insert the Data: ");
    scanf("%d",&position);
    if(position==1)                         //if the user enter position is 1 i.e, user wants to delete the first Node, then call the delete from front function
    {
        DeleteFromFront();
        return;
    }

    struct Node* temp=head;                      //created a temporarity variable containing the address of first variable in the linked list (value in the head)
    for(int i=0;temp!=NULL&&i<position-2;i++)    //do this until either temp becomes NULL(end of list reaches)-OR-run this loop less that i[position] times so that temp has the address of the node before the specified position
    {
        temp=temp->link;                   //access the node and assign it's link part to temp i.e, assign next node's address to temp each time the loop runs
    }

    if(temp==NULL||temp->link==NULL)        //when the loop stops, if the temp==NULL i.e, loop terminated to due reaching the end OR it reached second last Node then
    {
        printf("POSITION OUT OF RANGE");
        return;
    }

    struct Node* tlink=temp->link->link;   //create a temporary tlink variable to store the address the node after the node after current node
    free(temp->link);                       //free the node in specified position - temp->link as we stand in the node before the desired node
    temp->link=tlink;                       //join the gap
}

void Display()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
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
            InsertAtPosition();
        }
        else if(op==4)
        {
            DeleteFromFront();
        }
        else if(op==5)
        {
            DeleteFromRear();
        }
        else if(op==6)
        {
            DeleteFromPosition();
        }
        else if(op==7)
        {
            Display();
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