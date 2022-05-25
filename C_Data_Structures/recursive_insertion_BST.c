# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int); // function for adding new nodes
void inorder(struct node*);  //function for for preorder traversal
struct node* insert_BST_recursive(struct node*, int); // recursive function to insert node in a BST

int main (){
    // creating and initialising a Binary Tree
    struct node* root = NULL;
    root = insert_BST_recursive(root, 4);
    insert_BST_recursive(root, 1);
    insert_BST_recursive(root, 2);
    insert_BST_recursive(root, 2);
    insert_BST_recursive(root, 5);
    insert_BST_recursive(root, 6);

    //         4
    //        / \
    //       1   5
    //        \   \
    //         2   6 

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

struct node* insert_BST_recursive(struct node* root, int key){  // recursive function to insert node in a BST
    if (root == NULL)                                           // if the root is NULL
        return newNode(key);                                    // return a new node

    else if(key == root->data){                                 // if the key is equal to the root's data do not insert
        printf("Already present in BST");                      
        return root;
    }

    else if (key < root->data){                                // if the key is less than the root's data
        root->left = insert_BST_recursive(root->left, key);    // call the function for the left child
    }

    else{
        root->right = insert_BST_recursive(root->right, key);  // if the key is greater than the root's data call the function for the right child
    }

}