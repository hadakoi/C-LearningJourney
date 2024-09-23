#include <stdio.h>

// Function declaration
// This function takes two pointers to integers and returns a pointer to the smaller of the two integers.
int* smaller(int* px, int* py);

int main(void) {
  int a, b;  // Declare two integers to store user input
  
  printf("Enter Values for a, b: ");
  // Read input values for a and b
  scanf("%d %d", &a, &b);

  // Call the smaller function and initialize p with the pointer to the smaller value
  // The function receives the addresses of a and b and returns the address of the smaller value.
  int *p = smaller(&a, &b);

  // Print the smaller value by dereferencing the pointer p
  printf("Smaller value: %d\n", *p);

  return 0;  // Indicate that the program executed successfully
}

// Function definition
int* smaller(int* px, int* py) {
  // Compare the values pointed to by px and py
  // Return the pointer to the smaller value
  // The ternary operator checks which value is smaller and returns the corresponding pointer
  return (*px < *py ? px : py);
}

