#include <stdio.h>

// Function prototype
long factFn(int num);

int main() {

   int n;
   long f;
    
   printf("Enter a number: ");
   scanf("%d", &n);
    
   f = factFn(n); // Call the factorial function
   printf("Fact = %ld\n", f); // Print the result
    
   return 0;
   
}

// Function definition
long factFn(int num) {

   int i;
   long fact = 1;
    
   // Factorial computation
   for (i = 1; i <= num; i++) {
      fact *= i;
   }
   // Return the result
   return fact;

}
