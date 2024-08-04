#include <stdio.h>

int main() {

   int i, j, m, n;

   printf("Enter the number of rows and columns: ");
   scanf("%d %d", &m, &n);

   int a[m][n];

   printf("Enter elements of the matrix:\n");
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &a[i][j]);
      }
   }

   int rowSum[m];
   int colSum[n];

   for (i = 0; i < m; i++) {
      rowSum[i] = 0;
   }
   
   for (j = 0; j < n; j++) {
      colSum[j] = 0;
   }

   for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            rowSum[i] += a[i][j];
            colSum[j] += a[i][j];
        }
    }

   printf("\nRow sums:\n");
   for (i = 0; i < m; i++) {
      printf("Sum of row %d: %d\n", i, rowSum[i]);
   }

   printf("\nColumn sums:\n");
   for (j = 0; j < n; j++) {
      printf("Sum of column %d: %d\n", j, colSum[j]);
   }

    return 0;

}
