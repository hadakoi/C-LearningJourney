/*
Using For Loops print the pattern ->

1
12
123
1234
12345

and so on depending on number of lines user enters.
*/

#include <stdio.h>

int main(){
   int i, j, n;
   
   printf("Enter Number of lines to print the Pattern: ");
   scanf("%d", &n);

   for(i=1;i<=n;i++){
      for(j=1;j<=i;j++){
         printf("%d", j);
      }
      printf("\n");
   }

   return 0;
   
}