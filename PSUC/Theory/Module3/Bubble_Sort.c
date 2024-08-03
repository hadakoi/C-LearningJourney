#include <stdio.h>

int main() {
    int n, i, j, temp;
    
   // Input the number of elements in the array
   printf("Enter the number of elements: ");
   scanf("%d", &n);
    
   int array[n];
    
 
   printf("Enter %d elements:\n", n);
   for(i = 0; i < n; i++) {
      scanf("%d", &array[i]);
   }
    
   // Bubble sort in ascending order
   for(i = 0; i < n-1; i++) {
      for(j = 0; j < n-i-1; j++) {
         if(array[j] > array[j+1]) {
            // Swap the elements
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
         }
      }
   }
    
   // Print the array sorted in ascending order
   printf("Array sorted in ascending order:\n");
   for(i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
    
   // Bubble sort in descending order
   for(i = 0; i < n-1; i++) {
      for(j = 0; j < n-i-1; j++) {
         if(array[j] < array[j+1]) {
            // Swap the elements
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
         }
      }
   }
    
   // Print the array sorted in descending order
   printf("Array sorted in descending order:\n");
   for(i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
    
   return 0;

}
