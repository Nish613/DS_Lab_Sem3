/*Write a C program to implement Depth First Search (DFS) */

#include<stdio.h>
#define MAX 10

int adj[MAX][MAX];
int n;
int visited[MAX];

void dfs(int vertex)
{
    printf("%d ",vertex);
    visited[vertex]=1;

    for(int i=0;i<n;i++)
    {
        if(adj[vertex][i]==1&&visited[i]==0)
        dfs(i);
    }
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;  // Initialize visited array

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    dfs(start);
    printf("\n");

    return 0;
}
