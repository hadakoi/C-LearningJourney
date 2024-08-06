#include <stdio.h>

// Function prototype
int readNum(void);

int main() {

   int c;
   
   printf("Enter a number \n");
   c = readNum(); // Call the function to read an integer from the user
   printf("The number read is %d\n", c); // Print the number read
    
   return 0;
   
}

// Function definition
int readNum() {

   int z;
   scanf("%d", &z); // Read an integer from the user
   return z;       // Return the read integer
   
}
