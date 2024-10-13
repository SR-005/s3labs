#include<stdio.h>
struct priorityqueue
{
    int value;
    int priority;
};

int main()
{
    int i,j,max,op,pr,va,count;
    printf("Enter Maximum Capacity of the Queue: ");
    scanf("%d",&max);
    struct priorityqueue queue[max];
    int front=-1,rear=-1;

    while(1)
    {
        printf("\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("CHOOSE AN OPERATION: ");
        scanf("%d",&op);

        if(count==0)
        {
            front=-1;
            rear=-1;
        }

        if(op==1)
        {
            if(count==max)  //QUEUE IS FULL
            {
                printf("QUEUE IS FULL!!");
            }
            else
            {
                rear++;
                if(front==-1)
                {
                    front=0;
                }

                printf("Enter the Number: ");
                scanf("%d",&va);
                printf("Enter the Priority: ");
                scanf("%d",&pr);
                printf("\nvalue: %d      priority: %d",va,pr);
                for(i=front;i<rear;i++)
                {
                    if(queue[i].priority>pr)
                    {
                        break;    //value of i is the index of value we need to move
                    }
                }

                for(j=rear+1;j>i;j--)   //rear+1 cause be need extra struct to move the rest
                {
                        queue[j]=queue[j+1];
                }
                printf("\ni=%d\n",i);
                queue[i].value=va;
                queue[i].priority=pr;
                count++;
            }
            printf("\nREAR: %d\nFRONT: %d\nCOUNT: %d\n\n",rear,front,count);
        }
        else if(op==2)
        {
            printf("DEQUEUE");
        }
        else if(op==3)
        {
            if(count==0)
            {
                printf(" ");
            }
            else
            {
                for(i=front;i<=rear;i++)
                {
                    printf("%d ",queue[rear].value);
                }
            }
        }
        else if(op==4)
        {
            printf("-----------------EXITING PROGRAM------------------");
            break;
        }
        else
        {
            printf("INVALID OPERATION!!\n");
        }

    }
}
