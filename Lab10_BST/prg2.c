/*Write a function to search an element in a BST.*/

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

struct Node* search(struct Node* root,int key)
{
    if(root->data==key||root==NULL)
    return root;
    if(key<root->data)
    return search(root->left,key);
    else if(key>root->data)
    return search(root->right,key);
}

void inorder(struct Node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    struct Node* root=NULL;
    printf("Enter no of ele : ");
    int n,ele;
    scanf("%d",&n);

    printf("Enter ele : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        root = createBST(root,ele);
    }

    printf("\nInorder : ");
    inorder(root);

    printf("\nEnter ele to search : ");
    int key;
    scanf("%d",&key);

    struct Node* result = search(root,key);
    if (result != NULL)
        printf("\nElement %d found in BST.\n", key);
    else
        printf("\nElement %d not found in BST.\n", key);
    return 0;
}