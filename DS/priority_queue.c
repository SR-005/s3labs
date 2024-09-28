#include<stdio.h>
struct priorityqueue
{
    int value;
    int priority;
};

int main()
{
    int i,j,max,op,tpr,tva,count;
    printf("Enter Maximum Capacity of the Queue: ");
    scanf("%d",&max);
    struct priorityqueue element[max];
    int front=-1,rear=-1;

    while(1)
    {
        printf("\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("CHOOSE AN OPERATION: ");
        scanf("%d",&op);

        if(count==0)  //RESTART
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
                if(front==-1)  //FIRST EXECUTION
                {
                    front=0;
                }
                //INPUT VALUE AND PRIORITY

                printf("Enter the Number: ");
                scanf("%d",&element[rear].value);
                printf("Enter the Priority: ");
                scanf("%d",&element[rear].priority);
                count++;

                //BUBBLE SORT

            }

            printf("\nREAR: %d\nFRONT: %d\n\n",rear,front);
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
                    printf("%d ",element[rear].value);
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
