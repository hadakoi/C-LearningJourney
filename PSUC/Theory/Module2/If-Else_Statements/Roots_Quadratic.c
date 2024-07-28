#include <stdio.h>
#include <math.h> // Required for sqrt() function

int main() {

   float a, b, c;
   float discriminant, root1, root2, realPart, imaginaryPart;

   
   printf("Enter coefficients a, b, and c: ");
   scanf("%f %f %f", &a, &b, &c);

   
   discriminant = b * b - 4 * a * c;

   // Determine the nature of the roots using if-else statements
   if (discriminant > 0) {
      // Two distinct real roots
      root1 = (-b + sqrt(discriminant)) / (2 * a);
      root2 = (-b - sqrt(discriminant)) / (2 * a);
      printf("Roots are real and different.\n");
      printf("Root 1 = %.2f\n", root1);
      printf("Root 2 = %.2f\n", root2);
   } 
   else if (discriminant == 0) {
      // One real root (repeated root)
      root1 = root2 = -b / (2 * a);
      printf("Roots are real and the same.\n");
      printf("Root 1 = Root 2 = %.2f\n", root1);
    } 
    else {
      // Two complex roots
      realPart = -b / (2 * a);
      imaginaryPart = sqrt(-discriminant) / (2 * a);
      printf("Roots are complex and different.\n");
      printf("Root 1 = %.2f + %.2fi\n", realPart, imaginaryPart);
      printf("Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart);
   }

   return 0;

}
