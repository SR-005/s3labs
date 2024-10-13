#include <stdio.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head=NULL;

//INSERT AT FRONT
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
            printf("INSERT AT FRONT");
        }
        else if(op==2)
        {
            printf("INSERT AT REAR");
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