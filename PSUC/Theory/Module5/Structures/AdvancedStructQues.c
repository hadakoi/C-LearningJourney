#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LENGTH 30

// Define the structure for student information
typedef struct {
    int rollno;                // Student's roll number
    char name[NAME_LENGTH];    // Student's name
    float grades[3];           // Array to store grades for 3 subjects
} Student;

// Function prototypes
void inputStudentDetails(Student students[], int count);
void sortStudentsByName(Student students[], int count);
void calculateAndPrintAverages(Student students[], int count);
void printStudentDetails(Student s);

int main() {

   Student students[MAX_STUDENTS];
   int numStudents;

   printf("Enter the number of students (up to %d): ", MAX_STUDENTS);
   scanf("%d", &numStudents);


   if (numStudents > MAX_STUDENTS) {
      printf("Number exceeds the maximum limit of %d students.\n", MAX_STUDENTS);
      return 1;
   }


   inputStudentDetails(students, numStudents);


   sortStudentsByName(students, numStudents);


   calculateAndPrintAverages(students, numStudents);

   return 0;

}

// Function to input student details
void inputStudentDetails(Student students[], int count) {
   for (int i = 0; i < count; i++) {
      printf("\nEnter details for student %d:\n", i + 1);
      printf("Roll Number: ");
      scanf("%d", &students[i].rollno);
      printf("Name: ");
      scanf(" %[^\n]", students[i].name); // Read string with spaces
      for (int j = 0; j < 3; j++) {
         printf("Grade for subject %d: ", j + 1);
         scanf("%f", &students[i].grades[j]);
      }
   }
}

// Function to sort students by their names using bubble sort
void sortStudentsByName(Student students[], int count) {
   Student temp;
   // Bubble sort algorithm to sort by name
   for (int i = 0; i < count - 1; i++) {
      for (int j = i + 1; j < count; j++) {
         // Compare names and swap if necessary
         if (strcmp(students[i].name, students[j].name) > 0) {
            // Swap students[i] and students[j]
            temp = students[i];
            students[i] = students[j];
            students[j] = temp;
         }
      }
   }
}


// Function to calculate and print average grades
void calculateAndPrintAverages(Student students[], int count) {
   printf("\nSorted student details:\n");
   for (int i = 0; i < count; i++) {
      // Print student details
      printStudentDetails(students[i]); // Pass by value, not by reference
      // Calculate average grade
      float avg = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2]) / 3.0;
      printf("Average Grade: %.2f\n", avg); // Print average with 2 decimal places
   }
}


// Function to print student details
void printStudentDetails(Student s) {
   printf("\nRoll Number: %d\n", s.rollno);
   printf("Name: %s\n", s.name);
   printf("Grades: %f, %f, %f\n", s.grades[0], s.grades[1], s.grades[2]);
}
