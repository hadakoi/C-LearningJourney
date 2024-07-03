/*
With the knowledge of 1D arrays
Find the largest and smallest element in a 1D array.
*/

#include <stdio.h>

int main(){
   
   int n, x;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter the elements of the array:\n");

   for(x=0; x<n ;x++){
      printf("Enter Element %d: ", x+1);
      scanf("%d", &arr[x]);
   }

   int largest, smallest;

   largest = arr[0];
   smallest = arr[0];

   for(x=1; x<n ;x++){
      if (arr[x] > largest) {
            largest = arr[x];
        }
        if (arr[x] < smallest) {
            smallest = arr[x];
        }
   }

   printf("Largest element: %d\n", largest);
   printf("Smallest element: %d\n", smallest);

   return 0;

}