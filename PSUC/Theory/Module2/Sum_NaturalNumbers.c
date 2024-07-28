#include <stdio.h>

int main() {

   int counter = 1;
   int sum = 0; 

   // Do-while loop to sum numbers from 1 to 99
   do {
        sum = sum + counter; // Add the current counter value to sum
        counter = counter + 1; // Increment the counter
   } while (counter < 100); // Loop condition

   printf("%d\n", sum);

   return 0;

}
