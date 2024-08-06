#include <stdio.h>

int fnSum(int x);

int main() {

   int n, sum = 0;
    
   printf("Enter the limit: ");
   scanf("%d", &n); 

   printf("The sum is %d\n", fnSum(n));

   return 0;

}

int fnSum(int x) {
    if (x == 1) // Base case: when x is 1, return 1
        return 1;
    else
        return fnSum(x - 1) + x; // Recursive case
}
