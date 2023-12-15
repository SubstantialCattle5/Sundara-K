//
// Created by nilay on 12/15/23.
//

#ifndef NETWORKING_BINARYSEARCHTREE_H
#define NETWORKING_BINARYSEARCHTREE_H

#include "../common/Node.h"

struct BinarySearchTree {

    struct Node *head;


    /**
     * Compare function would be user defined
     * @param data_one
     * @param data_two
     * @return int -> -1 if false and 1 if true.
     */
    int (*compare) (void *data_one , void *data_two) ;

    /**
     * Search function would return the node being search
     * @param tree - pointer to the binary search tree
     * @param data - pointer to the data stored
     * @return * void - would return the value..
     */
    void * (* search) (struct BinarySearchTree *tree, void *data) ;

    /**
     *
     * @param tree
     * @param data
     * @param size
     */
    void (* insert) (struct BinarySearchTree *tree, void *data, int size) ;
};

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one , void *data_two)) ;

#endif //NETWORKING_BINARYSEARCHTREE_H
