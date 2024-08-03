#include <stdio.h>

int main() {

   int n, i;
   printf("Enter Number of digits in the Array You want to Sort: ");
   scanf("%d", &n);
   int arr[n];

   printf("Enter %d elements:\n", n);
   for(i = 0; i < n ; i++){
      scanf("%d", &arr[i]);
   }
    
   // Selection sort in ascending order
   for (int i = 0; i < n - 1; i++) {
      int min_idx = i;  // Assume the current element is the minimum
      for (int j = i + 1; j < n; j++) {
         // Find the index of the smallest element in the remaining array
         if (arr[j] < arr[min_idx]) {
            min_idx = j;
         }
      }
      // Swap the found minimum element with the first element of the unsorted part
      int temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
   }

   // Print the sorted array in ascending order
   printf("Sorted array in ascending order: \n");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   // Selection sort in descending order
   for (int i = 0; i < n - 1; i++) {
      int max_idx = i;  // Assume the current element is the maximum
      for (int j = i + 1; j < n; j++) {
         // Find the index of the largest element in the remaining array
         if (arr[j] > arr[max_idx]) {
            max_idx = j;
         }
      }
      // Swap the found maximum element with the first element of the unsorted part
      int temp = arr[max_idx];
      arr[max_idx] = arr[i];
      arr[i] = temp;
   }

   // Print the sorted array in descending order
   printf("Sorted array in descending order: \n");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

    return 0;
    
}

