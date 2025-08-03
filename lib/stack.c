#include "../include/stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool stack_push(Stack *stack, char *value) {
        StackNode *top = stack->next;
        StackNode *new_el = malloc(sizeof(StackNode));

        if (new_el == NULL) {
                return false;
        }

        stack->next = new_el;
        //   if(stack->size > 0){
        new_el->prev = top;

        stack->size++;

        return true;
        //   }
}

StackStatus stack_pop(Stack *stack) {
        StackStatus status = {.data = NULL, .error = STACK_EMPTY};

        if (stack->size == 0) {
                return status;
        }

        StackNode *top = stack->next;
        stack->next = top->prev;

        status.data = top->value;
        status.error = NO_STACK_ERR;

        free(top);

        stack->size--;

        return status;
}

StackStatus stack_peek(Stack *stack) {
        StackStatus status = {.data = NULL, .error = STACK_EMPTY};

        if (stack->size == 0) {
                return status;
        }

        char *result = _strdup(stack->next->value);
        if (result == NULL) {
                status.error = STACK_MEM_ERR;
                return status;
        }

        status.data = result;
        status.error = NO_STACK_ERR;

        return status;
}

Stack *create_stack() {
        Stack *stack = malloc(sizeof(Stack));

        //   stack->capacity = DEFAULT_STACK_SIZE;
        stack->size = 0;
        stack->next = NULL;

        return stack;
}