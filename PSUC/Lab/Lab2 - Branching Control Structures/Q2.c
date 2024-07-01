/*
With the help of various branching control constructs like if, if-else and switch case statements
Find the largest among given 3 numbers
*/

#include <stdio.h>

int main(){
   int a, b, c;
   int largest;

   printf("Enter three numbers: ");
   scanf("%d %d %d", &a, &b, &c);

  if (a >= b && a >= c) { // the && statement is literally 'and' is used to check wether both are true 
        largest = a;
    } else if (b >= a && b >= c) {
        largest = b;
    } else {
        largest = c;
    }
   
  printf("The largest number is: %d\n", largest);

  return 0;

}