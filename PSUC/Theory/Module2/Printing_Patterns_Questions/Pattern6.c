/*
Using For Loops print the pattern ->

1
2 3
4 5 6
7 8 9 10


and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main() {

   int n, number = 1;
   printf("Enter number of lines: ");
   scanf("%d", &n);

   // Outer loop for each row
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
         printf("%d ", number);
         number++;  
      }
      printf("\n");  // Move to the next line after each row
   }

   return 0;

}
