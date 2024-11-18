#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *link;
  struct node *prev;
} *NODE;

NODE createNode(int value) {
  NODE TempNode = (NODE)malloc(sizeof(struct node));
  TempNode->value = value;
  TempNode->link = TempNode;  // Initially points to itself (circular)
  TempNode->prev = TempNode;  // Initially points to itself (circular)
  return TempNode;
}

void insertHead(NODE *head, int value) {
  NODE NewNode = createNode(value);

  if (*head == NULL) {
    *head = NewNode;  // If the list is empty, the new node is the head.
  } else {
    NewNode->link = *head;               // New node's link points to current head
    NewNode->prev = (*head)->prev;       // New node's prev points to the last node
    (*head)->prev->link = NewNode;       // Last node's link points to the new node
    (*head)->prev = NewNode;             // Head's prev points back to the new node
    *head = NewNode;                     // Finally, update *head to the new node
  }
}

void insertEnd(NODE *head, int value) {
  NODE NewNode = createNode(value);

  if (*head == NULL) {
    *head = NewNode;  // If the list is empty, the new node becomes the head.
  } else {
    NewNode->link = *head;               // New node points to head (circular linking)
    NewNode->prev = (*head)->prev;       // New node's prev points to the last node
    (*head)->prev->link = NewNode;       // Last node's link points to the new node
    (*head)->prev = NewNode;             // Head's prev now points to the new node (last node)
  }
}

void DeleteHead(NODE *head) {
  if (*head == NULL) {
    return;
  }

  NODE temp = *head;

  if (*head == (*head)->link) {
    // Only one node in the list
    free(*head);
    *head = NULL;
  } else {
    // Update the head and links to remove the old head
    (*head)->prev->link = (*head)->link;
    (*head)->link->prev = (*head)->prev;
    *head = (*head)->link;
    free(temp);
  }
}

void DeleteEnd(NODE *head) {
  if (*head == NULL) {
    return;
  }

  NODE temp = (*head)->prev;

  if (*head == (*head)->link) {
    // Only one node in the list
    free(*head);
    *head = NULL;
  } else {
    // Remove the last node and update the links
    (*head)->prev = temp->prev;
    temp->prev->link = *head;
    free(temp);
  }
}

void Display(NODE *head) {
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }

  NODE tempNode = *head;
  do {
    printf("%d ", tempNode->value);
    tempNode = tempNode->link;
  } while (tempNode != *head);  // Stop when we reach the head again
  printf("\n");
}

int main() {
  NODE head = NULL;

  insertHead(&head, 10);
  insertHead(&head, 20);
  insertHead(&head, 30);

  printf("List after inserting at the head: \n");
  Display(&head);

  insertEnd(&head, 40);
  insertEnd(&head, 50);

  printf("List after inserting at the end: \n");
  Display(&head);

  DeleteHead(&head);
  printf("List after deleting the head: \n");
  Display(&head);

  DeleteEnd(&head);
  printf("List after deleting the end: \n");
  Display(&head);

  return 0;
}
