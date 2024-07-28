#include <stdio.h>

int main() {

   int m, n;

   printf("Enter the range (m and n): ");
   scanf("%d %d", &m, &n);

   // Loop through each number from m to n
   for (int i = m; i <= n; i++) {
      int prime = 1; // Assume the current number is prime which is held in the variable i
      for (int j = 2; j < i; j++) { // goes through list of numbers less than i from the number 2 for any factors. 
         if (i % j == 0) {
            prime = 0; // Found a factor, set prime to 0
            break; // Break out of inner loop
         }
      }
      // Print the number if it is prime
      if (prime == 1 && i > 1) {
         printf("%d\t", i);
      }
   }

   return 0; 

}
