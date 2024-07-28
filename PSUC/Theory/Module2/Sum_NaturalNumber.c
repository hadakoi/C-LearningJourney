#include <stdio.h>

int main() {
   
   int n;
   int sum = 0; // Initialize sum to 0

   // For loop to sum numbers from 1 to 99 would do it from 1 to 100 if n <= 100
   for (n = 1; n < 100; n++) {
      sum = sum + n; // Add the current number to sum
   }

   printf("%d\n", sum);

   return 0;

}
