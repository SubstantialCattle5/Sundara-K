/**
 * Dictionary Declaration file created for the Networking library
 *
 * Creator - nilay sharan
 * 15th dec 2023.
 *
 */
#ifndef NETWORKING_DICTIONARY_H
#define NETWORKING_DICTIONARY_H

#include "../tree/BinarySearchTree.h"
#include "Entry.h"


struct Dictionary {
    struct BinarySearchTree binary_search_tree;
    void (*insert)(struct Dictionary *dictionary,void *key, int key_size, void *value, int value_size) ;
    void * (*search) (struct Dictionary *dictionary,void *key);
};

/**
 * Constructs a Dictionary
 * @param compare - pass the compare function which is going to be used by the under the hood binary search tree
 * @return dictionary
 */
struct Dictionary dictionary_constructor(int (*compare)(void *key_one , void *key_two)) ;
struct Dictionary dictionary_destructor(struct Dictionary *dictionary) ;


#endif //NETWORKING_DICTIONARY_H
