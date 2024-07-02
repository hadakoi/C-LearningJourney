/*
do the following with the help of iterative (looping) control structures
Generate prime numbers between 2 given limits.
*/

#include <stdio.h>

int main(){
   int L1, L2, Is_Prime; 
   int x, y;

   printf("Enter Ranges 1 and 2: ");
   scanf("%d %d", &L1, &L2);

   for(x=L1; x <= L2 ; x++){ // goes through all numbers or test numbers within these ranges to be checked if they are prime

      Is_Prime = 1; // setting the flag to true.

      for(y=2; y <= x-1 ; y++){ // this allows us to have all possible divisors lower than the test number to use the mod % operator with (If Any divisible its not prime)

         if(x % y == 0){
            //Its Divisible Hence not a Prime Number
            Is_Prime = 0;
            break;
         }
      }

      if(Is_Prime == 1){
         printf("%d is a Prime Number \n", y);
      }
   }

   return 0;
   
}

