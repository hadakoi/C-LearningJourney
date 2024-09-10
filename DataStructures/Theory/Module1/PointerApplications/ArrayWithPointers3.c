#include <stdio.h>

int main() {
  // Define an array of 5 integers
  int arr[5] = {12, 7, 25, 3, 9};  
    
  // Pointer to the first element of the array (initially points to arr[0])
  int *pSm = arr;  
    
  // Pointer that will traverse the array (starting at the second element arr[1])
  int *pWalk;      

  // Loop through the array starting from the second element
  for (pWalk = arr + 1; pWalk < arr + 5; pWalk++) {
    // If the current element pointed to by pWalk is smaller than the one pointed by pSm
    if (*pWalk < *pSm) {
      // Update pSm to point to the current smaller element
      pSm = pWalk;  
    }
  }

  // Dereference pSm to print the smallest number found in the array
  printf("The smallest number is: %d\n", *pSm);
    
  return 0;
}
