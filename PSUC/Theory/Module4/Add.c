#include <stdio.h> 

// Function prototype
int fnAdd(int x, int y);

int main() {
   int a, b, c;
    
   printf("\nEnter numbers to be added\n");
   scanf("%d %d", &a, &b);
    
   c = fnAdd(a, b); // Call the fnAdd function
   printf("Sum is %d\n", c); // Print the result
    
   return 0;

}

// Function definition
int fnAdd(int x, int y) {
   int z;
   z = x + y; // Add x and y
   return z;  // Return the result
}
