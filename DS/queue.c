#include<stdio.h>
int main()
{
    int front=-1,rear=-1,op=0,max,i;
    printf("Enter Maximum Capacity of queue: ");
    scanf("%d",&max);
    int queue[max];
    while(1)
    {
        printf("\n\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("CHOOSE AN OPERATION: ");
        scanf("%d",&op);

        if(front>rear)
        {
            front=-1;
            rear=-1;
        }

        if(op==1)
        {
            if(rear==max-1)
            {
                printf("QUEUE OVERFLOW!!!");
            }
            else
            {
                rear++;
                if(front<0)
                {
                    front++;
                }
                printf("Enter Number: ");
                scanf("%d",&queue[rear]);
                printf("Element Entered Successfully!!");
            }
        }

        else if(op==2)
        {
            if(front&&rear==-1)
            {
                printf("QUEUE UNDERFLOW!!");
            }
            else
            {
                queue[front]=0;
                front++;
                printf("Element Removed Successfully");
            }
        }

        else if(op==3)
        {
            if(front&&rear==-1)
            {
                printf(" ");
            }
            else
            {
                for(i=front;i<=rear;i++)
                {
                    printf("%d ",queue[i]);
                }
            }
        }

        else if(op==4)
        {
            printf("--------EXITING----------");
            break;
        }

        else
        {
            printf("INVALID OPERATION!!");
            printf("TRY AGAIN");
        }
    }
}
