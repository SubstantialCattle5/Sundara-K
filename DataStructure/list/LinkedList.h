/**
 * LinkedList.h - Header file for the LinkedList data structure
 * For the implementation of the LinkedList data structure, refer to LinkedList.c
 * Created for the Networking Library 
 * 
 * Created by - Nilay Nath Sharan 
 * 15th Dec 2023. 
*/

#ifndef LinkedList_h
#define LinkedList_h

#include <stdlib.h>
#include <stdio.h>
#include "../common/Node.h"

struct LinkedList
{
    /**
     * The head of the linked list
    */
    struct Node *head;

    /**
     * The length of the linked list
    */
    int length;

    /**
     * insert - Inserts a node at the given index in the linked list pointer to the data to be inserted
     * @param index - The index at which the data is to be inserted
     * @param data - The pointer to the data to be inserted
     * @param linked_list - The pointer to the linked list in which the data is to be inserted
     * @param size
     * @return void
    */
    void (*insert)(int index, void *data, struct LinkedList *linked_list,  int size);

    /**
     * remove - Removes a node at the given index in the linked list 
     * @param index - The index at which the data is to be removed
     * @param linked_list - The pointer to the linked list in which the data is to be removed
     * @return void
    */
    void (*remove)(int index, struct LinkedList *linked_list);

    /**
     * retrieve - Retrieves a node at the given index in the linked list 
     * @param index - The index at which the data is to be retrieved
     * @param linked_list - The pointer to the linked list in which the data is to be retrieved
     * @return pointer to void meaning it can return any value
    */
    void * (*retrieve)(int index, struct LinkedList *linked_list);
};

/**
 * linked_list_constructor - Constructs a linked list
 * @param void - No parameters
 * @return struct LinkedList - The constructed linked list
*/
struct LinkedList linked_list_constructor(void);

/**
 * linked_list_destructor - Destructs a linked list
 * @param linked_list - The pointer to the linked list to be destructed
 * @return void
*/
void linked_list_destructor(struct LinkedList *linked_list);

#endif /* LinkedList_h */