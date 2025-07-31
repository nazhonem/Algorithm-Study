// A simple C program to calculate factorial of a number using recursion
#include <stdio.h>

int factorial(int n);

int main(void)
{
    // Get user input (number)
    int num;
    printf("Enter a number ");
    scanf("%d", &num);
    
    // Calculate factorial using recursion
    printf("Factorial of %d is %d", num, factorial(num));
}

int factorial(int n)
{
    if (n == 0)
        return 1;   // base case
    else
        return n * factorial(n - 1);   // recursive case
}