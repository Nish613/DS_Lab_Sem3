/*Write a program to create a BST and perform inorder, preorder, and postorder 
traversals.*/

#include<stdio.h>
#include<stdlib.h>

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
struct Node* createBST(struct Node* root,int data)
{
    if(root==NULL)
    return createNode(data);

    if(data<root->data)
    root->left = createBST(root->left,data);
    else if(data>root->data)
    root->right = createBST(root->right,data);

    return root;

}

void inorder(struct Node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node* root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct Node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    inorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    struct Node* root = NULL;
    printf("Enter no of nodes : ");
    int n;
    scanf("%d",&n);

    printf("Enter ele : ");
    int ele;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        root = createBST(root,ele);
    }
    printf("Inorder : ");
    inorder(root);

    printf("Preorder : ");
    preorder(root);

    printf("Postorder : ");
    postorder(root);

    return 0;
}