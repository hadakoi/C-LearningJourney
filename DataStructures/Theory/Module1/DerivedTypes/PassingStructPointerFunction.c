#include <stdio.h>

// Define a structure for a fraction
typedef struct {
  int numerator;   // Numerator of the fraction
  int denominator; // Denominator of the fraction
} FRACTION;

// Function prototypes
void getFr(FRACTION *pFr);           // Function to get a fraction from user input
void multFr(FRACTION *pFr1, FRACTION *pFr2, FRACTION *pRes); // Function to multiply two fractions
void printFr(FRACTION *pRes);        // Function to print a fraction

int main() {
  FRACTION fr1, fr2, res;  // Declare variables of type FRACTION

  // Get two fractions from the user
  getFr(&fr1); // Pass address of fr1 to getFr
  getFr(&fr2); // Pass address of fr2 to getFr

  // Multiply the two fractions and store the result in res
  multFr(&fr1, &fr2, &res); // Pass addresses of fr1, fr2, and res to multFr

  // Print the result of the multiplication
  printFr(&res); // Pass address of res to printFr

  return 0;
}

// Function to get a fraction from user input
void getFr(FRACTION *pFr) {
  printf("Write fraction in the form of x/y: ");
  // Read numerator and denominator into the structure pointed to by pFr
  scanf("%d/%d", &pFr->numerator, &pFr->denominator);
}

// Function to multiply two fractions
void multFr(FRACTION *pFr1, FRACTION *pFr2, FRACTION *pRes) {
  // Perform multiplication and store result in the structure pointed to by pRes
  pRes->numerator = pFr1->numerator * pFr2->numerator;
  pRes->denominator = pFr1->denominator * pFr2->denominator;
}

// Function to print a fraction
void printFr(FRACTION *pRes) {
  // Print the fraction stored in the structure pointed to by pRes
  printf("%d/%d\n", pRes->numerator, pRes->denominator);
}
