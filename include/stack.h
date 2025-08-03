#pragma once
#include "stdbool.h"

// #define DEFAULT_STACK_SIZE 10;

#define NO_STACK_ERR 0
#define STACK_EMPTY 1
#define STACK_MEM_ERR 2

// typedef enum { STACK_SUCCESS,
//                STACK_ERROR } StackStatus;

typedef struct StackNode {
    struct StackNode *prev;
    char *value;
} StackNode;

typedef struct {
    char *data;
    int error;
} StackStatus;

typedef struct {
    //   int capacity;
    int size;
    StackNode *next;
} Stack;

bool stack_push(Stack *stack, char *value);

StackStatus stack_pop(Stack *stack);

StackStatus stack_peek(Stack *stack);

void stack_resize(Stack *stack);

Stack *create_stack();