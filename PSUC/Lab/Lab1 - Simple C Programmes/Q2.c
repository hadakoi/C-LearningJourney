/*
Write a C program to find the sum, difference, product and quotient of 2 numbers.
*/

#include <stdio.h>

int main() {
    int num1, num2;
    int sum, difference, product, quotient;

    // This can be Done to Input two numbers at the Same Time
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Performing arithmetic operations
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    
    // Display the results
    printf("Sum: %d\n", sum); 
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);

    // Using \n signifies a new line for the next printed text

    return 0;
}
