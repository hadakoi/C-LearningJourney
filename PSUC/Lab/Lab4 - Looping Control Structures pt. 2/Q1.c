/*
do the following with the help of iterative (looping) control structures
Generate the multiplication table for ‘n’ numbers up to ‘k’ terms (using nested for loops).
*/

#include <stdio.h>

int main() {
    
    int n, k;

    printf("Enter the number of multiplication tables you want to generate: ");
    scanf("%d", &n);
    printf("Enter the number of terms for each multiplication table: ");
    scanf("%d", &k);

   for (int i = 1; i <= n; ++i) {
      printf("Multiplication table for %d up to %d terms:\n", i, k);
      for (int j = 1; j <= k; ++j) {
         printf("%d x %d = %d\n", i, j, i * j);
      }
      printf("\n"); // Add a newline for better readability
    }

    return 0;

}

