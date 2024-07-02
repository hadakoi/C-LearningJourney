/*
do the following with the help of iterative (looping) control structures
Check whether a given number is perfect or not.
*/

#include <stdio.h>

int main() {

   int number, sum = 0;

   printf("Enter a number: ");
   scanf("%d", &number);

   // Calculate the sum of divisors
   for (int i = 1; i < number ; ++i) {
      if (number % i == 0) {
        sum += i;
      }
   }

   // Check if the number is perfect
   if (sum == number && number != 0) {
      printf("%d is a perfect number.\n", number);
   } 
   else {
      printf("%d is not a perfect number.\n", number);
   }

   return 0;

}
