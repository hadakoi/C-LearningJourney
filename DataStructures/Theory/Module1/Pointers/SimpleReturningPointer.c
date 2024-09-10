#include <stdio.h>

// Function declaration
int* smaller(int* px, int* py);

int main(void) {
  int a, b;
  int* p;

  printf("Enter Values for a, b: ");
  // Read input values for a and b
  scanf("%d %d", &a, &b);

  // Call the smaller function and store the result
  p = smaller(&a, &b);

  // Print the smaller value
  printf("Smaller value: %d\n", *p);

  return 0;
}

// Function definition
int* smaller(int* px, int* py) {
  // Return a pointer to the smaller of the two values
  return (*px < *py ? px : py);  // Corrected to use ternary operator
}


// Why not use *p = smaller(&a, &b)? 
//
// The function `smaller` returns a pointer to an integer, not an integer itself.
// Therefore, `*p = smaller(&a, &b)` is incorrect because:
// 1. `*p` expects an integer value, but `smaller(&a, &b)` returns a pointer to an integer (i.e., an address).
// 2. Assigning a pointer value to `*p` would lead to a type mismatch. This is because `*p` is of type `int`, 
//    and you cannot directly assign a pointer (address) to an integer variable.
// 3. The correct usage involves assigning the returned pointer from `smaller` to `p`, and then using `*p`
//    to access the value at that address. So `p = smaller(&a, &b)` correctly assigns the address of the smaller 
//    value to `p`, and `*p` is used to access and print that value.
//
// Using *p = smaller(&a, &b) would cause a compilation error and incorrect behavior in the program.
