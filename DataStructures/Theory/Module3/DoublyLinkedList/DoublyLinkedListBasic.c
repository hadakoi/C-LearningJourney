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
  TempNode->link = NULL;
  TempNode->prev = NULL;
  return TempNode;
}

void insertHead(NODE *head, int value) {
  NODE newNode = createNode(value);

  if (*head == NULL) {
    *head = newNode;  // If the list is empty, the new node becomes the head
    return;  // Exit as the insertion is complete
  }

  newNode->link = *head;  // Point the new node's link to the current head
  (*head)->prev = newNode; // Update the current head node's prev pointer to the new node
  *head = newNode;         // Update the head pointer to the new node
}


void insertEnd(NODE *head, int value) {
  NODE NewNode = createNode(value);

  if (*head == NULL) {
    *head = NewNode;
    return;
  }

  NODE TempNode = *head;
  while (TempNode->link != NULL) {
    TempNode = TempNode->link;
  }

  TempNode->link = NewNode;
  NewNode->prev = TempNode;
}

void DeleteHead(NODE *head) {
  if (*head == NULL) {
    return;
  }

  NODE temp = *head;
  *head = (*head)->link;
  if (*head != NULL) {
    (*head)->prev = NULL;
  }
  free(temp);
}

void DeleteEnd(NODE *head) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->link == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  NODE temp = *head;
  while (temp->link != NULL) {
    temp = temp->link;
  }

  temp->prev->link = NULL;
  free(temp);
}

void Display(NODE *head) {
  NODE tempNode = *head;
  while (tempNode != NULL) {
    printf("%d ", tempNode->value);
    tempNode = tempNode->link;
  }
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
