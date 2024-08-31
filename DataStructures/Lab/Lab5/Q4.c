/*
Given an array arr with n elements and a number k, k<n. The task is to delete k
elements which are smaller than next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than next because next element is deleted. 
Example:
Input: arr[] = {20, 10, 25, 30, 40}, k = 2
Output: 25 30 40
*/

#include <stdio.h>

void deleteElements(int arr[], int n, int k) {
   int stack[n];
   int top = -1;

   for (int i = 0; i < n; i++) {
      while (top >= 0 && k > 0 && stack[top] < arr[i]) {
         top--; 
         k--;   
      }
      stack[++top] = arr[i];
   }

   while (k > 0) {
      top--;
      k--;
   }

   for (int i = 0; i <= top; i++) {
      printf("%d ", stack[i]);
   }
   printf("\n");
}

int main() {
   int arr[] = {20, 10, 25, 30, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 2;

   deleteElements(arr, n, k);

   return 0;
}
