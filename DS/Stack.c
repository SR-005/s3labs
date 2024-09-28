#include<stdio.h>
int main()
{
    int operation=0,top=-1,max,i,popnum,popindex,temp,count=0;
    printf("Enter the Maximum Capacity of the Stack: ");
    scanf("%d",&max);
    int stack[max];

    while(1)
    {
        printf("\n1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Choose an Operation: ");
        scanf("%d",&operation);

        if(operation==1)
        {
            if(top==max-1)
            {
                printf("STACK OVERFLOW!!\n");
            }
            else
            {
                printf("Enter the Number: ");
                scanf("%d",&stack[top]);
                top++;
            }
        }

        else if(operation==2)
        {
            if(top==-1)
            {
                printf("CANNOT POP ELEMENT - STACK UNDERFLOW!!");
            }
            else
            {
                printf("Enter Number you want to delete: ");
                scanf("%d",&popnum);

                for(i=0;i<top;i++)
                {
                    if(stack[i]==popnum)
                    {
                        popindex=i;
                        count=1;
                    }
                }

                if(count==1)
                {
                    for(i=popindex+1;i<=top;i++)
                    {
                        temp=stack[i];
                        stack[i]=stack[i+1];
                        stack[i+1]=temp;
                    }
                    top--;
                }
            }
        }

        else if(operation==3)
        {
            printf("STACK CONTENT: \n");
            for(i=0;i<top;i++)
            {
                printf("%d\n",stack[i]);
            }
        }

        else if(operation==4)
        {
            break;
        }

        else
        {
            printf("INVALID OPERATOR!!\n");
            printf("TRY AGAIN!!\n");
        }
    }
}
