#include <stdio.h>

int main() {

   int arr1[50], arr2[50], sum[50], n;
   printf("Enter the number of elements: ");
   scanf("%d", &n);
    
   printf("Enter elements of the first array:\n");
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr1[i]);
   }
    
   // Input elements for the second array
   printf("Enter elements of the second array:\n");
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr2[i]);
   }
    
   // Adding corresponding elements and storing in the sum array
   for(int i = 0; i < n; i++) {
      sum[i] = arr1[i] + arr2[i];
   }
    
   // Displaying the sum array
   printf("Resultant array (sum of corresponding elements):\n");
   for(int i = 0; i < n; i++) {
      printf("%d\t", sum[i]);
   }
    
   return 0;

}
