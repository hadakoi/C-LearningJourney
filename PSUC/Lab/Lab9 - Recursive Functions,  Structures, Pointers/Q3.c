/*
With the knowledge of recursive functions, Structures and pointers
Find the maximum number in the input integer array using pointers.
*/

#include <stdio.h>

int main() {

   int n;
   
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n];

   printf("Enter the elements of the array: ");
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

    // Initialize pointers
   int *ptr = arr;
   int *endPtr = arr + n;
   int max = *ptr; // Assume the first element is the maximum

   // Traverse the array using pointers to find the maximum value
   for (int *currentPtr = ptr; currentPtr < endPtr; currentPtr++) {
      if (*currentPtr > max) {
         max = *currentPtr;
      }
   }

   printf("The maximum number in the array is: %d\n", max);

   return 0;

}
