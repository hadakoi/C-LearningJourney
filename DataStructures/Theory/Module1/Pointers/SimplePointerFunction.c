#include <stdio.h>

// Explanation:
// In C, passing the address of a variable to a function allows the function to directly access and modify the original variable.
// This is because the address is a pointer to the variable's location in memory. 
// The function receives a pointer (address) to the variable, which it can use to modify the value at that memory location.
// This simulates pass by reference, enabling functions to alter variables in the calling context.

// Function to modify the value of a variable using its address
void modify(int *x) {
  // *x dereferences the pointer x to access the actual variable
  *x = 10;  // Change the value at the memory address pointed to by x
}

int main() {
  int num = 5;  // Initialize num to 5
    
  // Pass the address of num to the modify function
  modify(&num);
    
  // The value of num in main() has been changed
  printf("%d", num);  // Output will be 10
  return 0;
}
