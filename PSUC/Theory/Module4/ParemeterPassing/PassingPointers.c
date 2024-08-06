#include <stdio.h>

// Function to swap values of two integers using pointers
void swap(int *x, int *y) {
   int t = *x; // Temporary variable to hold the value of *x
   *x = *y;   // Assign value of *y to *x
   *y = t;    // Assign the temporary value to *y
}

int main() {

   int a = 5, b = 7;

   printf("Before swap: a=%d and b=%d\n", a, b);
    
   // Call swap function
   swap(&a, &b);
    
   // Print values after swap
   printf("After swap: a=%d and b=%d\n", a, b);
    
   return 0;
}
