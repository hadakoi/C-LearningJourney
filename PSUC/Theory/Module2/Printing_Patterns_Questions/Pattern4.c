/*
Using For Loops print the pattern ->

   *  
  **
 ***
****

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main(){

   int i, j, spaces;
   int n;

   printf("Enter Number of lines to print the *: ");
   scanf("%d", &n);

   for (i = 1; i <= n; i++) {  // Loop to iterate over each row

      for (int spaces = 1; spaces <= n - i; spaces++) {  // Loop to print spaces
         printf(" ");
      }
      for (j = 1; j <= i; j++) {  // Loop to print stars
         printf("*");
      }

      printf("\n");  // Move to the next line after printing stars in the current row
    }

    return 0;

}


   









