#include <stdio.h>
#include <stdlib.h>

int main() {
  // Step 1: Declare a double pointer 'table' to create an array of pointers
  // 'int** table' is a double pointer. It is a variable that will hold the address of an array of pointers.
  // Each pointer in this array will point to a different 1D array (each row of the ragged array).
  // Think of 'table' as a "list of addresses" where each address points to a row of integers.
  int** table;

  // Step 2: Allocate memory for 3 rows (3 pointers)
  // We're using malloc to allocate memory for 3 pointers (each pointer will later point to a 1D array).
  // 'sizeof(int*)' is the size of a single pointer to an integer. 
  // So, '3 * sizeof(int*)' reserves enough space to hold 3 addresses, which will each point to a row of integers.
  table = (int**) malloc(3 * sizeof(int*));

  // Check if memory allocation for rows was successful
  if (table == NULL) {
    printf("Memory allocation for rows failed!\n");
    return 1;  // Exit if allocation fails
  }

  // Step 3: Allocate memory for each row individually
  // Now, we allocate memory for each row separately.

  // First row: allocate space for 4 integers
  // 'int*' is a pointer to an integer. 
  // 'malloc(4 * sizeof(int))' reserves space for 4 integers.
  // 'table[0]' is a pointer to the first row of integers.
  table[0] = (int*) malloc(4 * sizeof(int));

  // Second row: allocate space for 2 integers
  // 'table[1]' is a pointer to the second row of integers.
  table[1] = (int*) malloc(2 * sizeof(int));

  // Third row: allocate space for 3 integers
  // 'table[2]' is a pointer to the third row of integers.
  table[2] = (int*) malloc(3 * sizeof(int));

  // Check if memory allocation for each row was successful
  if (table[0] == NULL || table[1] == NULL || table[2] == NULL) {
    printf("Memory allocation for one or more rows failed!\n");
    // Free previously allocated memory to avoid memory leaks
    free(table[0]);
    free(table[1]);
    free(table[2]);
    free(table);  // Free the array of pointers
    return 1;  // Exit if allocation fails
  }

  // Step 4: Fill in the rows with data
  // Assigning values to the first row (4 integers)
  table[0][0] = 1;
  table[0][1] = 2;
  table[0][2] = 3;
  table[0][3] = 4;

  // Assigning values to the second row (2 integers)
  table[1][0] = 5;
  table[1][1] = 6;

  // Assigning values to the third row (3 integers)
  table[2][0] = 7;
  table[2][1] = 8;
  table[2][2] = 9;

  // Step 5: Print the ragged array (each row has a different length)
  printf("Ragged array contents:\n");

  // Print the first row (4 elements)
  for (int i = 0; i < 4; i++) {
    printf("%d ", table[0][i]);
  }
  printf("\n");

  // Print the second row (2 elements)
  for (int i = 0; i < 2; i++) {
    printf("%d ", table[1][i]);
  }
  printf("\n");

  // Print the third row (3 elements)
  for (int i = 0; i < 3; i++) {
    printf("%d ", table[2][i]);
  }
  printf("\n");

  // Step 6: Free the dynamically allocated memory once done
  // Free the memory allocated for each row
  free(table[0]);  // Free memory for the first row
  free(table[1]);  // Free memory for the second row
  free(table[2]);  // Free memory for the third row

  // Finally, free the memory allocated for the array of pointers
  free(table);  // Free the array of pointers itself

  return 0;
}
