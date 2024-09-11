/*
Write a function Reverse to reverse the elements of an integer array using pointer.
Access the elements of the array using dereference operator. Read the values from
the keyboard in main function. Display the result in the main function.
*/

#include <stdio.h>
#include <stdlib.h>

void Reverse(int arr[], int length);

int main(){

  int n, i;
  printf("Please enter Number of values for the Array: ");
  scanf("%d", &n);

  int* arr = (int*)calloc(n, sizeof(int));

  for(i = 0; i < n ; i++){
    printf("Enter element for index %d: ", i+1);
    scanf("%d", &arr[i]);
  }


  printf("Original Array: \n");
  for(i = 0; i < n ; i++){
    printf("%d ", arr[i]);
  }

  Reverse(arr, n);

  printf("\n");

  printf("Reversed Array: \n");
  for(i = 0; i < n ; i++){
    printf("%d ", arr[i]);
  }

  free(arr);

  return 0;

}

void Reverse(int arr[], int length){

  int *ptr = arr;
  int i, temp;

  // Reverse the array using pointers
  for(i = 0; i < length / 2; i++){
    // Swap elements using dereference operator
    temp = *(ptr + i);
    *(ptr + i) = *(ptr + length - i - 1);
    *(ptr + length - i - 1) = temp;
  }

}

