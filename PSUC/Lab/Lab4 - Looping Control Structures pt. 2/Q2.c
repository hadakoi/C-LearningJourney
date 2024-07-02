/*
do the following with the help of iterative (looping) control structures
Generate Floyd’s triangle using natural numbers for a given limit N.
*/

#include <stdio.h>

int main() {

   int N, number = 1;

   printf("Enter the limit for Floyd's triangle: ");
   scanf("%d", &N);

   for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= i; j++) {
         printf("%d ", number);
         number++;
      }
      printf("\n"); // Prints the next set of numbers on a new line after it finishes the inner loop
    }

    return 0;
    
}
