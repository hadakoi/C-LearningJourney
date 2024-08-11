#include <stdio.h>
#include <string.h>

// Define a structure to hold person information
struct Person {
   char name[50]; // Array to store the person's name
   int age;       // Integer to store the person's age
};

int main() {

   // Create an instance of the Person structure
   struct Person person1;
    
   // Create a pointer to the Person structure and initialize it to point to person1
   struct Person *ptr = &person1;

   // Use the pointer to set the name and age of the person
   strcpy(ptr->name, "Bob"); // Accesses the 'name' member of person1 through the pointer
   ptr->age = 30;            // Accesses the 'age' member of person1 through the pointer

   // Print out the values using the pointer
   printf("Name: %s\n", ptr->name); // Accesses the 'name' member of person1 through the pointer and prints it
   printf("Age: %d\n", ptr->age);   // Accesses the 'age' member of person1 through the pointer and prints it

   return 0;

}
