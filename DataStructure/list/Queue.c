/**
 * Queue.c
 * Data Structure Library created for Networking library
 * 
 * Created by Nilay Nath Sharan
 * 15th Dec 2023.
*/
#include "Queue.h"


// MARK FUNCTION PROTOTYPE
void * peek(struct Queue *queue);
void pop (struct Queue *queue);
void push(struct Queue *queue,void *data, unsigned long size) ;


/**
 * queue_constructor - Constructs a queue
 * @param void - No parameters
 * @return struct Queue - The constructed queue
*/
struct Queue queue_constructor()
{
    struct Queue queue;
    queue.list = linked_list_constructor();

    queue.push = push;
    queue.pop = pop;
    queue.peek = peek ;

    return queue;
}

// PRIVATE FUNCTIONS
/**
 * queue_destructor - Destroys the given queue
 * @param queue - The queue to be destroyed
 * @return void
*/
void queue_destructor(struct Queue *queue)
{

    linked_list_destructor(&queue->list);
}



// MARK PUBLIC FUNCTIONS
/**
 * push - Pushes data into the queue
 * @param data - The pointer to the data to be pushed into the queue
 * @param queue - The pointer to the queue in which the data is to be pushed
 * @param size - The size of the data being pushed
 * @return void
*/
void push(struct Queue *queue, void *data,  unsigned long size)
{
    if (data == NULL || queue == NULL) {
        // Handle null pointers gracefully
        return;
    }
    queue->list.insert(&queue->list, queue->list.length, data, size);
}

/**
 * pop - Pops data from the queue
 * @param queue - The pointer to the queue from which the data is to be popped
*/
void pop(struct Queue *queue) {
    if (queue->list.length == 0) {
        printf("The Queue is empty....") ;
        return ;
    }
    void *data = queue->list.retrieve(&queue->list,0);
    queue->list.remove(&queue->list,0);
}

/**
 * Peeks the first element in queue
 * @param queue
 * @return void pointer to the node data
 */
void * peek(struct Queue *queue) {
    if (queue->list.length == 0) {
        printf("The Queue is empty....") ;
        return NULL;
    }
    void *data = queue->list.retrieve(&queue->list,0);
    return data;
}

