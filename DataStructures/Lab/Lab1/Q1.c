/*
Given an array of distinct elements. The task is to find triplets in an array whose sum is zero. Take the array as input. (Triplets Game)
Sample Input
0 -1 2 -3 1
Sample output
0 -1 1
2 -3 1
*/

#include <stdio.h>

int main() {

   int n;
   printf("Enter the number of elements: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter the elements of the array: ");
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

    int found = 0;

   for (int i = 0; i < n-2; i++) {
      for (int j = i+1; j < n-1; j++) {
         for (int k = j+1; k < n; k++) {
               if (arr[i] + arr[j] + arr[k] == 0) {
                  printf("A triplet is -> %d %d %d\n", arr[i], arr[j], arr[k]);
                  found = 1;
               }
         }
      }
   }

   if (found != 1) {
      printf("No triplets found\n");
   }

   return 0;

}
