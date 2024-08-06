#include <stdio.h>

// Function to compute Fibonacci numbers recursively
int rfibo(int n) {
    if (n <= 1) {
        return 1;
    }
    return rfibo(n - 1) + rfibo(n - 2);
}

int main(void) {

   int n, i, fibo;

   printf("Enter the number of terms for Fibonacci series: ");
   scanf("%d", &n); 

   printf("Fibonacci series: ");
   for (i = 1; i <= n; i++) {
      fibo = rfibo(i);
      printf("%d ", fibo); // Added space for better readability
   }
   printf("\n"); // Newline for clean output

    return 0;
}
