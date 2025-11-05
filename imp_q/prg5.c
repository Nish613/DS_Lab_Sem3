/*Queue of structures 
structure has name, event_name and reg_id
Write functions to enqueue, dequeue and display the queue*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char name[50];
    char event[50];
    int id;
    struct Node* next;
};

struct Node* front=NULL;
struct Node* rear = NULL;

void enqueue(char name[],char event[],int id)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->name,name);
    strcpy(newNode->event,event);
    newNode->next = NULL;

    if(front==NULL)
    front=rear=newNode;
    else{ 
    rear->next = newNode;
    rear = newNode;}
}

void dequeue()
{
    if(front==NULL)
    return;

    struct Node* temp = front;
    front=front->next;
    printf("%d",temp->id);
    free(temp);
}

void display()
{
    struct Node* temp = front;
    while(temp)
    {
        printf("\nname : %s",temp->name);
        printf("\nevent : %s",temp->event);
        printf("\nreg : %d",temp->id);

        temp=temp->next;
    }
}

int main()
{
    while(1)
    {
        printf("Enter choice 1.enqueue2.dequeue3.display : ");
        int n,id;
        char name[50],event[50];
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            {
                printf("Enter name : ");
                scanf(" %[^\n]",name);
                printf("Enter event : ");
                scanf(" %[^\n]",event);
                printf("Enter id : ");
                scanf("%d",&id);

                enqueue(name,event,id);
            }
            break;
            case 2:
            {
                dequeue();

            }
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
        }
    }
    
    return 0;

}

