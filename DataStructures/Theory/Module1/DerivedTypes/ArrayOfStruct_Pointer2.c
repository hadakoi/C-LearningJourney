#include <stdio.h>

#define SIZE 10

typedef struct {
    char name[25];
    int midterm[3];
    int final;
} STUDENT;

int main() {
  STUDENT stuary[SIZE];
  int i, j, sum = 0;
  float midtermAvg[3];
  STUDENT *pwalk;
  STUDENT *plast;

  // Initialize plast to point to the last element in the array
  plast = stuary + SIZE - 1;

  // Assume stuary is populated with data
  // For demonstration, we'll set some values
  for (i = 0; i < SIZE; i++) {
    stuary[i].midterm[0] = 60 + i;  // Example data
    stuary[i].midterm[1] = 65 + i;
    stuary[i].midterm[2] = 70 + i;
  }

  // Calculate the average for each midterm exam
  for (j = 0; j < 3; j++) {
    sum = 0;
    for (pwalk = stuary; pwalk <= plast; pwalk++) {
      sum = sum + pwalk->midterm[j];
    }
    midtermAvg[j] = sum / (float)SIZE;
    printf("Average for midterm %d: %.2f\n", j + 1, midtermAvg[j]);
  }

  return 0;
}
