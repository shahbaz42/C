#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int max(int, int);               // function to find the maximum of two numbers
struct node *newNode(int);       // function for adding new nodes
int count_nodes(struct node *);  // function for counting nodes

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

    printf("%d", count_nodes(root));
    return 0;
}

int max(int a, int b){
    if(a>=b)
        return a;
    else
        return b;
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

int count_nodes(struct node* root){
    if (root == NULL){                             // if the root is NULL return 0
        return 0;
    } else {
        return count_nodes(root->left)+count_nodes(root->right) + 1 ;  // return the sum of the left and right subtrees plus 1 for the root
    }
}




