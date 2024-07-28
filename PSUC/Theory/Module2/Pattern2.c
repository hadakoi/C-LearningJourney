/*
Using For Loops print the pattern ->

Taking i as line and j as amount of *

*****  Logic -> i = 1, j = 5
****            i = 2, j = 1
***             i = 3, j = 2 
**              i = 4, j = 3
*               i = 5, j = 4

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main(){
   int i, j, n;
   
   printf("Enter Number of lines to print the *: ");
   scanf("%d", &n);

   for(i=1;i<=n;i++){
      for(j=n;j>=i;j--){
         printf("*");
      }
      printf("\n");
   }

   return 0;
   
}