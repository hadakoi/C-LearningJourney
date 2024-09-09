#include <stdio.h>
#include <string.h>

typedef struct {
  char name[20];       // Array to store the student's name
  int midterm[3];      // Array to store three midterm exam scores
  int final_score;     // Integer to store the final exam score
} STUDENT;

int main() {
  STUDENT student;

  // Assign values to the structure's array members
  strcpy(student.name, "John Doe");  // Copy "John Doe" into the name array
  student.midterm[0] = 85;           // Assign first midterm score
  student.midterm[1] = 90;           // Assign second midterm score
  student.midterm[2] = 88;           // Assign third midterm score
  student.final_score = 92;          // Assign final exam score

  // Accessing array members using pointers
  int *pScores = student.midterm;    // pScores points to the first element of the midterm array
  // pScores now holds the address of student.midterm[0]
  // *(pScores) gives the value of student.midterm[0]
  // *(pScores + 1) gives the value of student.midterm[1]
  // *(pScores + 2) gives the value of student.midterm[2]
    
  int totalScores = *pScores + *(pScores + 1) + *(pScores + 2);  // Calculate total of midterm scores

  // Print the total of midterm scores
  printf("Total Midterm Scores: %d\n", totalScores);

  return 0;
}
