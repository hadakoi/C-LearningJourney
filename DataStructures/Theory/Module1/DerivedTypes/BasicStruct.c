#include <stdio.h>
#include <string.h>  // Required for strcpy

// Define the struct with typedef, without a tag name
typedef struct {
  char id[10];   // Identifier for storing the student ID
  char name[20]; // Identifier for storing the student name
  float gpa;     // Identifier for storing the student's GPA
} STUDENT;  // 'STUDENT' is the new type name

// Function to print student details
void print_Student(STUDENT stu) {
  printf("Student ID: %s\n", stu.id);
  printf("Student Name: %s\n", stu.name);
  printf("Student GPA: %.2f\n", stu.gpa);  // Using %.2f to format GPA as a floating-point number
}

int main() {
  // Declare a student
  STUDENT astudent; // 'astudent' is a variable of type 'STUDENT'
    
  // Assign values to the student struct
  strcpy(astudent.id, "S123456");  // Assign student ID
  strcpy(astudent.name, "John Doe");  // Assign student name
  astudent.gpa = 3.75;  // Assign student GPA
    
  // Call the function to print the student's details
  print_Student(astudent);
    
  return 0;
}

