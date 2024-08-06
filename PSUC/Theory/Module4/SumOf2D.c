#include <stdio.h>

int fn2d(int x[][10], int m, int n) { // when defining a function the value of columns of the 2d array must be passed which is 10 in this case.

   int i, j, sum = 0;

   for(i = 0; i < m; i++)
      for(j = 0; j < n; j++)
         sum += x[i][j];

   return sum;

}


int main() {

   int i, j, a[10][10], m, n;

   printf("Enter dimensions of matrix: ");
   scanf("%d%d", &m, &n);

   printf("Enter the elements:\n");
   for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
         scanf("%d", &a[i][j]);
      }
   }

   printf("Sum of elements is = %d\n", fn2d(a, m, n));

   return 0;

}
