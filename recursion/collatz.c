#include <stdio.h>

int collatz(int n);

int main(void)
{
    // Get user input (positive number)    
    int num;
    do 
    {
        printf("Enter a positive integer: ");
        scanf("%d", &num);
    } while (num <= 0); // Ensure the number is positive

    // Calculate Collatz sequence length using recursion
    printf("Collatz sequence length for %d is %d\n", num, collatz(num));
}

int collatz(int n)
{
    if (n == 1)
		return 0;                       // base case
	else if ((n % 2) == 0)
		return 1 + collatz(n / 2);      // even case
	else
		return 1 + collatz(3 * n + 1);  // odd case
}