#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
int adj[MAX][MAX];
int visited[MAX];
int n;
}Graph;
typedef struct {
int items[MAX];
int top;
}Stack;
typedef struct {
int items[MAX];
int front, rear;
}Queue;
void initGraph(Graph* g, int n);
void addEdge(Graph* g, int u, int v);
void bfs(Graph* g, int start);
void dfs(Graph* g, int start);
void push(Stack* s, int value);
int pop(Stack* s);
int isEmptyStack(Stack* s);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmptyQueue(Queue* q);
void initGraph(Graph* g, int n) {
g->n = n;
for (int i =0; i < n; i++)
{
g->visited[i] =0;
for (int j =0; j < n; j++)
{
g->adj[i][j] =0;
}}}
void addEdge(Graph* g, int u, int v) {
g->adj[u][v] =1;
g->adj[v][u] =1;
}
void bfs(Graph* g, int start) {
Queue q;
q.front = -1;
q.rear = -1;
enqueue(&q, start);
g->visited[start] =1;
while (!isEmptyQueue(&q)) {
int current = dequeue(&q);
printf("%d ", current);
for (int i =0; i < g->n; i++)
{
if (g->adj[current][i] ==1 && !g->visited[i])
{
enqueue(&q, i);
g->visited[i] =1;
}}}}
void dfs(Graph* g, int start) {
Stack s;
s.top = -1;
push(&s, start);
g->visited[start] =1;
while(!isEmptyStack(&s)) {
int current = pop(&s);
printf("%d ", current);
for (int i =0; i < g->n; i++)
{
if (g->adj[current][i] ==1 && !g->visited[i])
{
push(&s, i);
g->visited[i] =1;
}}}}
void push(Stack* s, int value) {
s->items[++s->top] = value; }
int pop(Stack* s) {
return s->items[s->top--]; }
int isEmptyStack(Stack* s) {
return s->top == -1;
}
void enqueue(Queue* q, int value) {
if (q->rear == MAX -1)
{
return;
}
if (q->front ==-1)
{
q->front =0;
}
q->items[++q->rear] = value; }
int dequeue(Queue* q) {
int item = q->items[q->front++];
if (q->front > q->rear) {
q->front = q->rear =-1;
}
return item; 
}
int isEmptyQueue(Queue* q) {
return q->front ==-1;
}
int main() {
Graph g;
int v, r, val;
printf("Enter the no. of vertices :");
scanf("%d", &v);
initGraph(&g, v);
for(int i=1; i<v; i++)
{
printf("Enter the edge(source) :");
scanf("%d", &r);
printf("Enter the destination:");
scanf("%d", &val);
addEdge(&g, r, val);
}
printf("BFS starting from vertex 0:\n");
bfs(&g,0);
for (int i =0;i< g.n; i++)
{
g.visited[i]=
0;
}
printf("\nDFS starting from vertex 0:\n");
dfs(&g,0);
}