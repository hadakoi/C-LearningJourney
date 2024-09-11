/*
Write a C program to
a) Demonstrate passing pointers to a function.
b) Demonstrate Returning pointer from a function.
c) c) Using pointer to pointer.
*/

#include <stdio.h>
#include <stdlib.h>

// a) Demonstrating passing pointers to a function
// This function takes a pointer to an integer as an argument.
// It modifies the value that the pointer points to by adding 10.
void modifyValue(int *ptr) {
  // Dereference the pointer and modify the value it points to
  *ptr = *ptr + 10;  // *ptr means "the value at the memory address ptr points to"
}

// b) Demonstrating returning a pointer from a function
// This function dynamically allocates memory for an array of integers
// and returns a pointer to the first element of the array.
int* createArray(int size) {
  // Dynamically allocate memory for an array of 'size' integers
  int *arr = (int*)malloc(size * sizeof(int));  // malloc allocates 'size' times the size of an int

  // Initialize the array with values from 1 to 'size'
  for (int i = 0; i < size; i++) {
    arr[i] = i + 1;  // Set arr[i] to i + 1 (i.e., 1, 2, 3, ... up to size)
  }

  // Return the pointer to the first element of the array
  return arr;  // arr is a pointer to the allocated memory
}

// c) Demonstrating pointer to pointer
// This function takes a pointer to a pointer as an argument (int **ptr_to_ptr).
// It modifies the value that the pointer (int*) points to by changing it to 50.
void modifyPointerToPointer(int **ptr_to_ptr) {
  // Dereference the pointer to pointer to modify the value at the original pointer
  **ptr_to_ptr = 50;  // **ptr_to_ptr means "the value at the memory address the pointer to pointer points to"
}

int main() {

  // a) Passing pointers to a function
  // Initializing an integer variable
  int num = 10;

  // Display the original value of 'num'
  printf("Original Value: %d\n", num);

  // Call the modifyValue function, passing the address of 'num'
  // This will modify 'num' through the pointer
  modifyValue(&num);  // &num passes the address of 'num', so modifyValue can change its value directly

  // Display the modified value of 'num'
  printf("Modified Value: %d\n\n", num);

  // b) Returning pointer from a function
  // Initialize the size of the array
  int n = 5;

  // Call createArray to allocate memory for an array of 5 integers
  // The returned pointer points to the dynamically allocated array
  int *array = createArray(n);  // Store the returned pointer from createArray

  // Display the elements of the array
  printf("Array elements: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);  // array[i] is the same as *(array + i), dereferencing the pointer
  }
  printf("\n");

  // Free the dynamically allocated memory for the array to prevent memory leaks
  free(array);  // Always free dynamically allocated memory when you're done using it

  // c) Using pointer to pointer
  // Initialize an integer variable
  int x = 20;

  // Create a pointer to 'x'
  int *ptr = &x;  // ptr points to the memory address of 'x'

  // Display the original value of 'x' through the pointer
  printf("\nOriginal Value through pointer: %d\n", *ptr);  // Dereferencing the pointer to get the value of 'x'

  // Call modifyPointerToPointer and pass the address of 'ptr'
  // This allows the function to modify the value of 'x' indirectly
  modifyPointerToPointer(&ptr);  // &ptr passes the address of 'ptr', so the function can modify what 'ptr' points to

  // Display the modified value of 'x' through the pointer
  printf("Modified Value through pointer: %d\n", *ptr);  // The value of 'x' has been changed to 50

  return 0;
}
