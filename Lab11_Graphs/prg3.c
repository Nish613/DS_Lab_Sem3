/*Write a C program to implement Breadth First Search (BFS) */

#include<stdio.h>

#define MAX 10//no vertices
int adj[MAX][MAX],queue[MAX],visited[MAX];
int front=-1,rear=-1,n;
void enqueue(int vertex)
{
    if(front==-1)
    front=0;

    queue[++rear] = vertex;
}

int dequeue()
{
    if(front==-1)
    return -1;

    int ele = queue[front++];
    if(front>rear)
    front=rear=-1;
    return ele;

}

void bfs(int start)
{
    int vertex;
    enqueue(start);
    visited[start]=1;
    while(front!=-1)
    {
        vertex = dequeue();
        printf("%d ",vertex);

        for(int i=0;i<n;i++)
        {
            if(adj[vertex][i]==1&&visited[i]==0)
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

int main()
{
    printf("Enter no of vertices : ");
    int start;
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    }

    for(int i=0;i<n;i++)
    visited[i]=0;

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("BFS traversal starting from vertex %d: ", start);
    bfs(start);
    printf("\n");
    return 0;
}
