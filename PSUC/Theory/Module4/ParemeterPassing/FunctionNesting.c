#include <stdio.h>

void fnOpr(int a, int b, int *sum, int *diff);
int fnDiff(int p, int q);

int main() {

   int x, y, s, d;
    
   printf("Enter the values: \n");
   scanf("%d %d", &x, &y);

   fnOpr(x, y, &s, &d);

   printf("The results are, Sum = %d and Diff = %d\n", s, d);
    
   return 0;
   
}

// Function to compute sum and difference
void fnOpr(int a, int b, int *sum, int *diff) {
    *sum = a + b; // Compute sum
    
    // Use fnDiff to determine how to compute the difference
    if (fnDiff(a, b)) 
        *diff = a - b;
    else 
        *diff = b - a;
}

// Function to check if p is greater than q
int fnDiff(int p, int q) {
    if (p > q)
        return 1; // Return 1 if p is greater than q
    else
        return 0; // Return 0 otherwise
}
