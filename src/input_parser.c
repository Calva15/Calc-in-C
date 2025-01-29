#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"
#include "input_parser.h"

double evaluate_expression(const char *expression){
    //Temporary: Use 'System' to evaluate the expression via bc (Linux/macOS)
    char command[100];
    snprintf(command, sizeof(command), "echo 'scale=10; %s' | bc", expression);

    FILE *fp = popen(command, "r");
    if (!fp){
        fprintf(stderr, "Error: Failed to run command\n");
        return 0;
    }
    double result;
    fscanf(fp, "%lf", &result);
    pclose(fp);

    return result;

}