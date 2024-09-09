#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int midterm[3];
    int final_score;
} STUDENT;

int main() {
  STUDENT student;

  // Assign values to the structure's array members
  strcpy(student.name, "John Doe");
  student.midterm[0] = 85;
  student.midterm[1] = 90;
  student.midterm[2] = 88;
  student.final_score = 92;

  // Accessing the array members
  printf("Student Name: %s\n", student.name);
  printf("Midterm 1: %d\n", student.midterm[0]);
  printf("Midterm 2: %d\n", student.midterm[1]);
  printf("Midterm 3: %d\n", student.midterm[2]);
  printf("Final Score: %d\n", student.final_score);

  return 0;
}
