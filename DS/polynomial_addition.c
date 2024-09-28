#include<stdio.h>

struct Polynomial1
{
    int coefficient;
    int exponent;
};
struct Polynomial2
{
    int coefficient;
    int exponent;
};
struct Polynomial3
{
    int coefficient;
    int exponent;
};

int main()
{
    int degree1,degree2,coefficient,exponent,i=0;
    //largest degree of POLYNOMIAL 1
    printf("Enter the Largest Degree of First Polynomial: ");
    scanf("%d",&degree1);
    degree1=degree1+1;
    struct Polynomial1 p1[degree1];

    //asking POLYNOMIAL 1
    for(i=degree1-1;i>=0;i--)
    {
        printf("Enter Coefficient of x^%d: ",i);
        scanf("%d",&p1[i].coefficient);
        p1[i].exponent=i;
    }

    //largest degree of POLYNOMIAL 2
    printf("\nEnter the Largest Degree of Second Polynomial: ");
    scanf("%d",&degree2);
    degree2=degree2+1;
    struct Polynomial2 p2[degree2];

    //asking POLYNOMIAL 2
    for(i=degree2-1;i>=0;i--)
    {
        printf("Enter Coefficient of x^%d: ",i);
        scanf("%d",&p2[i].coefficient);
        p2[i].exponent=i;
    }

    //displaying POLYNOMIAL 1
    printf("FIRST POLYNOMIAL: ");
    for(i=degree1-1;i>=0;i--)
    {
        printf("%dx^",p1[i].coefficient);
        printf("%d ",p1[i].exponent);
    }

    //displaying POLYNOMIAL 2
    printf("\nSECOND POLYNOMIAL: ");
    for(i=degree2-1;i>=0;i--)
    {
        printf("%dx^",p2[i].coefficient);
        printf("%d ",p2[i].exponent);
    }

    printf("\nelement 1: %dx^%d\n",p1[0].coefficient,p1[0].exponent);
    printf("element 2: %dx^%d\n",p1[1].coefficient,p1[1].exponent);
    printf("element 3: %dx^%d\n",p1[2].coefficient,p1[2].exponent);

    int maxdegree,p1count=0,p2count=0;
    p1count=degree1-1;
    p2count=degree2-1;
    printf("\np1count: %d\n",p1count);
    printf("p2count: %d",p2count);
    //maxdegree=degree1+degree2;
    //if(degree1>degree2)
    //{
    //    maxdegree=degree1;
    //}
    //else
    //{
    //    maxdegree=degree2;
    //}
    maxdegree=4;
    struct Polynomial3 p3[maxdegree];

    //adding POLYNOMIAL 1 and POLYNOMIAL 2
    for(i=0;i<maxdegree;i++)
    {
        printf("\np1: %d, p2: %d\n",p1count,p2count);
        if(p1count>=0&&p2count>=0)
        {
            if(p1[p1count].exponent>p2[p2count].exponent)
            {
                p3[i].coefficient=p1[p1count].coefficient;
                p3[i].exponent=p1[p1count].exponent;
                p1count--;
            }
            else if(p1[p1count].exponent<p2[p2count].exponent)
            {
                p3[i].coefficient=p2[p2count].coefficient;
                p3[i].exponent=p2[p2count].exponent;
                p2count--;
            }
            else
            {
                p3[i].coefficient=p1[p1count].coefficient+p2[p2count].coefficient;
                p3[i].exponent=p1[p1count].exponent;
                p1count--;
                p2count--;
            }
        }
        else
        {
            if(p1count<0)
            {
                p3[i].coefficient=p2[p2count].coefficient;
                p3[i].exponent=p2[p2count].exponent;
                p2count--;
            }
            else if(p2count<0)
            {
                p3[i].coefficient=p1[p1count].coefficient;
                p3[i].exponent=p1[p1count].exponent;
                p1count--;
            }
            else
            {
                break;
            }
        }

    }

    //displaying POLYNOMIAL 3
    printf("\nRESULTANT POLYNOMIAL: ");
    for(i=0;i<=maxdegree;i++)
    {
        printf("%dx^",p3[i].coefficient);
        printf("%d ",p3[i].exponent);
    }
}
