#include <stdio.h>

int main() {

   int n, rev = 0, rd; 

   printf("Enter your number:\n");
   scanf("%d", &n);

   // Loop to reverse the digits of the number
   while (n != 0) {
      rd = n % 10;   // Get the last digit
      rev = rev * 10 + rd; // Append the digit to the reversed number
      n = n / 10; // Remove the last digit
   }
   
   printf("The reversed number is %d\n", rev);

   return 0;

}
