#include <stdio.h>
#include "operations.h" // Include your header file

int main() {
    // Test addition
    double sum = add(5.5, 4.5);
    printf("Addition: 5.5 + 4.5 = %.2lf\n", sum);

    // Test subtraction
    double difference = subtract(10.0, 4.0);
    printf("Subtraction: 10.0 - 4.0 = %.2lf\n", difference);

    // Test multiplication
    double product = multiply(3.0, 7.0);
    printf("Multiplication: 3.0 * 7.0 = %.2lf\n", product);

    // Test division
    double quotient = divide(8.0, 2.0);
    printf("Division: 8.0 / 2.0 = %.2lf\n", quotient);

    // Test division by zero
    double division_error = divide(8.0, 0.0);
    printf("Division by Zero: 8.0 / 0.0 = %.2lf\n", division_error);

    // Test modulus
    int mod = modulus(10, 3);
    printf("Modulus: 10 %% 3 = %d\n", mod);

    // Test modulus by zero
    int modulus_error = modulus(10, 0);
    printf("Modulus by Zero: 10 %% 0 = %d\n", modulus_error);

    // Test power
    double power_result = power(2.0, 3.0);
    printf("Power: 2.0 ^ 3.0 = %.2lf\n", power_result);

    return 0;
}
