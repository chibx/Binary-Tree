#include "../include/queue.h"
#include <stdbool.h>

#pragma once

// typedef enum {
//     PARSE_SUCCESS,
//     /// When the user provides a number as first character of a variable
//     PARSE_ERROR_1,
//     /// When the user provides a character other than letters, $ and _ as
//     first character PARSE_ERROR_2,
// } ParseStatus;

typedef struct {
        char *message;
        bool error;
} ParseStatus;

ParseStatus is_start_token(char token);

ParseStatus is_valid_token(char token);

Queue *convert_to_arg_queue(char *valid_infix);

bool is_operator(char *text, int index);

void add_char(char *string, int size, char letter);

void clear_string(char *string, int size);

int get_specificity(char *_operator);

char *infix_to_postfix(char *valid_infix);