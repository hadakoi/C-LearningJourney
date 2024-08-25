#include <stdio.h>

int mul(int m, int n) {
   // Base case 1: If either number is 0, the result is 0
   if (m == 0 || n == 0)
      return 0;
    
   // Base case 2: If n is 1, the result is m
   if (n == 1)
      return m;

   // Recursive case: Multiply by adding m to the result of mul(m, n-1)
   else {
      int y = mul(m, n - 1);
      return y + m;
   }
}

int main() {
   int num1, num2, result;

   printf("Enter two numbers to multiply: ");
   scanf("%d %d", &num1, &num2);

   result = mul(num1, num2);

   printf("The result of multiplying %d and %d is: %d\n", num1, num2, result);

    return 0;
}
