#include <stdio.h>

int main() {

   int N, i, fact = 1;

   printf("Enter the number: ");
   scanf("%d", &N);

   // For loop to calculate the factorial
   for (i = 1; i <= N; i++) {
      fact = fact * i; // Multiply fact by i
   } 
   // i keeps increasing with every iteration for example in the first iteration 1(fact) x 1(i) = 1(fact) then in the seconed 1(fact) x 2(i) = 2(fact) then in the third  2(fact) x 3(i)= 6(fact) and so on.

   printf("The factorial is %d\n", fact);

   return 0; 
   
}
