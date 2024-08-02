#include <stdio.h>

int main() {

   int n;

   printf("Enter the number of elements: ");
   scanf("%d", &n);
   int a[n];

   printf("Enter %d elements:\n", n);
   for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }

   // Reverse the array
   for(int i = 0, j = n - 1; i < n / 2; i++, j--) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
   }

   printf("\nReversed array:\n");
   for(int i = 0; i < n; i++) {
      printf("%d\t", a[i]);
   }
   printf("\n");

   return 0;

}
