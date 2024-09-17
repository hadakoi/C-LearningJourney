#include<stdio.h>
#include<stdlib.h>

// Define the node structure
typedef struct node {
    int info;
    struct node *link;
} NODE;

// Function to push an element onto the stack
NODE* push(NODE *list, int x) {
  NODE *new = (NODE*)malloc(sizeof(NODE)); // Allocate memory for new node
  new->info = x; // Assign value to the new node
  new->link = list; // Link the new node to the current list (stack)
  return new; // Return the new node as the top of the stack
}

NODE* pop(NODE *list) {
  if(list == NULL) {
    printf("\nStack Underflow\n");
    return list;
  }
  NODE *temp = list; // Temporary pointer to hold the current top node
  printf("Deleted element is %d\n", temp->info); // Print the element being deleted
  list = list->link; // Move the top pointer to the next node
  free(temp); // Free the memory of the old top node
  return list; // Return the new top of the stack
}

void display(NODE *list) {
  if(list == NULL) {
    printf("\n\nSTACK: Stack is empty\n\n**********************************************\n");
    return;
  }
  NODE *temp = list;
  printf("\n\nSTACK: ");
  while(temp != NULL) {
    printf("%5d", temp->info); // Print the info of each node
    temp = temp->link; // Move to the next node
  }
  printf(" <- TOP\n\n**********************************************\n");
}

int getchoice() {
    int ch;
    printf("**********************************************\n\n");
    printf(" Menu \n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

int main() {
    NODE *list = NULL; // Initialize the stack (empty)
    int x, ch;

    while(1) { // Infinite loop for the menu
        ch = getchoice(); // Get the user's choice
        switch(ch) {
            case 1: // Push operation
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                list = push(list, x);
                display(list); // Display the stack after the push operation
                break;
            case 2: // Pop operation
                list = pop(list);
                display(list); // Display the stack after the pop operation
                break;
            case 3: // Display operation
                display(list);
                break;
            case 4: // Exit the program
                exit(1);
            default: // Handle invalid choices
                printf("\nInvalid choice\n\n**********************************************\n");
        }
    }

    return 0;
}
