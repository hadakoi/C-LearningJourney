/*
Using For Loops print the pattern ->

*****  
****           
***             
**              
*               

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main() {

   int i, j, n;

   printf("Enter Number of lines to print the *: ");
   scanf("%d", &n);

   for (i = 1; i <= n; i++) {  // Loop to iterate over each row
        for (j = n; j >= i; j--) {  // Loop to print the stars in each row
         printf("*");
      }
      printf("\n");
   }

   return 0;
}
