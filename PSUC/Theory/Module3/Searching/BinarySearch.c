#include <stdio.h>

int main() {

   int n, key, low, high, mid;

   printf("Enter the number of elements: ");
   scanf("%d", &n);
   int array[n];
    
   printf("Enter %d sorted elements:\n", n);
   for(int i = 0; i < n; i++) {
      scanf("%d", &array[i]);
   }

   printf("Enter the element to search: ");
   scanf("%d", &key);
    
   // Initialize low and high pointers
   low = 0;
   high = n - 1;
    
   // Binary search procedure
   do {
      mid = (low + high) / 2;
      if (key < array[mid]) {
         high = mid - 1;
      } 
      else if (key > array[mid]) {
         low = mid + 1;
      }
    } while (key != array[mid] && low <= high);
    
   if (key == array[mid]) {
      printf("SUCCESSFUL SEARCH.\nElement found at position %d.\n", mid + 1);
   } 
   else {
      printf("Search element NOT Found.\n");
   }
    
   return 0;
   
}
