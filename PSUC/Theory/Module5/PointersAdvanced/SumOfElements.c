#include <stdio.h>

int main() {
   // Declare a pointer to an integer, a variable to store the sum, and an index variable
   int *p, sum = 0, i = 0;

   // Initialize an array with 5 elements
   int x[5] = {5, 9, 6, 3, 7};

   // Initialize the pointer to point to the first element of the array
   p = x;

   // Loop through each element of the array using a pointer
   while (i < 5) {
      // Add the value at the current pointer location to the sum
      sum += *p;

      // Increment the index and move the pointer to the next element
      i++;
      p++;
    }


   printf("Sum of elements = %d\n", sum);

   return 0;
   
}
