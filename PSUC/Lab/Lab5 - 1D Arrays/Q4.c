/*
With the knowledge of 1D arrays
Search the position of the number that is entered by the user and delete that particular number from the array and display the resultant array elements.
*/

#include <stdio.h>

int main() {

   int n, i, j, element, pos = -1;

   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n];

   printf("Enter the elements of the array:\n");
   for (i = 0; i < n; i++) {
      printf("Element %d: ", i + 1);
      scanf("%d", &arr[i]);
   }

   printf("Enter the element to be deleted: ");
   scanf("%d", &element);

   // Search for the element
   for (i = 0; i < n; i++) {
      if (arr[i] == element) {
         pos = i;
         break;
      }
   }

   // Check if the element was found
   if (pos == -1) {
      printf("Element not found in the array.\n");
   } else {
      // Shift elements to delete the element
      for (i = pos; i < n - 1; i++) {
         arr[i] = arr[i + 1];
      }

      // Update the number of elements
      n--;

      printf("Array after deletion:\n");
      for (i = 0; i < n; i++) {
         printf("%d ", arr[i]);
      }
      printf("\n");
   }

    return 0;

}