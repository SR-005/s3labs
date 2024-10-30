#include<stdio.h>
int main()
{
    int max,op,i;
    printf("Enter the Maximum Size of Queue: ");
    scanf("%d",&max);
    int queue[max];
    for(i=0;i<max;i++)
    {
        queue[i]=0;
    }
    int front=-1,rear=-1,count=0;

    while(1)
    {
        printf("\n\n1.INSERT AT FRONT\n2.INSERT AT BACK\n3.DELETE FROM FRONT\n4.DELETE FROM BACK\n5.DISPLAY\n6.EXIT\n");
        printf("CHOOSE AN OPERATION: ");
        scanf("%d",&op);
        printf("COUNT: %d\nFRONT: %d\nREAR: %d\n",count,front,rear);
        if(count==0)
        {
            front=-1;
            rear=-1;
        }

        if(op==1)           //insert at front
        {
            if(count==max)
            {
                printf("QUEUE FULL!!!");
            }
            else
            {
                if(front==-1)        //first execution
                {
                    front=0;
                    rear=0;
                }
                else if(front==0)
                {
                    front=max-1;
                }
                else
                {
                    front--;
                }
                printf("Enter the Number: ");
                scanf("%d",&queue[front]);
                count++;
            }
        }
        else if(op==2)
        {
            if(count==max)
            {
                printf("QUEUE IS FULL!!!");
            }
            else
            {
                if(front==-1)        //first execution
                {
                    front=0;
                    rear=0;
                }
                else if(rear==max-1)
                {
                    rear=0;
                }
                else
                {
                    rear++;
                }
                printf("Enter the Number: ");
                scanf("%d",&queue[rear]);
                count++;
            }
        }
        else if(op==3)
        {
            if(front&&rear==-1)
            {
                printf("QUEUE IS EMPTY!!");
            }
            else
            {
                queue[front=0];
                if(front==max-1)
                {
                    front=0;
                }
                else
                {
                    front++;
                }
                printf("Element Removed Successfully");
                count--;
            }
        }
        else if(op==4)
        {
            if(front&&rear==-1)
            {
                printf("QUEUE IS EMPTY!!");
            }
            else
            {
                queue[front=0];
                if(rear==0)
                {
                    rear=max-1;
                }
                else
                {
                    rear--;
                }
                printf("Element Removed Successfully");
                count--;
            }
        }
        else if(op==5)
        {
            if(count==0)
            {
                printf(" ");
            }
            else
            {
                i=front;
                while(1)
                {
                    printf("%d",queue[i]);
                    if(i==rear)
                    {
                        break;
                    }
                    i=(i+1)%max;
                }
            }
        }
        else if(op==6)
        {
            printf("-----EXITING PROGRAM-----");
            break;
        }
        else
        {
            printf("INVALID OPERATION!!");
        }

    }
}
