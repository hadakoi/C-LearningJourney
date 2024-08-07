#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {

   // Base case: factorial of 0 or 1 is 1
   if (n == 0 || n == 1) {
        return 1;
   } 
   else {
      // Recursive case: n * factorial of (n - 1)
      return n * factorial(n - 1);
   }

}

int main() {

   int number;
    
   // Prompt the user to enter a number
   printf("Enter a positive integer: ");
   scanf("%d", &number);

   // Check for invalid input
   if (number < 0) {
      printf("Factorial of a negative number is not defined.\n");
   } 
   else {
      // Calculate and display the factorial
      printf("Factorial of %d is %d.\n", number, factorial(number));
   }

   return 0;

}
