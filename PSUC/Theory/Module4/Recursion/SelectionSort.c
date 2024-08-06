#include <stdio.h>

// Function prototype
void selectionSort(int arr[], int n, int index);

int main() {

   int arr[100];
   int n, i;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   printf("Enter the elements:\n");
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   selectionSort(arr, n, 0);

   printf("Sorted array:\n");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   return 0;

}


void selectionSort(int arr[], int n, int index) {

   if (index >= n - 1) {
      return;  // Base case: If the index is beyond the second last element
   }

   // Find the index of the minimum element in the unsorted part of the array
   int minIndex = index;
   for (int i = index + 1; i < n; i++) {
      if (arr[i] < arr[minIndex]) {
         minIndex = i;
      }
   }

    // Swap the found minimum element with the element at the current index
    if (minIndex != index) {
      int temp = arr[index];
      arr[index] = arr[minIndex];
      arr[minIndex] = temp;
   }

   // Recursively sort the remaining part of the array
   selectionSort(arr, n, index + 1);

}