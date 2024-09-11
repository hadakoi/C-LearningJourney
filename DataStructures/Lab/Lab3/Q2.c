/*
Write a function Smallest to find the smallest element in an array using pointer.
Create a dynamically allocated array and read the values from keyboard in main.
Display the result in the main function
*/

#include <stdio.h>
#include <stdlib.h>

int Smallest(int arr[], int n);

int main(){
  int n, i, d;

  printf("Please enter Number of values for the Array: ");
  scanf("%d", &n);

  int *arr = (int*)calloc(n, sizeof(int));

  for(i = 0; i < n ; i++){
    printf("Enter element for index %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  int result = Smallest(arr, n);

  printf("The Smallest value is %d", result);

  free(arr);

  return 0;

}

int Smallest(int arr[], int n){

  int smallest;
  int *p = arr;

  smallest = *p;

  for(p = arr + 1; p < arr + n; p++){ // Start from the second element
    if(*p < smallest){
      smallest = *p; // Update the smallest if a smaller element is found
    }
  }

  return smallest;

}