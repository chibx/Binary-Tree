#include "./include/utils.h"
#include "stdio.h"
#include <stdbool.h>


int main() {
        char *expression = "A * B + C";
        char *result = infix_to_postfix(expression);

        printf("%s\n", result);

        return 0;
}