#include <stdio.h>  // Included standard library for input and output functions
#include <stdlib.h> // Include stdlib.h for exit() function
#include <math.h>   // Include math.h for power function

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

void display_menu()
{
    printf("Calculator Program:\n");
    printf("-----------------------\n");
    printf("Select an operation from the list below:\n");
    printf("+: Addition \n");
    printf("-: Subtraction \n");
    printf("*: Multiplication \n");
    printf("/: Division \n");
    printf("%%: Modulus \n");
    printf("^: Power \n");
    printf("q: Quit \n");
    printf("-----------------------\n");
}
int main()
{
    while (1)
    {
        display_menu();

        // Ask User for input
        printf("Enter an operator from the menu above: ");
        scanf(" %c", &operator);

        // Exit if the user wants to quit
        if (operator== 'q')
        {
            clear_screen(); // Clear the screen before exiting
            exit(0);        // Exit the program successfully
        }

        // Validates Operator
        while (operator!= '+' && operator!= '-' && operator!= '*' && operator!= '/' && operator!= '%' && operator!= '^')
        {
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
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            while (1) //loop until valid input is given
            {
            
            
            
            if (num2 != 0)
            {
                result = num1 / num2;
                    break; //Exits loop if valid
            }
            else
            {
                printf("Error! Division by zero is not allowed.\n");
                printf("Enter a non-zero denominator: ");
                if (scanf("%lf", &num2) != 1){
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clears input buffer

                }
              }
            }
            break;

        case '%':
            while(1) //loop until valid input is given
            {
                if ((int)num2 != 0)
            {
                result = (int)num1 % (int)num2;
                break; //Exits loop if valid
            }
            else
            {
                printf("Error! Division by zero.\n");
                printf("Enter a non-zero denominator: ");
                if (scanf("%lf", &num2) != 1){
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n'); // Clears input buffer
                    }
                }
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