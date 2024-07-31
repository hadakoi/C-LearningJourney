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
