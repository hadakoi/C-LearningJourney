#include <stdio.h>

int main() {

   int n, pos, i;

   printf("Enter the number of elements: ");
   scanf("%d", &n);

   int a[n];

   printf("Enter %d numbers:\n", n);
   for(i = 0; i < n; i++) {
      scanf("%d", &a[i]);
   }

   printf("Enter the position at which the element to be deleted: ");
   scanf("%d", &pos);

  
    if(pos < 1 || pos > n) {
      printf("Invalid position!\n");
      return 1;
   }

   // Shift elements to the left
   for(i = pos - 1; i < n - 1; i++) {
      a[i] = a[i + 1];
   }

   //Decrease the number of elements
   n = n - 1;

   printf("Array after deletion:\n");
   for(i = 0; i < n; i++) {
      printf("%d ", a[i]);
   }
   printf("\n");

   return 0;

}


/*

Array: [1, 2, 3, 4, 5]
Index:  0  1  2  3  4

index 2 to be deleted

hence i = pos - 1 position entered will be the 3rd element of array by user which is 3 
a[2] = a[3] // [1, 2, 3, 4, 5] -> [1, 2, 4, 4, 5] 
a[3] = a[4] // [1, 2, 4, 4, 5] -> [1, 2, 4, 5, 5] 

The last element is now a duplicate (5) because the array size hasn't been updated yet.
n = n - 1;

Finally
Array: [1, 2, 4, 5]
Index:  0  1  2  3

*/