/*
Using For Loops print the pattern ->

Taking i as line and j as amount of *
*       Logic -> i = 1, j = 1
**               i = 2, j = 2 
***              i = 3, j = 3
****             i = 4, j = 4
*****            i = 5, j = 5

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main(){
   int i, j, n;

   printf("Enter Number of lines to print the *: ");
   scanf("%d", &n);
 
   for(i=1;i<=n;i++){
      for(j=1;j<=i;j++){ // depending on which line it is it sets the number of stars to print say i = 2 then it will run through j loop twice as its on the second line.
         printf("*");
      }
   printf("\n");
   }

   return 0;
}





