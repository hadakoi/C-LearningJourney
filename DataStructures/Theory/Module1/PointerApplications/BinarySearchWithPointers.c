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

  firstPtr = list;         // Initialize firstPtr to point to the first element of the array (start of search range)
  lastPtr = endPtr;        // Initialize lastPtr to point to the last element of the array (end of search range)

  // Perform binary search loop
  while (firstPtr <= lastPtr) {
    // Calculate midPtr by finding the midpoint between firstPtr and lastPtr
    // Using pointer arithmetic: (lastPtr - firstPtr) gives the number of elements between them, divided by 2 to find midpoint
    midPtr = firstPtr + (lastPtr - firstPtr) / 2;

    // Compare target with the value at midPtr
    if (target > *midPtr) {
      // If target is greater than the value at midPtr, search the right half by moving firstPtr forward
      firstPtr = midPtr + 1;
    } else if (target < *midPtr) {
      // If target is smaller than the value at midPtr, search the left half by moving lastPtr backward
      lastPtr = midPtr - 1;
    } else {
      // If target is equal to midPtr value, target is found
      // *locnPtr = midPtr:
      // Here, we update the pointer that was passed from `main` to point to the location of the found element
      *locnPtr = midPtr;  // Dereferencing locnPtr allows us to modify the original pointer in `main`
      return 1;  // Return 1 (true) to indicate that the target was found
    }
  }

  // If target is not found in the list, set locnPtr to NULL to indicate no result
  *locnPtr = NULL;  // This ensures that locationPtr in `main` is set to NULL if the target isn't found
  return 0;  // Return 0 (false) to indicate that the target was not found
}

int main() {
  // Example array for binary search
  int list[] = {10, 20, 30, 40, 50, 60, 70, 80};  // Sorted array to search
  int* endPtr = &list[7];  // Pointer to the last element in the array (80)
  int* locationPtr;  // Pointer that will store the address of the found element if the target is found
  int target = 40;  // The value we are searching for in the array

  // Perform binary search
  // Pass the address of locationPtr (using &locationPtr) so that binarySearch can modify it if the target is found
  // This allows binarySearch to update locationPtr in `main` to point to the found element
  int found = binarySearch(list, endPtr, target, &locationPtr);

  // Check if the target was found
  if (found) {
    // If found, print the index of the target element
    // We calculate the index by subtracting the base address of the array (list) from the address of the found element (locationPtr)
    // This works because subtracting two pointers gives the number of elements between them
    printf("Target found at index: %ld\n", locationPtr - list);
  } else {
    // If the target was not found, print a message
    printf("Target not found in the list.\n");
  }

  return 0;
}
