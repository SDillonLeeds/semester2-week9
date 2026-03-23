
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"
#include "queue_structures.h"
#include "queue.h"

int main( void ) {

    // create an empty queue
    Queue *queue = createQueue();

    // test join 
    for (int i=0; i<12; i++) {join(queue, 10+i);}
    // - use traverseI() to display the nodes
    // - which pointer do you pass to traverseI(): front or back?
    traverseI(queue->front);

    // test leave 
    // - take care to free detached memory
    for (int i=queue->size; i>0; i--) {
        Node* node = leave(queue);
        printf("Left: %i\n", node->data->value);
        traverseI(queue->front);
    }

    // free queue memory
    freeNodes( queue->front );
    // free queue
    free(queue);

    return 0;
}
