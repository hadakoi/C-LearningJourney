#include <stdio.h>

int main() {

   int number;
   int sum = 0; 
   
    // Do-while loop to add numbers until the user enters zero
   do {
      // Prompt the user to enter a number
      printf("Enter a number (enter zero to exit and display sum):\n");
      // Read the user input
      scanf("%d", &number);
      // Add the entered number to sum
      sum += number;
   } while (number != 0); 

   printf("The sum is %d\n", sum);

   return 0;

}
