#include <stdio.h>

void readMatrix(int matrix[][10], int rows, int cols) {
   printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         printf("Element [%d][%d]: ", i + 1, j + 1);
         scanf("%d", &matrix[i][j]);
      }
   }
}


void displayMatrix(int matrix[][10], int rows, int cols) {
   printf("The matrix (%d x %d) is:\n", rows, cols);
   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
         }
      printf("\n");
   }
}

void multiplyMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int r1, int c1, int c2) {
   for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
         result[i][j] = 0;
         for (int k = 0; k < c1; k++) {
            result[i][j] += matrix1[i][k] * matrix2[k][j];
         }
      }
   }
}

int main() {

   int r1, c1, r2, c2;
   int matrix1[10][10], matrix2[10][10], result[10][10];

   printf("Enter the number of rows and columns for the first matrix: ");
   scanf("%d %d", &r1, &c1);

   printf("Enter the number of rows and columns for the second matrix: ");
   scanf("%d %d", &r2, &c2);

   if (c1 != r2) {
      printf("Matrices cannot be multiplied. Number of columns in the first matrix must equal the number of rows in the second matrix.\n");
      return 1;
   }

   readMatrix(matrix1, r1, c1);
   readMatrix(matrix2, r2, c2);

   printf("First Matrix:\n");
   displayMatrix(matrix1, r1, c1);

    printf("Second Matrix:\n");
    displayMatrix(matrix2, r2, c2);

   multiplyMatrices(matrix1, matrix2, result, r1, c1, c2);

   printf("Product of the matrices:\n");
   displayMatrix(result, r1, c2);

   return 0;

}
