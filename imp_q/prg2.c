/*Create a menu-driven program to manage binary tree nodes in a stack with the
following functionalities:
Create a stack of nodes: Implement push, pop, and display functionality. 
The display should show the top of the stack after each operation
and the address of each node.
Create a binary tree: Convert a postfix expression into a binary expression tree
using the stack and display it in infix (inorder) notation.
Preorder Display: Display the binary tree in prefix (preorder) notation.
Exit: Option to exit the program.
Doubly Linked List Transformation and Operations*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* stack[MAX];
int top=-1;

void push(struct Node* node)
{
    if(top==MAX-1)
    return;

    stack[++top] = node;
}

struct Node* pop()
{
    if(top==-1)
    return NULL;
    struct Node* node = stack[top--];
    return node;
}

void display()
{
    printf("\ntop : %d",stack[top]->data);
    for(int i=top;i>=0;i--)
    printf("\n%d\t",&stack[i]->data);
    
}

struct Node* binary()
{
    int data;
    printf("Enter ele or -1");
    scanf("%d",&data);

    if(data==-1)
    return NULL;

    struct Node* root = createNode(data);
    printf("Enter left child of %d : ",data);
    root->left = binary();
    printf("Enter right child of %d : ",data);
    root->right = binary();

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    printf("Enter no of ele :" );
    int n,ele;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        printf("Enter ele : ");
        scanf("%d",&ele);
        struct Node* temp=createNode(ele);
        push(temp);
    }

    display();
    return 0;
}
