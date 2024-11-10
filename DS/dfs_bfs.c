#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Graph
{
    struct Node* alist[100];
    int tnodes;
};

struct Stack
{
    int items[100];
    int top;
};

struct Queue
{
    int items[100];
    int front,rear;
};

struct Graph* newgraph()
{
    int nodes,edges,source,destination;
    struct Graph* graph =  (struct Graph*)malloc(sizeof(struct Graph));


    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    graph->tnodes=nodes;
    for(int i=0;i<nodes;i++)
    {
        graph->alist[i]=NULL;
    }

    printf("Enter the Edges in 'SOURCE DESTINATION' format: \n");
    for(int i=0;i<edges;i++)
    {
        printf("=> ");
        scanf("%d %d",&source,&destination);
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=destination;
        newnode->link=graph->alist[source];
        graph->alist[source]=newnode;
    }
    return graph;
}

void dfs(struct Graph* graph, int start)
{
    int visited[100] = {0}; 
    struct Stack stack; 
    stack.top=-1;
    stack.top++;
    stack.items[stack.top]=start;

    while (stack.top!=-1)
    {
        int node=stack.items[stack.top];
        stack.top--;

        if (visited[node] == 0) 
        {
            visited[node] = 1; 
            printf("%d ", node); 

            struct Node* temp = graph->alist[node];
            while (temp!=NULL) 
            {
                if (visited[temp->data] == 0) 
                {
                    stack.top++;
                    stack.items[stack.top]=temp->data;
                }
                temp = temp->link; 
            }
        }
    }
    printf("\n");
}

void bfs(struct Graph* graph, int start)
{
    int visited[100] = {0}; 
    struct Queue queue; 
    queue.front = 0;
    queue.rear = -1;

    // Start BFS from the 'start' node
    queue.rear++;
    queue.items[queue.rear] = start;
    visited[start] = 1;

    while (queue.front <= queue.rear) 
    {
        int node = queue.items[queue.front];
        queue.front++;
        printf("%d ", node);
        
        struct Node* temp = graph->alist[node];
        while (temp != NULL) 
        {
            if (visited[temp->data] == 0) 
            {
                visited[temp->data] = 1; 
                queue.rear++;
                queue.items[queue.rear] = temp->data;
            }
            temp = temp->link; 
        }
    }
    printf("\n");
}

int main()
{
    int choice,start;
    struct Graph* graph;
    while(1)
    {
        printf("\n1.INSERT\n2.DFS\n3.BFS\n4.EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            graph=newgraph();
        }

        else if(choice==2)
        {
            printf("Enter the Starting Node for DFS: ");
            scanf("%d",&start);
            dfs(graph,start);
        }
        
        else if(choice==3)
        {
            printf("Enter the Starting Node for BFS: ");
            scanf("%d",&start);
            bfs(graph,start);
        }
        
        else if(choice==4)
        {
            printf("------------EXITING PROGRAM-----------");
            break;
        }

        else
        {
            printf("INVALID OPERATION!!");
        }
    }
}