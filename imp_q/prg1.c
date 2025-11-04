/*Implement a doubly linked list (DLL) with the following functionalities:
Read and display the list. 
Create a second list, separate even and odd numbers, and sort them.
Read a third list and perform a union operation with the sorted list.
Delete alternate nodes in the list.
Stack and Binary Tree Manipulation*/ 

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
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort(struct Node* head)
{
    struct Node* temp = head;
    int n=0;
    while(temp)
    {
        n++;
        temp = temp->next;
    }
    for(int i=0;i<n-1;i++)
    {
        temp = head;
        for(int j=0;j<n-i-1;j++)
        {
            if(temp->data>temp->next->data)
            {
                int t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }

        }
    }
}

struct Node* evenodd(struct Node* head)
{
    struct Node* even = NULL;
    struct Node* odd = NULL;
    struct Node* temp = head;

    while(temp)
    {
        if(temp->data%2==0)
        even = dll(even,temp->data);
        else
        odd = dll(odd,temp->data);
        temp = temp->next;
    }
    sort(even);
    sort(odd);

    struct Node* e = even;
    while(e->next)
    e=e->next;
    e->next=odd;
    odd->prev=e;
    return even;

}

struct Node* unionlist(struct Node* l1,struct Node* l2)//no duplicates
{
    struct Node* result = NULL;
    struct Node* temp = l1;

    while(temp)
    {
        result = dll(result,temp->data);
        temp=temp->next;
    }

    temp = l2;
    while(temp)
    {
        struct Node* t = result;
        int found=0;
        while(t)
        {
            if(t->data==temp->data)
            {
                found=1;
                break;
            }
            t=t->next;
        }
        if(!found)
        {
            result = dll(result,temp->data);
        }
        temp=temp->next;
        
    }
    return result;
   
}
int main()
{
    struct Node* head=NULL;
    printf("Enter no of ele : ");
    int n,ele;
    scanf("%d",&n);
    printf("Enter ele : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        head = dll(head,ele);
    }
    display(head);
    head = evenodd(head);
    display(head);

    //l2
    struct Node* l2 = NULL;
    printf("Enter no of ele for l2: ");
    int n1,ele1;
    scanf("%d",&n1);
    printf("Enter ele : ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&ele1);
        l2 = dll(l2,ele1);
    }
    struct Node* unionL = unionlist(head,l2);
    display(unionL);
    return 0;
}