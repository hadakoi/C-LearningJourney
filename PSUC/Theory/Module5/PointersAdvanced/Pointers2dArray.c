#include <stdio.h>

int main() {

   int i, j; 
   int (*p)[2];
   int a[][2] = {{12, 22}, {33, 44}};

    p = a;


   for (i = 0; i < 2; i++) {
      // Loop through columns
      for (j = 0; j < 2; j++) {
         // Access and print the element using pointer arithmetic
         printf("%d \t", *(*(p + i) + j));
      }
      printf("\n"); // Move to the next line after printing all columns of a row
    }

   return 0;
}


/*

*(p + i) : -> 

p: This is a pointer to an array of 2 integers. It initially points to the start of the 2D array a, which is the first row.
p + i: When you add i to p, you’re moving the pointer i rows down the array. In other words, if i is 1, p + 1 moves the pointer to the second row.

*(p + i): Dereferencing this gives you a pointer to the i-th row of the array. This is effectively a pointer to the beginning of the i-th row,
which is an array of 2 integers.

*/


/*

*(*(p + i) + j): ->

*(p + i): As explained, this is a pointer to the i-th row, which is an array of 2 integers.
*(p + i) + j: Adding j to this pointer moves the pointer j columns to the right within the i-th row. This points to the j-th element in that row.
*(*(p + i) + j): Dereferencing this final pointer gives you the value at the i-th row and j-th column of the 2D array.

*/
