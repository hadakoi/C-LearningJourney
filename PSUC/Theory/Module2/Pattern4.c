/*
Using For Loops print the pattern ->

   *   j = 1 i = 1 spaces = 3
  **   j = 2 i = 2 spaces = 2
 ***   j = 3 i = 3 spaces = 1
****   j = 4 i = 4 spaces = 0

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main(){

   int i, j, spaces;
   int n;

   printf("Enter Number of lines to print the *: ");
   scanf("%d", &n);

   for (i = 1; i <= n; i++) {

      for (spaces = 1; spaces <= n - i; spaces++) {
         printf(" ");
        }
       
      for (j = 1; j <= i; j++) {
         printf("*");
      }
      
      printf("\n");
   }

   return 0;

}

   









