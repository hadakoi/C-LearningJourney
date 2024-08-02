#include <stdio.h>

int main() {

   int n;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   int array[n];

   printf("Enter %d elements:\n", n);
   for(int i = 0; i < n; i++) {
      scanf("%d", &array[i]);
   }

   // Print the elements in reverse order
   printf("Array in reverse order:\n");
   for(int i = n - 1; i >= 0; i--) {
      printf("%d ", array[i]);
   }
   printf("\n");

   return 0;

}
