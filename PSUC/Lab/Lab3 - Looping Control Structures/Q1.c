/*
do the following with the help of iterative (looping) control structures
Reverse a given number and check if it is a palindrome or not.
*/

#include <stdio.h>

int main(){

   int Number, Reversed, DynamicNumber, Temp;

   printf("Enter Number you Wish to Reverse: ");
   scanf("%d", &Number);

   DynamicNumber = Number;

   while(DynamicNumber != 0){
      Temp = DynamicNumber % 10;
      DynamicNumber = DynamicNumber / 10;
      Reversed = Reversed*10 + Temp;
   }

   printf("The Reversed Number is %d \n", Reversed);

   if(Reversed = Number){
    printf("%d is a palindrome", Number);
   }
   else{
      printf("Not a Palindrome");
   }

   return 0;

}