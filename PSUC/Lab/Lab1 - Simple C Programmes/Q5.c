/*
Input P, N and R to compute simple and compound interest. [Hint: SI = PNR/100, CI = P(1+R/100)N-P]
*/

#include <stdio.h>
#include <math.h> // Used to Import Math Functions

int main(){

   int P, N, R, SI, CI;

   printf("Enter the principal amount (P): ");
   scanf("%d", &P);
    
   printf("Enter the number of years (N): ");
   scanf("%d", &N);
    
   printf("Enter the rate of interest (R): ");
   scanf("%d", &R);
    
   // Calculate Simple Interest
   SI = (P * N * R) / 100;
    
   // Calculate Compound Interest
   CI = P * pow((1 + R / 100), N) - P; // The Power Functions work by using this format pow(x, n) = x^n
    
   // Print the results
   printf("Simple Interest (SI) = %d\n", SI);
   printf("Compound Interest (CI) = %d\n", CI);

}
