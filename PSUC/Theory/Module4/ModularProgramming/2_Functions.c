#include <stdio.h>

void First() {
   printf("I am now inside function First\n");
}

void Second() {
   printf("I am now inside function Second\n");
   First(); // Call the First function
   printf("Back to Second\n");
}

int main() {

   printf("I am starting in function main\n");
   First();   // Call the First function
   printf("Back to main function\n");
   Second();  // Call the Second function
   printf("Back to main function\n");
   
   return 0;
}
