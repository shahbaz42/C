#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int);   // function for adding new nodes
void inorder(struct node *); // function for for preorder traversal
int isBST(struct node *);    // function for checking if the tree is BST

int main()
{
    // creating and initialising a Binary Tree
    struct node *root = newNode(5);
    struct node *p1 = newNode(3);
    struct node *p2 = newNode(6);
    struct node *p3 = newNode(1);
    struct node *p4 = newNode(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    //         5
    //        / \
    //       3   6
    //      / \  
    //     1   4

    // calling the function for preorder traversal
    inorder(root);
    printf("\n%d", isBST(root));
    return 0;
}

struct node *newNode(int data)
{
    struct node *p;                                 // creating a node pointer
    p = (struct node *)malloc(sizeof(struct node)); // allocating memory for the node
    p->data = data;                                 // assigning the data to the node
    p->left = NULL;                                 // assigning the left child to NULL
    p->right = NULL;                                // assigning the right child to NULL
    return p;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {                              // if the root is not NULL
        inorder(root->left);       // call the function for the left child
        printf("%d ", root->data); // print the data of the root
        inorder(root->right);      // call the function for the right child
    }
}

int isBST(struct node *root)
{
    if (root == NULL)              // if the root is NULL return 1 
        return 1;
    if (root->left != NULL && root->left->data > root->data)   // if the left child is not NULL and the left child data is greater than the root data return 0
        return 0;
    if (root->right != NULL && root->right->data < root->data) // if the right child is not NULL and the right child data is less than the root data return 0
        return 0;
    if (!isBST(root->left) || !isBST(root->right))             // if the left and right child are not BST return 0
        return 0;
    return 1;                      // if all the conditions are satisfied return 1
}