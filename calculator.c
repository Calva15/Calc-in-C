#include <stdio.h>

    char operator;
    double num1, num2, result;

int main()
 {
// Ask User for input
printf("Enter an operaator (+, -, *, /): ");
scanf(" %c", &operator);
printf("Enter two operands: ");
scanf("%lf %lf", &num1, &num2);

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
                        return 1;

            }
        break;
    default:
        printf("Error! Operator is not correct. \n");




}

//Output results
    printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);


  return 0;
}