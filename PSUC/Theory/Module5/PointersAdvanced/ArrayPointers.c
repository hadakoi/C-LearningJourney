#include <stdio.h>

int main() {

   int numbers[] = {10, 20, 30, 40, 50};
   int i = 0;
   // Initialize pointer 'p' to point to the first element of the 'numbers' array
   int *p = numbers;

   // Print the values in the array using pointer arithmetic
   for (i = 0; i < 5; i++) {
      // Access and print the i-th element of the array using pointer arithmetic
      printf("%d ", *(p + i));

   }

   printf("\n");

   return 0;

}
