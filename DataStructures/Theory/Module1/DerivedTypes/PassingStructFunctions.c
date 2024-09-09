#include <stdio.h>

// Define a structure for a fraction
typedef struct {
  int numerator;
  int denominator;
} FRACTION;

// Function declarations
FRACTION getFr();        // Function to get a fraction from user input
FRACTION multFr(FRACTION fr1, FRACTION fr2); // Function to multiply two fractions
void printFr(FRACTION result); // Function to print a fraction

int main() {
  FRACTION fr1, fr2, res;  // Declare variables of type FRACTION

  // Get two fractions from the user
  fr1 = getFr();
  fr2 = getFr();

  // Multiply the two fractions and store the result
  res = multFr(fr1, fr2);

  // Print the result of the multiplication
  printFr(res);

  return 0;
}

// Function to get a fraction from user input
FRACTION getFr() {
  FRACTION fr;  // Declare a variable of type FRACTION

  printf("Write fraction in the form of x/y: ");
  scanf("%d/%d", &fr.numerator, &fr.denominator);  // Read numerator and denominator

  return fr;  // Return the fraction
}

// Function to multiply two fractions
FRACTION multFr(FRACTION fr1, FRACTION fr2) {
  FRACTION res;  // Declare a variable to store the result

  // Perform multiplication
  res.numerator = fr1.numerator * fr2.numerator;
  res.denominator = fr1.denominator * fr2.denominator;

  return res;  // Return the result
}

// Function to print a fraction
void printFr(FRACTION res) {
  printf("%d/%d\n", res.numerator, res.denominator);  // Print the fraction
}