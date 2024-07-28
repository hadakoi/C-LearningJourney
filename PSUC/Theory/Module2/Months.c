#include <stdio.h>

int main() {


   // Define an enum for the months of the year
   enum year { //enum can also be declared outside of the programme not necessarily inside
      Jan,  // Jan is represented by 0
      Feb,  // Feb is represented by 1
      Mar,  // Mar is represented by 2
      Apr,  // Apr is represented by 3
      May,  // May is represented by 4
      Jun,  // Jun is represented by 5
      Jul,  // Jul is represented by 6
      Aug,  // Aug is represented by 7
      Sep,  // Sep is represented by 8
      Oct,  // Oct is represented by 9
      Nov,  // Nov is represented by 10
      Dec   // Dec is represented by 11
   };

   int i;  // Declare an integer variable for the loop counter

   // Use a for loop to iterate through all the months
   for (i = Jan; i <= Dec; i++) {
      // Print the integer value of each month
      printf("%d ", i);
   }

   printf("\n");  // Print a newline character for better output formatting

   return 0;

}

/*
OutPut will be ->
0 1 2 3 4 5 6 7 8 9 10 11
*/