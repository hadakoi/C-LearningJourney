/*
To implement selection sort using recursion
*/

#include <stdio.h>

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
      return;
   }

   int minIndex = index;
   for (int i = index + 1; i < n; i++) {
      if (arr[i] < arr[minIndex]) {
         minIndex = i;
      }
   }

   if (minIndex != index) {
      int temp = arr[index];
      arr[index] = arr[minIndex];
      arr[minIndex] = temp;
   }

   selectionSort(arr, n, index + 1);
}

/*
Call Tree for arr = [64, 25, 12, 22, 11]

selectionSort(arr, 5, 0)
|
|-- minIndex = 4 (value = 11)
|-- Swap arr[0] and arr[4] -> arr = [11, 25, 12, 22, 64]
|-- selectionSort(arr, 5, 1)
    |
    |-- minIndex = 2 (value = 12)
    |-- Swap arr[1] and arr[2] -> arr = [11, 12, 25, 22, 64]
    |-- selectionSort(arr, 5, 2)
        |
        |-- minIndex = 3 (value = 22)
        |-- Swap arr[2] and arr[3] -> arr = [11, 12, 22, 25, 64]
        |-- selectionSort(arr, 5, 3)
            |
            |-- minIndex = 3 (value = 25)
            |-- No swap needed -> arr = [11, 12, 22, 25, 64]
            |-- selectionSort(arr, 5, 4)
                |
                |-- Base case: index = 4 >= n - 1
                |-- Return from recursion
*/