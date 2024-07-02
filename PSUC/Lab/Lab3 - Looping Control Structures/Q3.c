/*
do the following with the help of iterative (looping) control structures such as while and do-while statements
Check if the sum of the cubes of all digits of an inputted number equals the number itself
*/

#include <stdio.h>
#include <math.h>


int main(){
   
   int digit, sum, RealNumber, DynamicNumber, Temp;

   printf("Enter Number You Wish to Check cubes with: ");
   scanf("%d", &RealNumber);

   DynamicNumber = RealNumber;

   while(DynamicNumber != 0){
      Temp = DynamicNumber % 10;
      DynamicNumber = DynamicNumber / 10;
      sum = sum + pow(Temp, 3);
   }

   if(sum == RealNumber){
      printf("It is an Armstrong Number");
   }
   else{
      printf("It is not a Armstrong Number");
   }

   return 0;

}

