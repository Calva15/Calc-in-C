#ifndef HISTORY_H
#define HISTORY_H

typedef struct
{
    char operation;     // Operation performed
    double operand1;   // First operand
    double operand2;  // Second operand
    double result;   // Result of the operation
} Calculation;

// Function Prototypes
void save_to_history(char operation, double operand1, double operand2, double result);
void display_history();
void clear_history();

#endif // HISTORY_H