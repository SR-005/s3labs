#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;

int queue[MAX];
int stack[MAX];
int top=-1,front=-1,rear=-1;

void push(int value)
{
    if(top<MAX-1)
    {
        stack[++top]=value;
    }
}

int pop()
{
    if(top>=0)
    {
        return stack[top--];
    }
    return -1;
}

void DFS(int start)
{
    for(int i=0;i<MAX;i++)
    {
        visited[i]=0;
    }

    push(start);

    while(top!=-1)
    {
        int node=pop();
        if(visited[node]==0)
        {
            printf("%d ",node);
            visited[node]=1;
            for(int i=n-1;i>=0;i--)
            {
                if(adj[node][i]==1&&visited[i]==0)
                {
                    push(i)
                }
            }
        }
    }
    printf("\n");
}