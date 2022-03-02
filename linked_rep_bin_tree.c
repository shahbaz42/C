# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int);

int main (){
    // creating parent node and assigning the data using function
    struct node* p = newNode(1);

    // // creating left child node without function
    // struct node *p1;
    // p1 = (struct node *) malloc(sizeof(struct node));
    // p1->left = NULL;
    // p1->right = NULL;

    // // creating right child node without function
    // struct node *p2;
    // p2 = (struct node *) malloc(sizeof(struct node));
    // p2->left = NULL;
    // p2->right = NULL;

    // creating two child nodes using function
    struct node *p1 = newNode(2);
    struct node *p2 = newNode(3);

    // assigning the left child to the parent node
    p->left = p1;
    // assigning the right child to the parent node
    p->right = p2;

    return 0;
}

struct node* newNode(int data){
    struct node* p; // creating a node pointer
    p = (struct node*) malloc(sizeof(struct node)); // allocating memory for the node
    p->data = data; // assigning the data to the node
    p->left = NULL; // assigning the left child to NULL
    p->right =NULL; // assigning the right child to NULL
    return p;
}
