#include <stdio.h>

// Function to perform binary search
// list: the array to search in
// endPtr: pointer to the last element in the list
// target: the value to search for
// locnPtr: pointer to a pointer that will hold the address of the found element if found
int binarySearch(int list[], int* endPtr, int target, int** locnPtr) {
  int* firstPtr;  // Pointer to the first element in the search range
  int* midPtr;    // Pointer to the middle element in the search range
  int* lastPtr;   // Pointer to the last element in the search range

  firstPtr = list;         // Initialize firstPtr to the start of the array
  lastPtr = endPtr;        // Initialize lastPtr to the end of the array

  // Perform binary search loop
  while (firstPtr <= lastPtr) {
    // Calculate midPtr by finding the midpoint between firstPtr and lastPtr
    midPtr = firstPtr + (lastPtr - firstPtr) / 2;

    // Compare target with the value at midPtr
    if (target > *midPtr) {
      // If target is greater than midPtr value, move the firstPtr to the right half
      firstPtr = midPtr + 1;
    } else if (target < *midPtr) {
      // If target is smaller than midPtr value, move the lastPtr to the left half
      lastPtr = midPtr - 1;
    } else {
      // If target is equal to midPtr value, target is found
      *locnPtr = midPtr;  // Update the locationPtr to point to the found element
      return 1;  // Return 1 (true) to indicate that the target was found
    }
  }

  // If target is not found in the list, set locnPtr to NULL
  *locnPtr = NULL;  // This is optional; just for clarity in case of not found
  return 0;  // Return 0 (false) to indicate that the target was not found
}

int main() {
  int list[] = {10, 20, 30, 40, 50, 60, 70, 80};  // Example array for binary search
  int* endPtr = &list[7];  // Pointer to the last element in the array (80)
  int* locationPtr;  // Pointer to hold the address of the target element if found
  int target = 40;  // Value to search for in the array

  // Perform binary search
  // Pass the address of locationPtr (using &locationPtr) so that binarySearch can modify
  // locationPtr to point to the found element if the target is found.
  int found = binarySearch(list, endPtr, target, &locationPtr);

  // Check if the target was found
  if (found) {
    // If found, print the index of the target element
    // Calculate the index by subtracting the base address of the array from the address of the found element
    printf("Target found at index: %ld\n", locationPtr - list);
  } else {
    // If not found, print a message
    printf("Target not found in the list.\n");
  }

  return 0;
}
