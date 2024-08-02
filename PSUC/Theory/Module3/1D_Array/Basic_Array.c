#include <stdio.h>

int main() {

   int n; 
    
   printf("Enter value of n: "); // prompt user for number of elements
   scanf("%d", &n); // read the value of n
   int arr[n]; // declaration of array arr containing n elements
    
   printf("Enter %d elements:\n", n);
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]); // reading n elements into the array
   }
    
   printf("You entered:\n");
   for(int j = 0; j < n; j++) {
      printf("%d\t", arr[j]); // displaying n elements
   }
    
   return 0;

}

/*
Easy way to calculate Number of Elements in a 1D array->

Calculate the total size of the array
size_t totalSize = sizeof(arr);

Calculate the size of one element
size_t elementSize = sizeof(arr[0]);

Calculate the number of elements
size_t numElements = totalSize / elementSize;

*/
