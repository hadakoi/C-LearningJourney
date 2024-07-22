/*
With the knowledge of recursive functions, Structures and pointers
Write a recursive function FIB to generate nth Fibonacci term. Write a main program to print first N Fibonacci terms using function FIB.
*/

#include <stdio.h>

// Function prototype for the Fibonacci function
int FIB(int n);

int main() {

   int N;
    
   printf("Enter the number of Fibonacci terms to print: ");
   scanf("%d", &N);

   // Print the first N Fibonacci terms
   printf("The first %d Fibonacci terms are:\n", N);
   for (int i = 0; i < N; i++) {
      printf("%d ", FIB(i));
   }
   printf("\n");

   return 0;

}

// Recursive function to generate the nth Fibonacci term
int FIB(int n) {

   // Base case: If n is 0, return 0 (the first term in the Fibonacci sequence)
   if (n == 0) {
      return 0;
   }
   // Base case: If n is 1, return 1 (the second term in the Fibonacci sequence)
   if (n == 1) {
      return 1;
   }
   // Recursive case: Return the sum of the two preceding terms
   // FIB(n - 1) gives the (n-1)th term
   // FIB(n - 2) gives the (n-2)th term
   return FIB(n - 1) + FIB(n - 2);

}