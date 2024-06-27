/*
Write a C program to display the size of the data type int, char, float, double, long int and long double using size of ( ) operator.
*/

#include <stdio.h>

int main(){ 
    
   printf("Size of int: %zu bytes\n", sizeof(int)); // Identifier is %d or %i
   printf("Size of char: %zu byte\n", sizeof(char)); // Identifier is %c
   printf("Size of float: %zu bytes\n", sizeof(float));  // Identifier is %f
   printf("Size of double: %zu bytes\n", sizeof(double)); // Identifier is %lf
   printf("Size of long int: %zu bytes\n", sizeof(long int)); // Identifier is %ld
   printf("Size of long double: %zu bytes\n", sizeof(long double)); // Identifier is %Lf

   return 0;
   
}
