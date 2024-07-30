/*
Using For Loops print the pattern ->

   *
  * *
 * * *
* * * *

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main() {

   int n, i, j, spaces;

   printf("Enter number of lines: ");
   scanf("%d", &n);

   for (i = 1; i <= n; i++) {
      for (spaces = 1; spaces <= n - i; spaces++) {
         printf(" ");
      }
      for (j = 1; j <= i; j++) {
         printf("* ");
      }
      printf("\n");
   }

   return 0;

}
