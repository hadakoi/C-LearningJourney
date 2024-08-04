#include <stdio.h>
#include <stdlib.h>

int main() {

   int i, j;
   int m, n;

   printf("Enter dimensions (rows and columns):\n");
   scanf("%d %d", &m, &n);

   if (m != n) {
      printf("Enter a square matrix\n");
      exit(0);
   }

   int a[m][n];

   printf("Enter elements:\n");
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         scanf("%d", &a[i][j]);
      }
   }

   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         if (a[i][j] != a[j][i]) {
               printf("\nMatrix is not symmetric\n");
               exit(0);
         }
      }
   }

   printf("\nMatrix is symmetric\n");
   return 0;
   
}
