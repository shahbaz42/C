# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int); // function for adding new nodes
void inorder(struct node*);  //function for for preorder traversal
void insert_BST(struct node*, int); // iterative function to insert node in a BST

int main (){
    // creating and initialising a Binary Tree
    struct node* root = newNode(4);
    insert_BST(root, 1);
    insert_BST(root, 2);
    insert_BST(root, 3);
    insert_BST(root, 5);
    insert_BST(root, 6);

    //         4
    //        / \
    //       1   6
    //      / \  
    //     5  2 

    inorder(root);
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

void inorder(struct node* root){
    if(root != NULL){ // if the root is not NULL
        inorder(root->left); // call the function for the left child
        printf("%d ", root->data); // print the data of the root
        inorder(root->right); // call the function for the right child
    }
}

void insert_BST(struct node* root, int key){   // for inserting a node into BST
    struct node* prev = NULL;                  // trailing pointer to root node

    while(root != NULL){                       // traversing to the leaf where new node is to be inserted
        prev = root;
        if(key == root->data){                 // if key is already present then no insertion
            printf("Value is already present in BST");
            return;
        }
        if(key < root->data)                   // navigating around binary tree
            root = root->left;
        else
            root = root->right;
    }
    
    struct node* new = newNode(key);           // creating node to be inserted

    if(key < prev->data)                       // inserting in appropriate place
        prev->left = new;
    else
        prev->right = new;
}