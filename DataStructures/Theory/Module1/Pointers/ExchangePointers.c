#include <stdio.h>

// Function to exchange values of two variables using pointers
void exchange(int *a, int *b) {
  int temp = *a;  // Store the value at pointer 'a' in 'temp'
  *a = *b;        // Copy the value at pointer 'b' to pointer 'a'
  *b = temp;      // Assign the stored value in 'temp' to pointer 'b'
}

int main() {
  int x = 10, y = 20;

  printf("Before exchange: x = %d, y = %d\n", x, y);

  // Call the exchange function with addresses of x and y
  exchange(&x, &y);

  printf("After exchange: x = %d, y = %d\n", x, y);

  return 0;
}
