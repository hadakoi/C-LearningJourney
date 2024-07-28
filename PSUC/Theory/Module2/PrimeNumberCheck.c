#include <stdio.h>

int main() {
    int N, j, prime = 1; // Variable declarations and initialization


    printf("Enter a number: ");
    scanf("%d", &N);

    // Check for edge cases (0 and 1 are not prime numbers)
   if (N <= 1) {
      prime = 0;
   }
   else {
      // goes through list of numbers less than N from the number 2 for any factors. 
      for (j = 2; j < N; j++) {
         if ((N % j) == 0) {
            prime = 0; // Found a factor, set prime to 0
            break; // Break out of the loop
         }
      }
   }

   // Check the prime flag and print the result
   if (prime == 1) {
      printf("%d is a prime number\n", N);
   }

   else {
      printf("%d is not a prime number\n", N);
   }

   return 0;

}
