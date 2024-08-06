#include <stdio.h>

// Function prototype
int IsPrime(int num);

int main() {

   int n;
    
   printf("Enter a number: ");
   scanf("%d", &n);
    
   if (IsPrime(n))
      printf("%d is a prime number\n", n);
   else
      printf("%d is not a prime number\n", n);
    
   return 0;

}

// Function definition
int IsPrime(int num) {
 
   if (num <= 1) {
      return 0; // 0 and 1 are not prime numbers stops the function execution
   }
   for (int j = 2; j <= num / 2; j++) {
      if (num % j == 0) {
         return 0; // Not a prime number stops the function execution
      }
   }
   return 1; // Prime number
}
