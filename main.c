#include "include/binary_tree.h"
#include "include/stack.h"
#include "include/utils.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

int multiply(int *first, int *second) {
    printf("Memory address of first: %p\n", first);
    *first = 30;
    return *first * *second;
}

int add(int first, int second) {
    printf("Memory address of first: %p\n", &first);
    first = 50 / 2;
    return first + second;
}

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    char name[] = "abc\0";
    int e[3];
    e[1] = 0;
    int age = 5;

    int *p, q;

    int ages[3] = {10, 29, 39};

    printf("The value of the 1st elem is: %d\n", *(ages + 0));
    printf("The value of the 2nd elem is: %d\n", *(ages + 1));
    printf("The value of the 3rd elem is: %d\n", *(ages + 2));
    // add_char("", 3, 'c');

    int one = 1;
    int two = 2;

    swap(&one, &two);

    printf("The value of one is: %d\n", one);
    printf("The value of two is: %d", two);

    // printf("Sizeof randomly generated string is: ");

    return 0;
}