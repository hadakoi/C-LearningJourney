#include <stdio.h>
#include <stdlib.h>

// comments will explain the concept completely.

int main() {
  
  // Step 1: Using malloc() to allocate memory dynamically for 5 integers.
  // Think of malloc like renting 5 empty storage boxes.
  // sizeof(int) ensures that each box is large enough to store an integer.
  // malloc(5 * sizeof(int)) allocates 5 such boxes.
  // malloc doesn't know what type of data you're storing, so it's like receiving 5 empty boxes with no labels.
  // (int*) is like putting a label on each box saying "These boxes are for integers."
  // int* ptr_malloc: This is the pointer (like the address) to the first box.
  int* ptr_malloc = (int*) malloc(5 * sizeof(int));

  // Checking if malloc succeeded in renting the memory space.
  // If malloc fails (e.g., not enough space), it returns NULL, meaning no storage was provided.
  if (ptr_malloc == NULL) {
    printf("Memory allocation using malloc failed!\n");
    return 1;  // Exit the program if malloc fails
  }

  // Assigning values to the 5 allocated boxes (using malloc).
  // Here, we are storing values 1 to 5 in the storage boxes (memory allocated).
  for (int i = 0; i < 5; i++) {
    ptr_malloc[i] = i + 1;  // Store numbers 1 to 5 in each box.
  }

  // Printing the values stored in the memory allocated by malloc.
  printf("Values stored using malloc:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", ptr_malloc[i]);  // Output should be 1 2 3 4 5
  }
  printf("\n");

  // Step 2: Using calloc() to allocate memory dynamically for 5 integers.
  // Think of calloc as renting 5 new storage boxes, but this time it clears the boxes before giving them to you.
  // This means that calloc initializes all allocated memory to zero, ensuring the boxes are empty.
  // calloc(5, sizeof(int)) gives you 5 boxes for integers and sets them all to zero.
  int* ptr_calloc = (int*) calloc(5, sizeof(int));

  // Checking if calloc succeeded in renting the memory space.
  if (ptr_calloc == NULL) {
    printf("Memory allocation using calloc failed!\n");
    free(ptr_malloc);  // Free previously allocated memory if calloc fails
    return 1;  // Exit the program if calloc fails
  }

  // Printing the values stored in the memory allocated by calloc.
  // Since calloc initializes the memory to zero, it should print 0s.
  printf("Values stored using calloc (should be all zeros):\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", ptr_calloc[i]);  // Output should be 0 0 0 0 0
  }
  printf("\n");

  // Step 3: Using realloc() to resize the memory allocated by malloc.
  // realloc is like upgrading the rental agreement.
  // Imagine you've rented 5 boxes with malloc, but now you need more space—say 10 boxes.
  // realloc tries to extend your current 5 boxes into 10.
  // If there’s enough space in the same area, realloc will extend it, otherwise, it will move the entire storage to a new bigger place.
  // realloc(ptr_malloc, 10 * sizeof(int)) increases the allocated space to hold 10 integers.
  ptr_malloc = (int*) realloc(ptr_malloc, 10 * sizeof(int));

  // Checking if realloc succeeded in resizing the memory space.
  if (ptr_malloc == NULL) {
    printf("Memory reallocation using realloc failed!\n");
    free(ptr_calloc);  // Free previously allocated memory before exiting
    return 1;  // Exit the program if realloc fails
  }

  // Assigning additional values to the new storage boxes.
  // The first 5 boxes still have the values 1 to 5.
  // Now, we are storing values 6 to 10 in the additional 5 boxes.
  for (int i = 5; i < 10; i++) {
    ptr_malloc[i] = i + 1;  // Store numbers 6 to 10 in the new portion of memory
  }

  // Printing the values stored in the reallocated memory (1 to 10).
  printf("Values after reallocating memory (should print 1 to 10):\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", ptr_malloc[i]);  // Output should be 1 2 3 4 5 6 7 8 9 10
  }
  printf("\n");

  // Step 4: Freeing the dynamically allocated memory after usage.
  // Think of this as canceling your rental agreement and returning all the storage boxes.
  // Free both the malloc/realloc and calloc allocated memory.
  free(ptr_malloc);  // Free memory allocated by malloc and resized by realloc
  free(ptr_calloc);  // Free memory allocated by calloc

  return 0;
}
