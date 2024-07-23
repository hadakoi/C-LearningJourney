/*
With the knowledge of modularization, function definition, function call etc.,
Write a function Fact to find the factorial of a given number. Using this function, compute NCR in the main function.
*/

#include <stdio.h>

// Function to calculate factorial of a number
int fact(int n) {
   int factorial = 1;
   for (int i = 1; i <= n; i++) {
   factorial *= i;
   }
   return factorial;
}

// Function to calculate nCr
int ncr(int n, int r) {
   int numerator = fact(n);
   int denominator = fact(r) * fact(n - r);
   return numerator / denominator;
}

int main() {
   
   int n, r;
    
   printf("Enter n: ");
   scanf("%d", &n);
    
   printf("Enter r: ");
   scanf("%d", &r);
    
   if (r > n) {
      printf("r cannot be greater than n\n");
      return 1;
   }

   printf("%dC%d = %d\n", n, r, ncr(n, r));

   return 0;

}
