#include <string.h>
#include "Node.h"


/**
 * Dynamically memory allocates the data
 * @param data
 * @param size
 * @return
 */

struct Node node_constructor(void *data, int size)
{
    if (size < 1) { // to check empty size
        printf("Invalid data size for node...\n");
        exit(1);
    }

    // Create a Node instance to be returned
    struct Node node;

    // Allocate space for the data if it is of a supported type
    node.data = malloc(size);
    memcpy(node.data, data, size);

    // Initialize the pointers.
    node.next = NULL;
    node.previous = NULL;

    return node;
}

/**
 * Frees the data memory allocation then deletes the node
 */
void node_destructor(struct Node *node)
{
    if (node != NULL) {
        free(node->data);
    } else {
        printf("Node is Null \n") ;
    }

}