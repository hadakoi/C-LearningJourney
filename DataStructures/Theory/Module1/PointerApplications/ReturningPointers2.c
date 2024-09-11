#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a point in 2D space
struct Point {
  int x;
  int y;
};

// Function to create and return a pointer to a Point
struct Point* createPoint(int x, int y) {
  struct Point* p = (struct Point*)malloc(sizeof(struct Point));  // Allocate memory for a Point
  if (p == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;  // Return NULL if memory allocation fails
  }
  p->x = x;  // Assign x value
  p->y = y;  // Assign y value

  return p;  // Return the pointer to the Point
}

int main() {
  // Create a point using the function
  struct Point* p1 = createPoint(10, 20);

  // Display the point's coordinates
  if (p1 != NULL) {
    printf("Point: (%d, %d)\n", p1->x, p1->y);
    free(p1);  // Free the memory after use
  }

  return 0;
}
