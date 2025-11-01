/*Write a C program to represent directed and undirected graphs using adjacency 
matrix. */

#include<stdio.h>
#define MAX 10 //max vertices

void createDirected(int adj[MAX][MAX],int n)
{
    printf("Enter no of edges : ");
    int edge,origin,dest;
    scanf("%d",&edge);

    for(int i=0;i<edge;i++)
    {
        printf("Enter origin,destination for edge %d : ",i+1);
        scanf("%d %d",&origin,&dest);

        if(origin>=n||origin<0||dest>=n||dest<0)
        {
            printf("Invalid\n");
            i--;
        }
        else
        adj[origin][dest] = 1;
    }
}

void createUndirected(int adj[MAX][MAX],int n)
{
    printf("Enter no of edges : ");
    int edge,origin,dest;
    scanf("%d",&edge);

    for(int i=0;i<edge;i++)
    {
        printf("Enter origin,destination for edge %d : ",i+1);
        scanf("%d %d",&origin,&dest);

        if(origin>=n||origin<0||dest>=n||dest<0)
        {
            printf("Invalid\n");
            i--;
        }
        else
        {
            adj[origin][dest] = 1;
            adj[dest][origin] = 1;
        }
        
    }
}

void display(int adj[MAX][MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adj[MAX][MAX];

    printf("Enter no of vertices : ");
    int n;
    scanf("%d",&n);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;


    printf("Directed matrix : \n");
    createDirected(adj,n);
    display(adj,n);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Undirected matrix : \n");
    createUndirected(adj,n);
    display(adj,n);

    return 0;
}