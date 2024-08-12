#include <stdio.h>

int main() {

   int arr[5] = {31, 54, 77, 52, 93};
   int *ptr;

   // Initialize the pointer to point to the first element of the array
   ptr = arr;
   // Loop through each element of the array
   for(int j = 0; j < 5; j++) {
      // Print the value at the current pointer location
      // `*ptr` dereferences the pointer to get the value
      // `ptr++` moves the pointer to the next element in the array
      printf("%d ", *ptr++);
   }

   printf("\n");

   return 0;

}
