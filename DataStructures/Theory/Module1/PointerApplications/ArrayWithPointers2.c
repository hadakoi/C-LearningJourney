#include <stdio.h>

int main() {
  // Define and initialize the array
  int arr[] = {10, 20, 30, 40, 50};

  // Define a pointer and initialize it to the first element of the array
  int *ptr = arr;  // Array name 'arr' points to the first element

  // Print the first element using index and pointer notation
  printf("Using array index: %d\n", arr[0]);   // Output: 10
  printf("Using pointer dereferencing: %d\n", *ptr); // Output: 10

  // Print the first element in the array using pointer arithmetic
  printf("Using pointer and array notation: %d\n", *(arr + 0)); // Output: 10

  // Now, let's demonstrate multiple names for referencing different array elements

  // Create a pointer to the second element of the array (arr[1])
  int *ptr2 = &arr[1];  // ptr2 points to the second element of the array

  // Print the first 2 elements using both array name and pointer
  printf("\nUsing array notation:\n");
  printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);  // Output: 10, 20

  printf("\nUsing pointer notation:\n");
  printf("ptr2[0] = %d, ptr2[1] = %d\n", ptr2[0], ptr2[1]);  // Output: 20, 30

  // Demonstrating negative index (valid pointer arithmetic but unsafe for arrays)
  printf("\nUsing pointer with negative index (unsafe):\n");
  printf("ptr2[-1] = %d\n", ptr2[-1]); // Output: 10 (ptr2[-1] is arr[0])

  return 0;
}
