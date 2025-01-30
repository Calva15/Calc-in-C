#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "input_parser.h"
#include "operations.h"

double evaluate_expression(const char *expression) {
    double result;

    // Handle factorial separately (since bc -l doesn't support it)
    if (strchr(expression, '!') != NULL) {
        int num;
        if (sscanf(expression, "%d!", &num) == 1) {
            return factorial(num);  // Use your factorial function
        } else {
            printf("Error: Invalid factorial input.\n");
            return 0;
        }
    }

    // Format trigonometric functions for bc -l
    char formatted_expression[256];
    strncpy(formatted_expression, expression, sizeof(formatted_expression) - 1);
    formatted_expression[sizeof(formatted_expression) - 1] = '\0'; // Ensure null termination

    // Replace "sin(x)" with "s(x)", "cos(x)" with "c(x)", "tan(x)" with "a(x)"
    char temp_expression[256];
    strcpy(temp_expression, formatted_expression);

    char *pos;
    while ((pos = strstr(temp_expression, "sin(")) != NULL) {
        *pos = 's';
        memmove(pos + 1, pos + 3, strlen(pos + 3) + 1);
    }
    while ((pos = strstr(temp_expression, "cos(")) != NULL) {
        *pos = 'c';
        memmove(pos + 1, pos + 3, strlen(pos + 3) + 1);
    }
    while ((pos = strstr(temp_expression, "tan(")) != NULL) {
        *pos = 'a';
        memmove(pos + 1, pos + 3, strlen(pos + 3) + 1);
    }

    // Ensure `bc` runs with `-l` flag for math support
    char command[300];
    snprintf(command, sizeof(command), "echo 'scale=10; %s' | bc -l", temp_expression);

    // Execute the command and read the result
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: Failed to run bc command.\n");
        return 0;
    }

    if (fscanf(fp, "%lf", &result) != 1) {
        printf("Error: Failed to read result from bc.\n");
        pclose(fp);
        return 0;
    }

    pclose(fp);
    return result;
}
