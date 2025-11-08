/*Details are - Id and name 
BST(by id) insert node recursively , delete root node , 
post order traversal iteratively and find minimum and maximum id element */

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int id;
    char name[50];
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int id,char name[])
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->name,name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* bst(struct Node* root,int id,char name[])
{
    if(root==NULL)
    root = createNode(id,name);

    if(id<root->id)
}
int main()
{

    return 0;
}