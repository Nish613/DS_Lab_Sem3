/*Write a C program to represent directed and undirected graphs using adjacency list.*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 10 // max vertices

struct Node
{
    int vertex;
    struct Node* next;
};

void addEdge(struct Node* adj[],int origin,int dest)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adj[origin];
    adj[origin] = newNode;
}

void createDirected(struct Node* adj[], int n)
{
    printf("Enter no of edges : ");
    int edges,origin,dest;
    scanf("%d",&edges);

    for(int i=0;i<edges;i++)
    {
        printf("Enter origin and destination for %d edge : ",i+1);
        scanf("%d %d",&origin,&dest);

        if(origin>=n||origin<0||dest>=n||dest<0)
        {
            printf("Invalid\n");
            i--;
        }

        else
        addEdge(adj,origin,dest);
    }
}

void createUndirected(struct Node* adj[], int n)
{
    printf("Enter no of edges : ");
    int edges,origin,dest;
    scanf("%d",&edges);

    for(int i=0;i<edges;i++)
    {
        printf("Enter origin and destination for %d edge : ",i+1);
        scanf("%d %d",&origin,&dest);

        if(origin>=n||origin<0||dest>=n||dest<0)
        {
            printf("Invalid\n");
            i--;
        }

        else{ 
        addEdge(adj,origin,dest);
        addEdge(adj,dest,origin);
        }
    }
}

void display(struct Node* adj[],int n)
{
    for(int i=0;i<n;i++)
    {
        struct Node* temp = adj[i];
        printf("Vertex %d : ",i);
        while(temp!=NULL)
        {
            printf("%d\t",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Node* adj[MAX];
    int n;

    printf("Enter no of vertices : ");
    scanf("%d",&n);
    //initilise LL to null
    for(int i=0;i<MAX;i++)
    adj[i] = NULL;

    printf("Directed list : \n");
    createDirected(adj,n);
    display(adj,n);

    for(int i=0;i<MAX;i++)
    adj[i] = NULL;

    printf("Undirected list : \n");
    createUndirected(adj,n);
    display(adj,n);
    return 0;
}