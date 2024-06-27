/*Q1 -> Write a C program to add two integers a and b read through the keyboard. Display the
result using third variable sum */

#include <stdio.h>

int main(){

int x, y, z; // Our 3 integers we are using for the addition

printf("Please Enter The First Number: ");
scanf("%d", &x);
// How the Values are Entered for x, &x signifies the value being inputted there. (%d is the identifier for integers)

printf("Please Enter The First Number: ");
scanf("%d", &y);

z = x + y; // Arithmatic addition
printf("The value of Adding %d and %d gives %d", x, y, z);
}

