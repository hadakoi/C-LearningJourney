#include <stdio.h>

#define SIZE 10

typedef struct {
  char name[25];
  int midterm[3];
  int final;
} STUDENT;

int main() {
  STUDENT stuary[SIZE];
  int i, sum = 0;
  float average;
  STUDENT *pwalk;
  STUDENT *plast;

  // Initialize plast to point to the last element in the array
  plast = stuary + SIZE - 1;

  // Assume stuary is populated with data
  // For demonstration, we'll set some values
  for (i = 0; i < SIZE; i++) {
    stuary[i].final = 50 + i;  // Example data
  }

  // Calculate the sum of final marks
  for (pwalk = stuary; pwalk <= plast; pwalk++) {
    sum = sum + pwalk->final;
  }

  // Calculate the average
  average = sum / (float)SIZE;

  // Print the average
  printf("Average of final marks: %.2f\n", average);

  return 0;
}
