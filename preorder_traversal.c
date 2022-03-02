# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int); // function for adding new nodes
void preorder(struct node*);  //function for for preorder traversal

int main (){
    // creating and initialising a Binary Tree
    struct node* root = newNode(4);
    struct node* p1 = newNode(1);
    struct node* p2 = newNode(6);
    struct node* p3 = newNode(5);
    struct node* p4 = newNode(2);
    
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    // calling the function for preorder traversal
    preorder(root);
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

void preorder(struct node* root){
    if(root != NULL){ // if the root is not NULL
        printf("%d ", root->data); // print the data of the root
        preorder(root->left); // call the function for the left child
        preorder(root->right); // call the function for the right child
    }
}