
#include <stdio.h>
#include <stdlib.h>

#include "stack_structures.h"
#include "stack.h"

int main( void ) {

    Stack *stack = createStack();

    // push() - add some data to the stack
    push(stack,createData(1));
    displayStack(stack);
    for (int i=0; stack->top<stack->size-1; i++) {push(stack, createData(i));}
    displayStack(stack);
    enlargeStack(stack);
    for (int i=0; stack->top<stack->size-1; i++) {push(stack, createData(2*i));}
    displayStack(stack);

    // free stack dynamic memory
    freeStack( stack );
    free( stack );
    
    return 0;
}
