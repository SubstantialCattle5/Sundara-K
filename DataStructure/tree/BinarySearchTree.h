/**
 * Declaration file of Binary Search Tree
 * The file is the part of networking library
 *
 * Inspired by -
 * https://www.geeksforgeeks.org/binary-search-tree-data-structure/
 * Created By Nilay Nath Sharan
 * 15th Dec 2023.
 */

#ifndef NETWORKING_BINARYSEARCHTREE_H
#define NETWORKING_BINARYSEARCHTREE_H

#include "../common/Node.h"

struct BinarySearchTree {

    struct Node *head;

    /**
     * Compare function would be user defined.
     * @param data_one - void pointer
     * @param data_two - void pointer
     * @return int -> -1 if false and 1 if true.
     */
    int (*compare) (void *data_one , void *data_two) ;

    /**
     * Returns the node which is being searched.
     * @param tree - pointer to the binary search tree
     * @param data - pointer to the data stored
     * @return * void - would return the value.
     */
    void * (* search) (struct BinarySearchTree *tree, void *data) ;

    /**
     * Inserts the data
     * @param tree - pointer to the binary search tree.
     * @param data - pointer to the data being stored.
     * @param size - size of the data
     */
    void (* insert) (struct BinarySearchTree *tree, void *data, int size) ;
};

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one , void *data_two)) ;

#endif //NETWORKING_BINARYSEARCHTREE_H
