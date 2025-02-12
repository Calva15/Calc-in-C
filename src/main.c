#include"ui.h" // Include the header file for the user interface
#include <string.h> // Include string.h for string functions
#include <stdio.h>  // Included standard library for input and output functions
#include <stdlib.h> // Include stdlib.h for exit() function
#include <math.h>   // Include math.h for power function
#include "ui.h"    // Include the header file for the user interface
#include "operations.h" // Include the header file for the operations
#include "history.h" // Include the header file for the history
#define EPSILON 1e-9 // A very small number to compare floating-point values
#define PI 3.141592653589793 // The value of pi
#include "input_parser.h" // Include the header file for the input parser
char operator;
double num1, num2, result;

// Function to clear the terminal screen
void clear_screen()
{
#ifdef _WIN32
    system("cls"); // Clear screen on Windows
#else
    system("clear"); // Clear screen on Unix-like systems
#endif
}


int main()
{
    // Display ASCII Art
    display_ascii_art();
    load_history(); // Load history from file

    while (1)
    {
        display_menu();

// NEW: Read full expression or operator
    char expression[100];
    printf("Enter a mathematical expression or select an operator: ");
    scanf(" %[^\n]", expression); // Reads full input (expression or operator)

    // If input is a single character and a valid operator, process normally
    if (strlen(expression) == 1 && strchr("+-*/%%^qSCT!v", expression[0])) {
        operator = expression[0]; // Process operator normally
    } else {
        // Otherwise, treat input as a mathematical expression
        result = evaluate_expression(expression);
        printf("Result: %s = %.2lf\n", expression, result);
        save_to_history('E', 0, 0, result);
        continue; // Skip normal operator handling
    }

    // Existing operator-based processing remains unchanged...

        // Exit if the user wants to quit
        if (operator== 'q')
        {
            clear_screen(); // Clear the screen before exiting
            exit(0);        // Exit the program successfully
        }
        if(operator == 'c'){ // Clear history
            char confirmation;
            printf("are you sure you want to clear history? (y/n): ");
            scanf(" %c", &confirmation);
            if (confirmation == 'y'){
            clear_history(); //calls function to clear history
            }
            else{
                printf("Operation cancelled.\n");
          
            }
            continue;
        }
            if( operator == 'h'){
            display_history(); //calls function to display history
            continue;
            }

            if(operator == 's')
            {
                printf("Please enter a number: ");
                    if(scanf("%lf", &num1) != 1){
                        printf("Invalid input! Please enter a valid number.\n");
                        while (getchar() != '\n')
                            ; // Clears input buffer
                            continue;
                    }
                    result = square_root(num1);
                    if(result != -1){
                        printf("Result: sqrt(%.2lf) = %.2lf\n", num1, result);
                        save_to_history('s', num1, 0, result);
                    }
                    continue;
            }

            if (operator == 'e'){
                printf("Enter a number: ");
                if(scanf("%lf", &num1)!=1){
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n')
                        ; // Clears input buffer
                        continue;
                }
                result = natural_log(num1); //calls function to find natural log
                if(result != -1){
                    printf("Result: ln(%.2lf) = %.2lf\n", num1, result);
                    save_to_history('e', num1, 0, result);
                }
                continue;
            }
            if(operator == 'l'){
                printf("Enter a number: ");
                if (scanf("%lf", &num1) != 1){
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clears input buffer
                    continue;
                }
                result = base10_log(num1); //calls function to find log base 10
                if(result != -1){
                    printf("Result: log10(%.2lf) = %.2lf\n", num1, result);
                    save_to_history('l', num1, 0, result);
                }
                continue;
            }
    if (operator == '$' || operator == ')' || operator == '(') {
    printf("Enter an angle in radians (you can use 'pi' for input): ");
    char input[50]; // Temporary string for input
    scanf("%s", input); // Read the input as a string

    // Check if the input contains 'pi'
    if (strstr(input, "pi") != NULL) {
        double multiplier = 1.0; // Default multiplier for 'pi'

        // If the input starts with a number (e.g., "2pi" or "0.5pi")
        if (strncmp(input, "pi", 2) != 0) {
            multiplier = atof(input); // Convert the numeric prefix to double
        }

        num1 = multiplier * PI; // Multiply by PI
    } else {
        // Handle non-pi numeric input
        num1 = atof(input); // Convert input to double
        if (num1 == 0 && input[0] != '0') {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
    }

    // Perform the trigonometric calculation
    if (operator == '$') {
        result = sine(num1);
        printf("Result: sin(%.2lf) = %.2lf\n", num1, result);
        save_to_history('$', num1, 0, result);
    } else if (operator == '(') {
        result = cosine(num1);
        printf("Result: cos(%.2lf) = %.2lf\n", num1, result);
        save_to_history('(', num1, 0, result);
    } else if (operator == ')') {
        // Handle undefined tangent
        if (fabs(cos(num1)) < EPSILON) {
            printf("Error: Tangent is undefined for this angle (cosine is zero).\n");
        } else {
            result = tangent(num1);
            // Check if the result is close to zero
        if (fabs(result) < EPSILON) {
            result = 0.00; // Force result to exactly zero
        }
            printf("Result: tan(%.2lf) = %.2lf\n", num1, result);
            save_to_history(')', num1, 0, result);
        }
    }
    continue; // Skip to the next iteration of the main loop
}

        if (operator == '!') {
    printf("Enter a non-negative integer: ");
    int num;
    char leftover; // Variable to check for extra characters

    // Ensure input is a valid integer without any decimal parts
    if (scanf("%d%c", &num, &leftover) != 2 || leftover != '\n' || num < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        while (getchar() != '\n'); // Clear buffer
        continue;
    }

    long long result = factorial(num);
    if (result != -1) { // Only print if valid
        printf("Result: %d! = %lld\n", num, result);
        save_to_history('!', num, 0, result);
    }
    continue;
        }
            if(operator == 'v'){
                printf("Enter a number: ");
                    if(scanf("%lf", &num1) != 1){
                        printf("Invalid input! Please enter a valid number.\n");
                        while (getchar() != '\n')
                            ; // Clears input buffer
                            continue;
                    }
                    result = exponential(num1);
                    printf("Result: e^%.2lf = %.2lf\n", num1, result);
                    save_to_history('v', num1, 0, result);
                    continue;
            }

            if (operator == 'S' || operator == 'C' || operator == 'T') {
                printf("Enter a number: ");
                 if (scanf("%lf", &num1) != 1) {
                     printf("Invalid input! Please enter a valid number.\n");
                 while (getchar() != '\n'); // Clear buffer
            continue;
    }

            if (operator == 'S') {
             result = inverse_sine(num1);
                 if (result != -1) { // Only print if valid
                  printf("Result: asin(%.2lf) = %.2lf radians\n", num1, result);
                     save_to_history('S', num1, 0, result);
                    }
                  }   else if (operator == 'C') {
                result = inverse_cosine(num1);
            if (result != -1) { // Only print if valid
        printf("Result: acos(%.2lf) = %.2lf radians\n", num1, result);
    save_to_history('C', num1, 0, result);
}
    } else if (operator == 'T') {
        result = inverse_tangent(num1);
        printf("Result: atan(%.2lf) = %.2lf radians\n", num1, result);
        save_to_history('T', num1, 0, result);
    }
    continue;
}

        // Validates Operator
        while (operator!= '+' && operator!= '-' 
                && operator!= '*' && operator!= '/' 
                && operator!= '%' && operator!= '^' 
                && operator!= 'q' && operator!= 's' 
                && operator!='c' && operator!='h'
                && operator!='e' && operator!='l'
                && operator!='$' && operator!='('
                && operator!=')' && operator!='!'
                && operator!='v' && operator!='S' 
                && operator!='C' && operator!='T'){
            printf("Invalid operator! Please enter a valid operator (+, -, *, /, %%, ^) or 'q' to quit: ");
            scanf(" %c", &operator);
            if (operator== 'q')
            {
                clear_screen(); // Clear the screen before exiting
                exit(0);        // Exit the program successfully
            }
        }

        // Validates Operands
        while (1)
        {
            printf("Enter two operands: ");
            if (scanf("%lf %lf", &num1, &num2) != 2)
            {
                printf("Invalid input! Please enter two valid numbers.\n");
                while (getchar() != '\n')
                    ; // Clears input buffer
            }
            else
            {
                break; // Exit loop if valid numbers are entered
            }
        }

        // Perform calculation based on the operator
        switch (operator)
        {
        case '+':
            result = add(num1, num2);
            save_to_history('+', num1, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            save_to_history('-', num1, num2, result);
            break;
        case '*':
            result = multiply(num1, num2);
            save_to_history('*', num1, num2, result);
            break;
        case '/':
            result = divide(num1, num2);
            save_to_history('/', num1, num2, result);
            break;

        case '%':
            result = modulus((int)num1, (int)num2);
            save_to_history('%', num1, num2, result);
            break;
        case '^':
            result = power(num1, num2);
            save_to_history('^', num1, num2, result);
            break;
        }

        // Output results
        printf("Result: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
    }

    return 0;
}