#include "operations.h"
#include <math.h> //for scientific function
#include <stdio.h> //for fprintf function

// Function to add two numbers

double add(double x, double y)
{
    return x + y;
}
// Function to subtract two numbers

double subtract(double x, double y)
{
    return x - y;
}
// Function to multiply two numbers

double multiply(double x, double y)
{
    return x * y;
}

// Function to divide two numbers

double divide(double x, double y)
{
if (y==0){
    fprintf(stderr, "Error: Division by zero\n");
        return 0;
}
    return x / y;
}

// Function to find the modulus of two numbers

int modulus(int x, int y)
{
    if (y == 0)
    {
    fprintf(stderr, "Error: Modulus by zero\n");
        return 0;
    }
    
    return x % y;
}

// Function to find the power of a number

double power(double x, double y)
{
    return pow(x, y);
}

// Function to find the square root of a number

double square_root(double x)
{
    if(x < 0){
        fprintf(stderr, "Error: Square root of a negative number\n");
        return -1;
    }
    return sqrt(x);
}

//Function to for log

double natural_log(double x)
{
    if(x <= 0){
        fprintf(stderr, "Error: Natural logarithm is undefined for non-positive numbers.\n");
        return -1; //returns error value
    }
    return log(x); //returns ln(num)
}

//For log base 10

double base10_log(double x)
{
    if(x <= 0){
        printf("Error: Base-10 logarithm is undefined for non-positive numbers.\n");
        return -1; // Return an error value
    }
    return log10(x); //returns log10(num)
}

// Functions to find Trigonometric functions

double sine(double angle)
{
    return sin(angle); //returns sin(angle)
}

double cosine(double angle)
{
    return cos(angle); //returns cos(angle)
}

double tangent(double angle)
{
    return tan(angle); //returns tan(angle)
}
