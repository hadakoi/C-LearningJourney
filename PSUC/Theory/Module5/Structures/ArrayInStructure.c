#include <stdio.h>

#define MAX_SCORES 5

typedef struct {
    char name[50];
    int scores[MAX_SCORES];
    int numScores;
} Student;

// Function to initialize a Student structure with user input
void initializeStudent(Student s[], int index) {
   // Input name
   printf("Enter the student's name: ");
   scanf(" %[^\n]", s[index].name);  // Read a line of text including spaces

   // Input scores
   printf("Enter the number of scores (up to %d): ", MAX_SCORES);
   scanf("%d", &s[index].numScores);
   if (s[index].numScores > MAX_SCORES) {
      s[index].numScores = MAX_SCORES;
      printf("Number of scores exceeded maximum limit. Only the first %d scores will be accepted.\n", MAX_SCORES);
   }

   printf("Enter %d scores:\n", s[index].numScores);
   for (int i = 0; i < s[index].numScores; i++) {
      printf("Score %d: ", i + 1);
      scanf("%d", &s[index].scores[i]);
   }

   // Clear input buffer
   while (getchar() != '\n');
}

// Function to print a Student structure
void printStudent(Student s[], int index) {
   printf("Name: %s\n", s[index].name);
   printf("Scores:\n");
   for (int i = 0; i < s[index].numScores; i++) {
      printf("Score %d: %d\n", i + 1, s[index].scores[i]);
   }
}

// Function to calculate the average score of a Student
float calculateAverageScore(Student s[], int index) {
    int sum = 0;
    for (int i = 0; i < s[index].numScores; i++) {
      sum += s[index].scores[i];
   }
   return (float)sum / s[index].numScores;
}

int main() {
   
   Student students[1];  // Array of one Student structure

   // Initialize the student structure with user input
   initializeStudent(students, 0);

   // Print the student information
   printStudent(students, 0);

   // Calculate and print the average score
   float average = calculateAverageScore(students, 0);
   printf("Average score: %.2f\n", average);

   return 0;

}
