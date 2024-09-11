#include <stdio.h>
#include <stdlib.h>

// Function to create an array of integers dynamically
int* createArray(int size) {
  int* array = (int*)malloc(size * sizeof(int));  // Allocating memory for 'size' integers
  if (array == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;  // Return NULL if memory allocation fails
  }
    
  // Initialize the array
  for (int i = 0; i < size; i++) {
    array[i] = i + 1;  // Assign values to the array elements
  }

  return array;  // Return the pointer to the dynamically allocated array
}

int main() {
  int size = 5;
  int* arr = createArray(size);  // Function returns a pointer to the array

  // Display the array
  if (arr != NULL) {
    for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
    }
    free(arr);  // Free the dynamically allocated memory after use
  }

  return 0;
}
