//
// Created by nilay on 12/14/23.
//

#ifndef NETWORKING_LINKEDLIST_H
#define NETWORKING_LINKEDLIST_H


#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
struct LinkedList_int {
    struct Node_int *head ;
    int length ;

    void (*insert) (int index, int data , struct LinkedList_int *linked_list);
    void (*remove) (int index, struct LinkedList_int *linked_list ) ;
    int (*retrieve) (int index, struct LinkedList_int *lined_list);

};

//void insert_node_int(int index, int data, struct LinkedList_int *linked_list) ;
//void remove_node_int(int index, struct LinkedList_int *linked_list) ;
//int retrieve_data_int(int index, struct LinkedList_int *linked_list) ;


struct LinkedList_int linked_list_int_constructor() ;

#endif //NETWORKING_LINKEDLIST_H
