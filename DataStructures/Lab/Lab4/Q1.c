/*
Use Pointers to structures and dynamic memory management functions in the following programs
Implement Complex numbers using structures. Write functions to add, multiply, subtract two complex numbers
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complex;


Complex* createComplex(double real, double imag) {

   Complex* c = (Complex*)malloc(sizeof(Complex));
   c->real = real;
   c->imag = imag;
   return c;

}

Complex* addComplex(Complex* c1, Complex* c2) {
   return createComplex(c1->real + c2->real, c1->imag + c2->imag);
}

Complex* subtractComplex(Complex* c1, Complex* c2) {
   return createComplex(c1->real - c2->real, c1->imag - c2->imag);
}

Complex* multiplyComplex(Complex* c1, Complex* c2) {
   double realPart = (c1->real * c2->real) - (c1->imag * c2->imag);
   double imagPart = (c1->real * c2->imag) + (c1->imag * c2->real);
   return createComplex(realPart, imagPart);
}

void printComplex(Complex* c) {
   if (c->imag < 0)
      printf("%2lf - %.2lfi\n", c->real, -c->imag);
   else
      printf("%2lf + %.2lfi\n", c->real, c->imag);
}



int main() {

   Complex* c1 = createComplex(3.0, 4.0);
   Complex* c2 = createComplex(1.0, 2.0);

   Complex* sum = addComplex(c1, c2);
   Complex* difference = subtractComplex(c1, c2);
   Complex* product = multiplyComplex(c1, c2);

   printf("Complex number 1: ");
   printComplex(c1);
   printf("Complex number 2: ");
   printComplex(c2);
   printf("Sum: ");
   printComplex(sum);
   printf("Difference: ");
   printComplex(difference);
   printf("Product: ");
   printComplex(product);

   return 0;
   
}
