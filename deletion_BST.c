# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void insertion_sort(int arr[], int n);

struct node* newNode(int); // function for adding new nodes
void inorder(struct node*);  //function for for preorder traversal
struct node* insert_BST_recursive(struct node*, int); // recursive function to insert node in a BST
struct node* delete_node_BST(struct node*, int); // recursive function to delete node in a BST
struct node* find_inorder_predecessor(struct node*);

int main (){
    // creating and initialising a Binary Tree

    struct node* root = NULL;
    root = insert_BST_recursive(root, 8);
    insert_BST_recursive(root, 3);
    insert_BST_recursive(root, 10);
    insert_BST_recursive(root, 1);
    insert_BST_recursive(root, 6);
    insert_BST_recursive(root, 14);
    insert_BST_recursive(root, 4);
    insert_BST_recursive(root, 7);
    insert_BST_recursive(root, 13);

    //          8
    //        /   \
    //       3     10
    //      / \      \
    //     1   6      14
    //        / \     /
    //       4   7   13
    printf("inorder traversal before deletion : ");
    inorder(root);
    printf("\ninorder traversal after deletio (8) : ");
    delete_node_BST(root, 8);
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

struct node* find_inorder_predecessor(struct node* root){      // function for finding inorder predessor of a node
    root = root->left;                                         // we traverse to left child
    while(root->right != NULL){                                // we keep moving to right until we reach to leaf node.
        root = root->right;
    }
    return root; 
}

struct node* delete_node_BST(struct node* root, int key)
{
    // base case
    if (root == NULL)                                    // base case
        return root;
 
    if (key < root->data)                                // navigating to the node to be deleted
        root->left = delete_node_BST(root->left, key);
 
    else if (key > root->data)                           // navigating to the node to be deleted
        root->right = delete_node_BST(root->right, key);
 
    else {                                               // for node to be deleted
        if (root->left == NULL) {                        // if node has a single right child  
            struct node* in_pre = root->right;
            free(root);
            return in_pre;
        }
        else if (root->right == NULL) {                  // if node has a single left child 
            struct node* in_pre = root->left;
            free(root);
            return in_pre;
        }
 
        struct node* in_pre = find_inorder_predecessor(root); // finding inorder child for replacement
 
        root->data = in_pre->data;                            // replacing data of to be deleted node with its inorder predecessor 
 
        root->left = delete_node_BST(root->left, in_pre->data);  // deleting inorder predecessor
    }
    return root;
}
