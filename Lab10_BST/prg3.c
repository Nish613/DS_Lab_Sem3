/*Write a function to delete a node from a BST. */

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

struct Node* min(struct Node* root)
{
    struct Node* temp = root;
    while(temp!=NULL && temp->left !=NULL)
    temp = temp->left;
    return temp;
}
struct Node* delete(struct Node* root,int key)
{
    if(root==NULL)
    return root;

    //traverse to node to be deleted
    if(key<root->data)
    root->left = delete(root->left,key);
    else if(key>root->data)
    root->right = delete(root->right,key);

    else
    {
        //Node to be deleted is found

        //case1: no child
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        
        //case2: 1 child
        else if(root->left==NULL)
        {
            struct Node* temp = root->right;//we are deleting parent node so storing right child in temp
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        //case3: 2 children
        struct Node* temp = min(root->right);//a root's successor is its right child ka left child
        root->data = temp->data;//copy right child ka left to root
        root->right = delete(root->right,temp->data);//remove the duplicate ie right child ka left
    }
    return root;
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
    struct Node* root = NULL;
    printf("Enter no of ele : ");
    int n,ele;
    scanf("%d",&n);

    printf("Enter ele : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        root = createBST(root,ele);
    }

    inorder(root);
    root = delete(root,3);
    printf("\n");
    inorder(root);
}