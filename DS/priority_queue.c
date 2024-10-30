#include<stdio.h>
struct priorityqueue
{
    int value;
    int priority;
};

int main()
{
    int max,op,i,j,count=0;
    printf("Enter Maximum Size of Queue: ");
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
            if(count==max)
            {
                printf("QUEUE IS FULL!!");
            }
            else
            {
                int va,pr;
                if(front==-1)
                {
                    front=0;
                }
                rear++;
                printf("Enter the Number: ");
                scanf("%d",&va);
                printf("Enter Priority: ");
                scanf("%d",&pr);

                for(i=front;i<rear;i++)
                {
                    if(queue[i].priority>pr)
                    {
                        break;    //value of i is the index of value we need to move, so we break
                    }
                }

                for(j=rear+1;j>i;j--)   //rear+1 cause be need extra struct to move the rest
                {
                        queue[j]=queue[j-1];
                }
                queue[i].value=va;
                queue[i].priority=pr;
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
                queue[front].value=0;
                queue[front].priority=0;
                front++;
                printf("Element Removed Successfully");
                count--;
            }
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
                    printf("%d ",queue[i].value);
                }
            }
        }
        else if(op==4)
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
