#include <stdio.h>

void printArray(int x[][3], int rows);

int main() {
   int array[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
   };
   
   printArray(array, 2);
   return 0;
}

void printArray(int x[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}
