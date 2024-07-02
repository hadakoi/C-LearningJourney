/*
do the following with the help of iterative (looping) control structures
Write a program using do-while loop to read the numbers until -1 is encountered. Also count the number of prime numbers and composite numbers entered by user.
*/

#include <stdio.h>

int main(){

  int number, primeCount = 0, compositeCount = 0;

  do {
    printf("Enter a number (-1 to end): ");
    scanf("%d", &number);

    if (number == -1) {
      break;
   }

    if (number <= 1) {
      // Numbers less than or equal to 1 are neither prime nor composite hence we skip this iteration
      continue; 
    }

   int isPrime = 1; // Assume the number is prime

   // Check if the number is prime
   for (int i = 2; i <= number / 2; ++i) {
      if (number % i == 0) {
         isPrime = 0; // Not a prime number
         break;
      }
    }

    if (isPrime == 1) {
         primeCount++;
    } 
    else {
         compositeCount++;
    }

    } while (number != -1);

   printf("Prime numbers: %d\n", primeCount);
   printf("Composite numbers: %d\n", compositeCount);

   return 0;

}