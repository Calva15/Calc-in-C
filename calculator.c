#include <stdio.h>

    char operator;
    double num1, num2, result;

int main()
 {
// Ask User for input
printf("Enter an operaator (+, -, *, /): ");
scanf(" %c", &operator);

// Validates Operator
        while (1)
        {
          if (operator == '+' || operator == '-' ||
                operator == '*' || operator == '/'){
                    break;    
            }  
                else {
                    printf("Invalid operator! Please enter a valid operator! (+, -, *, /): ");
                    scanf(" %c", &operator); //Re-prompt until valid input is received

                }

        }
        // Validates Operrands
    while (1)
    {
     
printf("Enter two operands: ");
if (scanf("%lf %lf", &num1, &num2) != 2) {
    printf("Invalid input! Please enter two valid numbers. \n");
        while(getchar() != '\n'); //clears input buffer
    }
        else {
            break; //Exit loop if valid numbers are entered
        }



    }

//perform the operation based on the operator
switch (operator){
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
        if (num2 !=0)
     result = num1 / num2;
            else{
                    printf("Error! Division by zero .\n");
                        return 1; // Exitsif Division is by Zero

            }
        break;
    default:
        printf("Error! Operator is not correct. \n");
                return 1; //Exits if operator is invalid



}

//Output results
    printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);


  return 0;
}