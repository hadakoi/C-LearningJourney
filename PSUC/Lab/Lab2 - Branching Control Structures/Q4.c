/*
With the help of various branching control constructs like if, if-else and switch case statements
Find the smallest among three numbers using conditional operator.
*/

#include <stdio.h>

int main() {

   int a, b, c, smallest;

   printf("Enter three numbers: ");
   scanf("%d %d %d", &a, &b, &c);

   // Find the smallest using conditional operator
   smallest = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);

   /*

   Explanation -> 
   First it checks a < b if true it moves to (a < c) ? a : c 
      Now it checks if a < c if true then smallest is set to a else smallest is set to c
   If a < b is not true then it moves to (b < c) ? b : c
      Now it checks if b < c if true then smallest is set to b else smallest is set to c

   */

   printf("The smallest number is: %d\n", smallest);

   return 0;

}
