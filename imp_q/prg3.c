/*Create a doubly linked list (DLL) of n nodes with the following operations:
Delete the nth node from the end.
Create another DLL and append it to the updated first DLL.
Delete duplicate nodes.
Display the list.
Convert the DLL into a binary search tree (BST).
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct Node* dll(struct Node* head,int data)
{
    struct Node* newNode = createNode(data);
    if(head==NULL)
    return newNode;

    struct Node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void display(struct Node* head)
{
    struct Node* temp = head;
    while(temp)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* dll1 = NULL;
    printf("Enter no of ele : ");
    int n,ele;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        dll1 = dll(dll1,ele);
    }
    display(dll1);
    return 0;
}