/*
Write a C program to print the ASCII value of a character
*/

#include <stdio.h>
 
int main(){

   char c; // Declaration for a Character

   printf("Enter a Character: ");
   scanf("%c", &c); // Enters a character 

   printf("The Ascii value of %c is : %d", c, c); // using %d for a character variable helps represent it in Ascii format

   return 0;
}
