#include <stdio.h>

// Function to calculate the sum and product of two integers
// Uses pointers to return multiple values
void calculate(int a, int b, int *sum, int *product) {
  *sum = a + b;       // Calculate sum and store at the address pointed by sum
  *product = a * b;   // Calculate product and store at the address pointed by product
}

int main() {
  int num1 = 4, num2 = 5;  // Initialize two numbers
  int sum, product;        // Variables to store the results
    
  // Call calculate with the numbers and addresses of sum and product
  calculate(num1, num2, &sum, &product);
    
  // The sum and product have been modified in main() by calculate()
  printf("Sum = %d, Product = %d", sum, product);  // Output will be Sum = 9, Product = 20
  return 0;
}
