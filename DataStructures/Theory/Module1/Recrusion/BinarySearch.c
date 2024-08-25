#include <stdio.h>

int binary(int item, int a[], int low, int high) {
   int mid;


   if (low > high)
      return -1;

   mid = (low + high) / 2;

   if (item == a[mid])
      return mid;

   // Recursive case: search in the left half
   else if (item < a[mid]) {
      high = mid - 1;
      return binary(item, a, low, high);
   }

   // Recursive case: search in the right half
   else {
      low = mid + 1;
      return binary(item, a, low, high);
   }
}

int main() {
   int n, i, item, result;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   int arr[n];

   printf("Enter %d sorted elements:\n", n);
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   printf("Enter the element to search for: ");
   scanf("%d", &item);

   result = binary(item, arr, 0, n - 1);


   if (result != -1)
      printf("Element %d found at index %d.\n", item, result);
   else
      printf("Element %d not found in the array.\n", item);

   return 0;
}
