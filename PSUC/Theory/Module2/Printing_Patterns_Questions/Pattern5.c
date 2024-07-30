/*
Using For Loops print the pattern ->

1
22
333
4444
55555

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main() {

   int n;

   printf("Enter number of lines: ");
   scanf("%d", &n);

   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
         printf("%d", i);
      }
      printf("\n");  // Move to the next line after each row
   }

   return 0;
}
