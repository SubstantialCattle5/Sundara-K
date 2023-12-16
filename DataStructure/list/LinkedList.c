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

//MARK : PRIVATE PROTOTYPE FUNCTIONS
struct Node * create_node_ll(void *data, unsigned long size);
void destroy_node_ll(struct Node *node_to_destroy);

//MARK : PUBLIC PROTOTYPE FUNCTIONS
struct Node * iterate_ll(struct LinkedList *linked_list, int index);
void insert_ll(struct LinkedList *linked_list, int index, void *data, unsigned long size);
void remove_node_ll(struct LinkedList *linked_list, int index);
void * retrieve_ll(struct LinkedList *linked_list, int index);

struct LinkedList linked_list_constructor()
{
    struct LinkedList new_list;
    new_list.head = NULL;
    new_list.length = 0;

    new_list.insert = insert_ll;
    new_list.remove = remove_node_ll;
    new_list.retrieve = retrieve_ll;

    return new_list;
}

struct Node * create_node_ll(void *data, unsigned long size)
{
    // Allocate space.
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // Call the constructor.
    *new_node = node_constructor(data, size);
    return new_node;
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
        linked_list->remove(linked_list,0);
    }
}

// MARK : PRIVATE FUNCTIONS

/**
 * create_node - Creates a node with the given data
 * @param data - The data to be inserted in the node
 * @param data_type
 * @param size
 * @return * Node - pointer to the node created
*/
struct Node * create_node_LL(void *data, unsigned long size)
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
void destroy_node_ll(struct Node *node_to_destroy)
{
    // calling the node destructor to destroy the node data
    node_destructor(node_to_destroy);

    // destroying the memory allocated to the node
    free(node_to_destroy);
}

/**
 * iterate - Iterates through the linked list to find the node at the given index
 * @param index - The index at which the node is to be found
 * @param linked_list - The pointer to the linked list in which the node is to be found
 * @return * Node - pointer to the node at the given index
*/
struct Node * iterate_ll(struct LinkedList *linked_list,int index)
{
    if (index < 0 || index >= linked_list->length) 
    {
        return NULL; // TODO: Change this to a better error code
    }

    // creating the cursor for the node implementation
    struct Node *cursor = linked_list->head;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}

// MARK: PUBLIC FUNCTIONS

/**
 * insert-node - Inserts a node at the given index in the linked List 
 * @param index - The index at which the data is to be inserted
 * @param data - The data to be inserted
 * @param linked_list - The pointer to the linked list in which the data is to be inserted
 * @param data_type - The type of data present in the node
 * @param size - The size of the data present in the node
 * @return void
*/
void insert_ll(struct LinkedList *linked_list, int index, void *data, unsigned long size)
{
    // Create a new node to be inserted.
    struct Node *node_to_insert = create_node_ll(data, size);
    // Check if this node will be the new head of the list.
    if (index == 0)
    {
        // Define the Node's next.
        node_to_insert->next = linked_list->head;
        // Re-define the List's head.
        linked_list->head = node_to_insert;
    }
    else
    {
        // Find the item in the list immediately before the desired index.
        struct Node *cursor = iterate_ll(linked_list, index - 1);
        // Set the Node's next.
        node_to_insert->next = cursor->next;
        // Set the cursor's next to the new node.
        cursor->next = node_to_insert;

    }
    // Increment the list length.
    linked_list->length += 1;
}

/**
 * remove_node - Removes a node at the given index in the linked list 
 * @param index - The index at which the data is to be removed
 * @param linked_list - The pointer to the linked list in which the data is to be removed
 * @return void
*/
void remove_node_ll(struct LinkedList *linked_list, int index)
{
    // Check if the item being removed is the head.
    if (index == 0)
    {
        // Collect the node to be removed.
        struct Node *node_to_remove = linked_list->head;
        // Define the new head of the list.
        linked_list->head = node_to_remove->next;
        // Remove the desired node.
        destroy_node_ll(node_to_remove);
    }
    else
    {
        // Find the item in the list before the one that is going to be removed.
        struct Node *cursor = iterate_ll(linked_list, index - 1);
        // Use the cursor to define the node to be removed.
        struct Node *node_to_remove = cursor->next;
        // Update the cursor's next to skip the node to be removed.
        cursor->next = node_to_remove->next;
        // Remove the node.
        destroy_node_ll(node_to_remove);
    }
    // Decrement the list length.
    linked_list->length -= 1;
}

/**
 * retrieve_data - Retrieves the data at the given index in the linked list
 * @param index - The index at which the data is to be retrieved
 * @param linked_list - The pointer to the linked list in which the data is to be retrieved
 * @return pointer to void meaning it can return any value
*/
void * retrieve_ll(struct LinkedList *linked_list, int index)
{
    // Find the desired node and return its data.
    struct Node *cursor = iterate_ll(linked_list, index);
    if (cursor)
    {
        return cursor->data;
    }
    else
    {
        return NULL;
    }
}