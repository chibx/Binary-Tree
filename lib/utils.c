#include "../include/utils.h"
#include "../include/stack.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Max tokens for a variable name
#define MAX_TOKEN 100

const char *operators[] = {"**", "/", "*", "+", "-"};

const float operator_precedence[] = {4.0, 3.1, 3.0, 2.1, 2.0};

ParseStatus is_start_token(char token) {
    ParseStatus status = {.error = true};
    if (token >= 48 && token <= 57) {
        status.message = _strdup("Numbers cannot start variables");
        return status;
    }

    if (!(tolower(token) >= 'a' /** 97 ASCII of a */ && tolower(token) <= 'z' /** 122 ASCII of z */) && token != '$' && token != '_') {
        // printf("Invalid Character %c found at the beginning of an identifier\n", token);
        status.message = malloc(70);
        sprintf(status.message, "Invalid Character %c found at the beginning of an identifier", token);
        return status;
    }

    status.error = false;
    return status;
}

bool is_operator(char *text, int index) {
    char curr = text[index];
    char next = text[index + 1];
    if (curr == '*' || (curr == '*' && next == '*') || curr == '/' || (curr == '/' && next == '/') || curr == '+' || curr == '-') {
    }

    return false;
}

ParseStatus is_valid_token(char token) {
    ParseStatus status = {.error = true};

    if (!(tolower(token) >= 'a' /** 97 ASCII of a */ && tolower(token) <= 'z' /** 122 ASCII of z */) &&
        !(token >= 48 && token <= 57) && token != '$' && token != '_') {
        status.message = _strdup("Numbers cannot start variables\n");
        return status;
    }

    status.error = false;
    return status;
}

char *infix_to_postfix(char *valid_infix) {
    Stack *operator_stack = create_stack();
    int length = strlen(valid_infix);
    bool inWord = false;
    bool hasSpace = false;

    // To store letter or perfectly defined variables
    char *buffer = calloc(MAX_TOKEN, 1);

    for (int i = 0; i < length; i++) {

        // Word parsing logic
        while (valid_infix[i] != ' ') {
            hasSpace = false;

            char inner_curr = valid_infix[i];
            // if (inner_curr == ' ') {
            //     break;
            // }
            if (!inWord) {
                inWord = true;
                ParseStatus status = is_start_token(inner_curr);

                if (status.error) {
                    printf("%s", status.message);
                    exit(EXIT_FAILURE);
                }
            } else {
                ParseStatus status = is_valid_token(inner_curr);

                if (status.error) {
                    printf("%s", status.message);
                    exit(EXIT_FAILURE);
                }
            }

            add_char(buffer, MAX_TOKEN, inner_curr);

            if (i >= length) {
                //  TODO Come back to this
                break;
            }

            // if (inner_curr == ' ') {
            //     inWord = false;
            //     break;
            // }

            i++;
        }

        if (valid_infix[i] != ' ') {
            hasSpace = true;
            continue;
        }

        inWord = false;

        if (2) {
        }
    }

    return "";
}

/// Size here is the size of the memory allocated for the string i.e `strlen(str) + 1`
void add_char(char *string, int size, char letter) {
    int start = 0;
    for (int i = 0; i < size; i++) {
        if (start > size) {
            return;
        }
        if (string[i] == '\0') {
            string[i] = letter;
            string[i + 1] = '\0';

            return;
        }

        start++;
    }
}

/// Size here is the size of the memory allocated for the string i.e `strlen(str) + 1`
void clear_string(char *string, int size) {
    int start = 0;

    for (int i = 1; i < size; i++) {
        if (start > size) {
            return;
        }

        string[i] = 0;

        start++;
    }
}

int get_specificity(char *operator) {
    const int length = sizeof(operators) / sizeof(char *);

    for (int i = 0; i < length; i++) {
        if (strcmp(operator, operators[i]) == 0) {
            return operator_precedence[i];
        };
    }

    return -1;
}