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

enum DataTypes {
    Special,
    Int,
    Long,
    Float,
    Double,
    Char,
    Bool
};
/**
 * Node structure
 * @param data: pointer to the data
 * @param data_type : type of data being stored
 * @param size : size of the data being stored
 * @param next: pointer to the next node
*/
struct Node
{
    void *data;
    int data_type;
    int size;
    struct Node *next;
};

/**
 * Node constructor to initialize a node
 * @param data : pointer to the data
 * @param data_type  : type of data being stored
 * @param size : size of the data
 * @return Node
 */
struct Node node_constructor(void *data, int data_type, int size);

/**
 * To delete a node
 * @param node
 * @return void
 */
void node_destructor(struct Node *node);
#endif /* Node_h */