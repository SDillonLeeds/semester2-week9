
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"
#include "stack_structures.h"
#include "stack.h"

/*
*  create and initialise the stack
 */
Stack* createStack( void ) {
    Stack* new = malloc( sizeof(Stack) );
    new->top = NULL;
    new->size = 0;
    return new;
}

/*
*  push - add a new Node item at the top of the stack
 */
void push( Stack* stack, int val ) {
    Node* new = createNode( createData( val ) );

    new->next = stack->top;           // add node at top
    stack->top = new;                 // move stack top
    stack->size++;                    // increase stack size

    return;
}

/*
*  pop - return the Node item on top of the stack
 */
Node* pop( Stack* stack ) {
    if( stack->size == 0 )           // check if stack is already empty
        return NULL;

    Node* node = stack->top;
    
    stack->top = node->next;         // move stack top
    stack->size--;                   // decrease stack size

    return node;
}
