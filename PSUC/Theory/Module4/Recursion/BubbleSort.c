#include <stdio.h>

// Function to sort the array using recursive selection sort
void sortR(int list[], int ln) {

   int i, tmp, min;
   if (ln <= 1)
      return; // Base case: array of size 1 is already sorted

   // Find index of the smallest element in the subarray
   min = 0;
   for (i = 1; i < ln; i++) {
      if (list[i] < list[min]) {
         min = i;
      }
   }

   // Move smallest element to the 0-th position
   tmp = list[0];
   list[0] = list[min];
   list[min] = tmp;

   sortR(list + 1, ln - 1);

}



int main() {

   int arr[100];
   int n, i;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   printf("Enter the elements:\n");
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   sortR(arr, n);

   printf("Sorted array: ");
   for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

   return 0;

}
