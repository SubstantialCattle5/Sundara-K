/**
 * Declaration of Node.h -- Node structure
 * This file is part of the networking library 
 * 
 * Created by Nilay Nath Sharan
 * 15th December 2023. 
*/
#ifndef Node_h
#define Node_h

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure
 * @param data: pointer to the data
 * @param size : size of the data being stored
 * @param next: pointer to the next node
 * @param previous : pointer to the previous node
*/
struct Node
{
    /*PUBLIC MEMBERS VARIABLES*/
    // data is being stored as a void pointers
    void *data;

    struct Node *next;
    struct Node *previous;
};

/**
 * Node constructor to initialize a node
 * @param data : pointer to the data
 * @param data_type  : type of data being stored
 * @param size : size of the data
 * @return Node
 */
struct Node node_constructor(void *data, int size);

/**
 * To delete a node
 * @param node
 * @return void
 */
void node_destructor(struct Node *node);
#endif /* Node_h */