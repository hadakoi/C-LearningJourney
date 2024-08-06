#include <stdio.h>

long factorial(long a) {
   if (a == 0) // Base case: factorial of 0 is 1
      return 1;
   return a * factorial(a - 1); // Recursive case
}

int main() {

   long number;
    
   printf("Please enter the number: ");
   scanf("%ld", &number); // Use %ld for long integers

   long c = factorial(number);
    
   printf("%ld! = %ld\n", number, c);
    
   return 0;

}
