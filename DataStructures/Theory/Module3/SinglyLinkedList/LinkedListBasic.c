#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *link;
} *NODE;

NODE createNode(int value){
  NODE TempNode = (NODE)malloc(sizeof(struct node));

  TempNode->value = value;
  TempNode->link = NULL;

  return TempNode;
}

void insertHead(NODE *head, int value) {
  NODE TempNode = createNode(value);

  if (*head == NULL) {
    *head = TempNode;
  } else {
    TempNode->link = *head;
    *head = TempNode;
  }
}

void insertEnd(NODE *head, int value){
  NODE NewNode = createNode(value);
  if(*head == NULL){
    *head = NewNode;
    return;
  }

  NODE TempNode = *head;
  while(TempNode->link != NULL){
    TempNode = TempNode->link;
  }

  TempNode->link = NewNode;
}

void DeleteHead(NODE *head){
  if(*head == NULL){
    return;
  }

  NODE temp = *head;
  *head = (*head)->link;
  free(temp);
}

void DeleteEnd(NODE *head){
  if(*head == NULL){
    return;
  }
  if((*head)->link == NULL ){
    free(*head);
    *head = NULL;
    return;
  }

  NODE temp = *head;
  while(temp->link->link != NULL){
    temp = temp->link;
  }
  free(temp->link);
  temp->link = NULL;
}

void Display(NODE *head){
  NODE tempNode = *head;
  while(tempNode != NULL){
    printf("%d ", tempNode->value);
    tempNode = tempNode->link;
  }
  printf("\n");
}

int main() {
    NODE head = NULL;  // Initialize the head pointer to NULL

    // Insert elements at the head
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);

    printf("List after inserting at the head: \n");
    Display(&head);

    // Insert elements at the end
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("List after inserting at the end: \n");
    Display(&head);

    // Delete the head element
    DeleteHead(&head);
    printf("List after deleting the head: \n");
    Display(&head);

    // Delete the end element
    DeleteEnd(&head);
    printf("List after deleting the end: \n");
    Display(&head);

    return 0;
}