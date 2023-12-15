/**
 * LinkedList - A linked list data structure
 * Created for the Networking Library
 * 
 * Constructor: 
 * linked_list_constructor - Constructs a linked list
 * 
 * Functions: 
 * iterate - Iterates through the linked list to find the node at the given index
 * retrieve_data - Retrieves the data at the given index in the linked list
 * create_node - Creates a node with the given data
 * destroy_node - Destroys the given node
 * insert_node - Inserts a node at the given index in the linked list
 * remove_node - Removes a node at the given index in the linked list
 * 
 * Created by - Nilay Nath Sharan
 * 15th Dec 2023.
*/

#include "LinkedList.h"

struct Node * create_node(void *data, int size);
void destroy_node(struct Node *node_to_destroy);

struct Node * iterate(int index, struct LinkedList *linked_list);
void insert_node(int index, void *data, struct LinkedList *linked_list, int size);
void remove_node(int index, struct LinkedList *linked_list);
void * retrieve_data(int index, struct LinkedList *linked_list);

struct LinkedList linked_list_constructor()
{
    struct LinkedList new_list;
    new_list.head = NULL;
    new_list.length = 0;

    new_list.insert = insert_node;
    new_list.remove = remove_node;
    new_list.retrieve = retrieve_data;

    return new_list;
}

/**
 * linked_list_destructor - Destroys the given linked list
 * @param linked_list - The linked list to be destroyed
 * @return void
*/
void linked_list_destructor(struct LinkedList *linked_list)
{
    for (int i = 0; i < linked_list->length; i++)
    {
        linked_list->remove(0, linked_list);
    }
}

/**
 * create_node - Creates a node with the given data
 * @param data - The data to be inserted in the node
 * @param data_type
 * @param size
 * @return * Node - pointer to the node created
*/
struct Node * create_node(void *data, int size)
{
    // Allocating memory for the node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    *new_node = node_constructor(data,size) ;
    return new_node;
}

/**
 * destroy_node - Destroys the given node
 * @param node_to_destroy - The node to be destroyed
 * @return void
*/
void destroy_node(struct Node *node_to_destroy)
{
    free(node_to_destroy->data);
    free(node_to_destroy);
}

/**
 * iterate - Iterates through the linked list to find the node at the given index
 * @param index - The index at which the node is to be found
 * @param linked_list - The pointer to the linked list in which the node is to be found
 * @return * Node - pointer to the node at the given index
*/
struct Node * iterate(int index, struct LinkedList *linked_list)
{
    if (index < 0 || index >= linked_list->length) 
    {
        printf("Index out of bound..");
        exit(9);  // TODO: Change this to a better error code
    }

    struct Node *cursor = linked_list->head;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}

/**
 * insert-node - Inserts a node at the given index in the linked List 
 * @param index - The index at which the data is to be inserted
 * @param data - The data to be inserted
 * @param linked_list - The pointer to the linked list in which the data is to be inserted
 * @param data_type - The type of data present in the node
 * @param size - The size of the data present in the node
 * @return void
*/
void insert_node(int index, void *data, struct LinkedList *linked_list, int size)
{
    struct Node *node_to_insert = create_node(data,size); // Creating a node with the given data

    if (index == 0) // check for head 
    {
        node_to_insert->next = linked_list->head;
        linked_list->head = node_to_insert;
    }
    else
    {
        struct Node *cursor = iterate(index - 1, linked_list);
        node_to_insert->next = cursor->next;
        cursor->next = node_to_insert;

    }
    linked_list->length += 1;
}

/**
 * remove_node - Removes a node at the given index in the linked list 
 * @param index - The index at which the data is to be removed
 * @param linked_list - The pointer to the linked list in which the data is to be removed
 * @return void
*/
void remove_node(int index, struct LinkedList *linked_list)
{
    if (index == 0) // check for head
    {
        struct Node *node_to_remove = linked_list->head; // Saving the head in a temporary variable
        linked_list->head = node_to_remove->next; // The head is now the next node (swip swap)
        destroy_node(node_to_remove); 
    }
    else
    {
        struct Node *cursor = iterate(index - 1, linked_list); // The node before the node to be removed
        struct Node *node_to_remove = cursor->next; // The node to be removed
        cursor->next = node_to_remove->next; // The node before the node to be removed now points to the node after the node to be removed
        destroy_node(node_to_remove); 
    }
    linked_list->length -= 1; 
}

/**
 * retrieve_data - Retrieves the data at the given index in the linked list
 * @param index - The index at which the data is to be retrieved
 * @param linked_list - The pointer to the linked list in which the data is to be retrieved
 * @return pointer to void meaning it can return any value
*/
void * retrieve_data(int index, struct LinkedList *linked_list)
{
    // pointer to the node at the given index
    struct Node *cursor = iterate(index, linked_list); 
    return cursor->data; // This is a void pointer
}