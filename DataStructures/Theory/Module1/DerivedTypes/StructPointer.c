#include <stdio.h>
#include <string.h>  // Required for strcpy

// Define the structure
typedef struct {
    char id[10];
    char name[20];
    float gpa;
} STUDENT;

int main() {
  STUDENT sam1;  // Declare a structure variable

  // Pointer to the structure
  STUDENT *ptr = &sam1;

  // Assign values using the pointer and dereferencing method
  strcpy((*ptr).id, "S123456");  // Using (*ptr).member
  strcpy((*ptr).name, "John Doe");
  (*ptr).gpa = 3.75;

  // Print the structure members
  printf("ID: %s\n", ptr->id);
  printf("Name: %s\n", ptr->name);
  printf("GPA: %.2f\n", ptr->gpa);
  
  printf("\n");
  // Assign values using the arrow operator
  strcpy(ptr->id, "S654321");  // Using ptr->member
  strcpy(ptr->name, "Jane Smith");
  ptr->gpa = 4.0;

  // Print the structure members
  printf("ID: %s\n", ptr->id);
  printf("Name: %s\n", ptr->name);
  printf("GPA: %.2f\n", ptr->gpa);

  return 0;
}
