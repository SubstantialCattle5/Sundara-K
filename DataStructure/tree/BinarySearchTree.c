/**
 * Binary Search Tree Implementation
 * created for Networking file
 *
 * Created by - Nilay Nath Sharan
 * 15th Dec 2023.
 */
#include "BinarySearchTree.h"

struct Node * create_node(void *data, int size);
void destroy_node(struct Node *node_to_destroy);
struct Node * iterate(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction);
void * search(struct BinarySearchTree *tree, void *data);
void insert(struct BinarySearchTree *tree, void *data, int size);


struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one , void *data_two)) {
    struct BinarySearchTree tree ;
    tree.compare = compare;
    return tree;
};

// HELPER FUNCTIONS
/**
 * Helper function
 * Creates a node
 * @param data - pointer to the data being stored
 * @param size - the size of the memory allocation
 * @return Node
 */
struct Node * create_node(void *data, int size)
{
    // Allocates the space for the new node.
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Call the constructor and created a new node.
    *new_node = node_constructor(data, size);
    return new_node;
}

/**
 * Destroys the node present in the bst.
 * @param node_to_destroy
 * @return void
 */
void destroy_node(struct Node *node_to_destroy)
{
    node_destructor(node_to_destroy);
}

/**
 * Recursive function which traverses the BST in search of the data
 * @param tree - pointer to the BST tree.
 * @param cursor - pointer to the current cursor location.
 * @param data - pointer to the location of the data.
 * @param direction - left(1)/right(-1) / not-found(0)
 * @return
 */
struct Node * iterate(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction) {
    if(tree->compare(cursor->data,data) == 1 ) {
        if (cursor->next) {
            return iterate(tree,cursor->next,data,direction) ;
        } else {
            *direction = 1 ;
            return cursor ;
        }
    }
    else if (tree->compare(cursor->data,data) == -1) {
        if (cursor->previous) {
            return iterate(tree,cursor->previous,data,direction);
        } else {
            *direction = -1;
            return cursor;
        }
    }
    else {
        *direction = 0 ;
        return cursor ;
    }
}


// PUBLIC FUNCTIONS

/**
 * Returns the data present in the Binary Search Tree.
 * @param tree - pointer to the BST
 * @param data - pointer to the data
 * @return either the data or NULL
 */
void * search(struct BinarySearchTree *tree, void *data){
    int *direction = NULL;
    struct Node * cursor = iterate(tree,tree->head,data,direction) ;
    if (*direction == 0)  {
        return cursor->data;
    } else  {
        return NULL;
    }

}

/**
 * Inserts the Data in the Binary Search Tree.
 * @param tree - pointer to the BST
 * @param data - pointer to the data
 * @param size - the size of data being stored
 */
void insert(struct BinarySearchTree *tree , void *data , int size) {
    int *direction = NULL;

    // traverses the bst and returns the node where the data needs to be attached
    struct Node *cursor = iterate(tree, tree->head, data, direction);

    if (*direction == 1) //right
    {
        cursor->next = create_node(data, size);
    }
    else if (*direction == -1) //left
    {
        cursor->previous = create_node(data, size);
    }
}