/**
 * Queue.c
 * Data Structure Library created for Networking library
 * 
 * Created by Nilay Nath Sharan
 * 15th Dec 2023.
*/
#include "Queue.h"




void * peek(struct Queue *queue);
void pop (struct Queue *queue);
void push(void *data, struct Queue *queue, int data_type , int size) ;


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

/**
 * queue_destructor - Destroys the given queue
 * @param queue - The queue to be destroyed
 * @return void
*/
void queue_destructor(struct Queue *queue)
{
    linked_list_destructor(&queue->list);
}

/**
 * push - Pushes data into the queue
 * @param data - The pointer to the data to be pushed into the queue
 * @param queue - The pointer to the queue in which the data is to be pushed
 * @param data_type
 * @param size
 * @return void
*/
void push(void *data, struct Queue *queue, int data_type , int size)
{
    queue->list.insert(queue->list.length, data, &queue->list, data_type , size);
}

/**
 * pop - Pops data from the queue
 * @param queue - The pointer to the queue from which the data is to be popped
*/
void pop(struct Queue *queue) {
    void *data = queue->list.retrieve(0, &queue->list);
    queue->list.remove(0, &queue->list);
}

/**
 * Peeks the first element in queue
 * @param queue
 * @return void pointer to the node data
 */
void * peek(struct Queue *queue) {
    void *data = queue->list.retrieve(0,&queue->list);
    return data;
}

