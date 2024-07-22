/*
With the knowledge of recursive functions, Structures and pointers
Create a student record with name, rollno, marks of 3 subjects (m1, m2, m3). Compute
the average of marks for 3 students and display the names of the students in ascending
order of their average marks.
*/

#include <stdio.h>
#include <string.h>

int main() {
   
    // Define a structure to hold student record
   typedef struct {
      char name[50];
      int rollno;
      float m1, m2, m3;
      float average;
    } Student;

   Student students[3];
   Student temp;

   // Input student records
   for (int i = 0; i < 3; i++) {

      printf("Enter details for student %d\n", i + 1);
        
      printf("Name: ");
      gets(students[i].name);
        
      printf("Roll number: ");
      scanf("%d", &students[i].rollno);
        
      printf("Marks in subject 1: ");
      scanf("%f", &students[i].m1);
        
      printf("Marks in subject 2: ");
      scanf("%f", &students[i].m2);
        
      printf("Marks in subject 3: ");
      scanf("%f", &students[i].m3);
        
      // Compute average for the student
      students[i].average = (students[i].m1 + students[i].m2 + students[i].m3) / 3.0;
        
      printf("\n");

   }
    
   // Sort students by average marks in ascending order
   for (int i = 0; i < 3 - 1; i++) {
      for (int j = i + 1; j < 3; j++) {
         if (students[i].average > students[j].average) {
               // Swap students[i] and students[j]
               temp = students[i];
               students[i] = students[j];
               students[j] = temp;
         }
      }
   }
    
    // Display names of students in ascending order of their average marks
   printf("Students in ascending order of their average marks:\n");
   for (int i = 0; i < 3; i++) {
      printf("%s (Average Marks: %.2f)\n", students[i].name, students[i].average);
   }
    
   return 0;
   
}
