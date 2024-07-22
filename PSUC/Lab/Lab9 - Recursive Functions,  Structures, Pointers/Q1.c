/*
With the knowledge of recursive functions, Structures and pointers
Write a recursive function, GCD to find the GCD of two numbers. Write a main program which reads 2 numbers and finds the GCD of the numbers using the specified
function.
*/

#include <stdio.h>

// Function prototype
int GCD(int a, int b);

int main() {

   int num1, num2;
   printf("Enter the first number: ");
   scanf("%d", &num1);
   printf("Enter the second number: ");
   scanf("%d", &num2);

   // Calculate the GCD
   int result = GCD(num1, num2);

   // Print the result
   printf("The GCD of %d and %d is: %d\n", num1, num2, result);

   return 0;

}

// Recursive function to find the GCD of two numbers
int GCD(int a, int b) {

   // Base case: If b is 0, return a (the GCD of a and 0 is a)
   if (b == 0) {
      return a;
   }
   // Recursive case: Call GCD with b and a % b
   // This reduces the problem size and eventually reaches the base case
   return GCD(b, a % b);

}
