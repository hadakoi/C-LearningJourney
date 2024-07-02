/*
do the following with the help of iterative (looping) control structures
Evaluate the sine series to n terms
*/

#include <stdio.h>

int main() {
   
   int n;
   float x, term, sum = 0.0;
   int sign = 1;

   printf("Enter the value of x (in radians): ");
   scanf("%lf", &x);
   printf("Enter the number of terms: ");
   scanf("%d", &n);

   for (int i = 0; i < n; ++i) {
      term = 1.0;
      int power = 2 * i + 1;
        
      // Calculate x^power
      for (int j = 0; j < power; ++j) {
         term = term * x;
      }
        
      // Calculate power
      for (int j = 1; j <= power; ++j) {
         term /= j;
      }
        
      term = term * sign;
      sum = sum + term;
      sign = sign * -1; // Alternate the sign
   }

   printf("sin(%lf) = %lf\n", x, sum);

   return 0;
   
}
