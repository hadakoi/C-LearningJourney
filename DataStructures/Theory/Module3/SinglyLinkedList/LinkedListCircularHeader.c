#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *link;
} *NODE;

NODE createNode(int value) {
  NODE newNode = (NODE)malloc(sizeof(struct node));
  newNode->value = value;
  newNode->link = NULL;
  return newNode;
}

void insertHead(NODE header, int value) {
  NODE newNode = createNode(value);
  NODE first = header->link;  // Points to the first node in the list
    
  newNode->link = first;     // New node points to the first node
  header->link = newNode;    // Header now points to the new node
}

void insertEnd(NODE header, int value) {
  NODE newNode = createNode(value);
  NODE last = header;
    
  // Traverse to the last node
  while (last->link != header) {
    last = last->link;
  }

  last->link = newNode;       // Last node points to the new node
  newNode->link = header;     // New node points back to the header (circular)
}

void deleteHead(NODE header) {
  if (header->link == header) {
    printf("List is empty!\n");
    return;
  }

  NODE first = header->link;
  header->link = first->link;  // Header now points to the second node
  free(first);                 // Free the first node
}

void deleteEnd(NODE header) {
  if (header->link == header) {
    printf("List is empty!\n");
    return;
  }

  NODE last = header;
  // Traverse to the second-last node
  while (last->link->link != header) {
    last = last->link;
  }

  NODE lastNode = last->link;
  last->link = header;         // Second-last node now points to the header
  free(lastNode);              // Free the last node
}

void display(NODE header) {
    if (header->link == header) {
        printf("List is empty!\n");
        return;
    }

    NODE temp = header->link;  // Start from the first node
    do {
        printf("%d ", temp->value);
        temp = temp->link;     // Move to the next node
    } while (temp != header);  // Continue until we loop back to the header
    printf("\n");
}

int main() {
    NODE header = createNode(0);  // Create a header node (dummy node)

    // Insert elements at the head
    insertHead(header, 10);
    insertHead(header, 20);
    insertHead(header, 30);
    printf("List after inserting at the head:\n");
    display(header);

    // Insert elements at the end
    insertEnd(header, 40);
    insertEnd(header, 50);
    printf("List after inserting at the end:\n");
    display(header);

    // Delete the head element
    deleteHead(header);
    printf("List after deleting the head:\n");
    display(header);

    // Delete the end element
    deleteEnd(header);
    printf("List after deleting the end:\n");
    display(header);

    return 0;
}
