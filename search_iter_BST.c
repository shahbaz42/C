#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int); // function for adding new nodes
struct node *searchIter_BST(struct node *, int);  // function for searching in an iterative way

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

    struct node *ptr = searchIter_BST(root, 5);

    if (ptr != NULL)
        printf("%d", ptr->data);
    else
        printf("Not Found");

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

struct node *searchIter_BST(struct node *root, int key)
{
    while (root != NULL)              // while the root is not null  
    {
        if (root->data == key)        // if the root data is equal to the key
            return root;              // return the root
        else if (key < root->data)    // if the key is less than the root data 
            root = root->left;        // move to the left child
        else                          // if the key is greater than the root data
            root = root->right;       // move to the right child
    }

    return NULL;
}