
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue_structures.h"
#include "queue.h"

/*
 * create a Data item for the queue
 */
Data *createData(int val ) {
  Data *new = malloc(sizeof(Data));
  new->value = val;
  return new;
}

/*
 * allocate and initialise a queue data structure 
 */
Queue *createQueue( void ) {
    Queue *new = malloc(sizeof(Queue));
    new->blockSize = 8u;
    new->size = new->blockSize;
    new->data = calloc(new->size,sizeof(Data*));  // allocate an initial block for queue storage

    new->front = 0; //NEVER changes.
    new->back = -1;

    return new;
}

/*
 * reallocate dynamic array data if we have reached queue->size
 */
void enlargeQueue( Queue *queue ) {
    queue->size += queue->blockSize;
    queue->data = realloc(queue->data, queue->size*sizeof(Data*)); // allocate a further 'block' to the queue to increase size
    return;
}

/*
 * join a Data item onto the queue at the back
 */
void join( Queue *queue, Data *new ) {

    if (queue->length >= queue->size) {
        //Re-allocate more memory.
        enlargeQueue(queue);
    }

    queue->data[++queue->back] = new;
    queue->length++;

    return;
}

/*
 * remove the front Data item from the queue
 */

#define SIZE_B(N) ((N) * sizeof(Data*))
Data *leave( Queue *queue ) {

    if (queue->back == -1) {
        //No elements to pop.
        return NULL;
    }
    //Return and remove first element.
    Data* removed = queue->data[queue->back--];
    memcpy(
        queue->data + SIZE_B(queue->front), //Dest
        queue->data + SIZE_B(1), //Src
        --queue->length //Length of the queue
    ); //Shift queue back.

    return removed;
}

/*
 * display queue data - traverse list from front to back
 */
void displayQueue ( Queue *queue ) {
    printf("Queue length %d\n",queue->length);
    for( int k=queue->front; k<queue->back; ++k )
        printf(" %d",queue->data[k]->value);
    printf("\n");
    return;
}

/*
 * free dynamic array data
 */
void freeQueue( Queue *queue ) {
    for( unsigned int k=0; k<queue->size; k++ )
        free( queue->data[k] ); // free queue Data item
    free( queue->data );        // free queue Data array
    return;
}
