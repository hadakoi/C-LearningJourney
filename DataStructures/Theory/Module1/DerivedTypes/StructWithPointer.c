#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the DATE structure with a pointer for the month
typedef struct {
  char *month;
  int day;
  int year;
} DATE;

// Function to initialize a DATE structure
void initDate(DATE *date, const char *monthName, int day, int year) {
  date->month = malloc(strlen(monthName) + 1);  // Allocate memory for the month name
  if (date->month != NULL) {
    strcpy(date->month, monthName);  // Copy the month name into allocated memory
  }
  date->day = day;
  date->year = year;
}

// Function to print the DATE structure
void printDate(const DATE *date) {
  printf("Date: %s %d, %d\n", date->month, date->day, date->year);
}



int main() {
  // Define month names
  char jan[] = "January";
  char feb[] = "February";
  // Other months can be added similarly

  // Create and initialize DATE structures
  DATE stamp1;
  initDate(&stamp1, jan, 1, 2024);

  DATE stamp2;
  initDate(&stamp2, feb, 14, 2024);

  printDate(&stamp1);
  printDate(&stamp2);

  return 0;
}
