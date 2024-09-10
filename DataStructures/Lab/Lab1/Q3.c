/*
Implement an iterative Lsearch(….) function to search for an element in an 1D array
of type integer using linear search technique
*/

#include <stdio.h>

// Function to perform linear search
int Lsearch(int arr[], int size, int key) {
  // Iterating through the array
  for (int i = 0; i < size; i++) {
    // If the element is found, return its index
    if (arr[i] == key) {
      return i;
    }
  }
  // If element is not found, return -1
  return -1;
}

int main() {
  int size, key, result;

  // Input the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int arr[size];

  // Input the elements of the array
  printf("Enter the elements of the array:\n");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Input the element to search
  printf("Enter the element to search for: ");
  scanf("%d", &key);

  // Perform linear search
  result = Lsearch(arr, size, key);

  // Output the result
  if (result == -1) {
    printf("Element not found in the array.\n");
  } else {
    printf("Element found at index: %d\n", result);
  }

  return 0;
}
