// A simple C program to find the Fibonacci series using recursion
#include <stdio.h>

int fibonacci(int n);

int main (void)
{
    // Get user input (number)
    int num;
    printf("Enter a number ");
    scanf("%d", &num);
    
    // Calculate Fibonacci number using recursion
    printf("Fibonacci of %d is %d", num, fibonacci(num));
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;       // base case
    else if (n == 1)
        return 1;       // base case
    else
        return fibonacci(n - 1) + fibonacci(n - 2);   // recursive case
}