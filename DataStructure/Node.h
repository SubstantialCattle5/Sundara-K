/**
 * Declaration of Node.h -- Node structure
 * This file is part of the networking library 
 * 
 * Created by Nilay Nath Sharan
 * 15th December 2023. 
*/
#ifndef Node_h
#define Node_h

/**
 * Node structure
 * @param data: pointer to the data
 * @param next: pointer to the next node
*/
struct Node
{
    void *data;
    struct Node *next;
};

#endif /* Node_h */