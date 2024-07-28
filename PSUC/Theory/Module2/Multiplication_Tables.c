#include <stdio.h>

int main() {

   int n, k; 
   int i, j, prod;

   printf("Enter the number of tables and the number of terms (e.g., 5 10): ");
   scanf("%d %d", &n, &k);
   
   for (i = 1; i <= k; i++) {
      for (j = 1; j <= n; j++) {
         // Calculate the product of the current table and term
         prod = i * j;
         // Print the multiplication result
         printf("%d * %d = %d\t", j, i, prod);
      }
      // Print a newline after each row of the multiplication table
      printf("\n");
   }

   return 0;

}


// If Using 3, 5 the outerloop using the variable i will run through 1-3 where as the innerloop will run from 1 - 5 hence we get this output: 

/*

1 * 1 = 1    2 * 1 = 2    3 * 1 = 3    
1 * 2 = 2    2 * 2 = 4    3 * 2 = 6    
1 * 3 = 3    2 * 3 = 6    3 * 3 = 9    
1 * 4 = 4    2 * 4 = 8    3 * 4 = 12   
1 * 5 = 5    2 * 5 = 10   3 * 5 = 15   

*/

