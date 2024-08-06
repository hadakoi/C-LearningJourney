#include <stdio.h>

// Function to compute the sum of array elements
int fnSum(int a[], int n) { // passing the array to a function by using a[]  
    int sum = 0, i;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int main() {

   int n, a[20], i;
    
   printf("Enter the limit \n");
   scanf("%d", &n);

   printf("Enter the values: \n");
   for (i = 0; i < n; i++){
      scanf("%d", &a[i]);
   }
    
   // Output the sum of the array elements
   printf("The sum of array elements is = %d\n", fnSum(a, n)); // when passing the array in the function pass the array name
    
   return 0;

}
