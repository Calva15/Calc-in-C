#include <stdio.h>
#include <math.h>

char operator;
double num1, num2, result;

int main() {
    while (1) {
        // Ask User for input
        printf("Enter an operator (+, -, *, /, %%, ^) or 'q' to quit: ");
        scanf(" %c", &operator);

        // Exit if the user wants to quit
        if (operator == 'q') {
            break;
        }

        // Validates Operator
        while (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%' && operator != '^') {
            printf("Invalid operator! Please enter a valid operator (+, -, *, /, %%, ^) or 'q' to quit: ");
            scanf(" %c", &operator);
            if (operator == 'q') {
                return 0;
            }
        }

        // Validates Operands
        while (1) {
            printf("Enter two operands: ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("Invalid input! Please enter two valid numbers.\n");
                while (getchar() != '\n'); // Clears input buffer
            } else {
                break; // Exit loop if valid numbers are entered
            }
        }

        // Perform calculation based on the operator
        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    printf("Error! Division by zero.\n");
                    continue; // Skip the rest of the loop and prompt again
                }
                break;
            case '%':
                if ((int)num2 != 0) {
                    result = (int)num1 % (int)num2;
                } else {
                    printf("Error! Division by zero.\n");
                    continue; // Skip the rest of the loop and prompt again
                }
                break;
            case '^':
                result = pow(num1, num2);
                break;
        }

        // Output results
        printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
    }

    return 0;
}