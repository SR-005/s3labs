#include<stdio.h>
int main()
{
    int front=-1,rear=-1,op=0,max,i,count;
    printf("Enter Maximum Capacity of queue: ");
    scanf("%d",&max);
    int queue[max];
    while(1)
    {
        printf("\n\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("CHOOSE AN OPERATION: ");
        scanf("%d",&op);

        if(count==0)
        {
            front=-1;
            rear=-1;
        }

        if(op==1)
        {
            if(count==max)
            {
                printf("QUEUE OVERFLOW!!!");
            }
            else
            {
                rear=(rear+1)%max;
                if(front<0)
                {
                    front++;
                }
                printf("Enter Number: ");
                scanf("%d",&queue[rear]);
                printf("Element Entered Successfully!!");
                count++;
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
                front=(front+1)%max;
                printf("Element Removed Successfully");
                count--;
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
                for(i=0;i<=max-1;i++)
                {
                    if(queue[i]!=0)
                    {
                        printf("%d ",queue[i]);
                    }

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
