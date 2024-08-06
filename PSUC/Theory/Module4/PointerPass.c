#include <stdio.h>

// Function to modify the value at the given pointer
int change(int *p) {

   *p = *p + 10; // Increase the value pointed to by p by 10
   return 0; // Return 0 (not used in this example)

}

int main() {

   int x = 20; // Initialize x
   change(&x); // Pass the address of x to the change function
   printf("x after change=%d\n", x); // Print the modified value of x

   return 0;
   
}
