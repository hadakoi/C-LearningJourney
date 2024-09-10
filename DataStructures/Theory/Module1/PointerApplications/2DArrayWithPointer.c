#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
  // Define and initialize a 2D array
  int table[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  // Pointer to the 2D array
  int (*ptr)[COLS] = table;

  printf("Using index notation:\n");
  // Print the 2D array using index notation
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", table[i][j]);
    }
  printf("\n");
  }

  printf("\nUsing pointer notation:\n");
  // Print the 2D array using pointer notation
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      // Access and print the element using pointer notation
      // Explanation of *(*(ptr + i) + j):
      // ptr: pointer to the first row of the 2D array
      // ptr + i: moves the pointer to the start of the i-th row
      // *(ptr + i): dereferences to get a pointer to the start of the i-th row
      // *(ptr + i) + j: moves the pointer to the j-th column within the i-th row
      // *(*(ptr + i) + j): dereferences to get the value at the i-th row and j-th column
      printf("%d ", *(*(ptr + i) + j));  // Print the element at [i][j]
    }
    printf("\n");
  }

  return 0;
}
