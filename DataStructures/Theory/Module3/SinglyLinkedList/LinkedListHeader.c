#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *link;
} *NODE;

NODE createNode(int value) {
  NODE TempNode = (NODE)malloc(sizeof(struct node));
  TempNode->value = value;
  TempNode->link = NULL;
  return TempNode;
}

void insertHead(NODE header, int value) {
  NODE TempNode = createNode(value);
  TempNode->link = header->link;
  header->link = TempNode;
}

void insertEnd(NODE header, int value) {
  NODE NewNode = createNode(value);
  NODE TempNode = header;
  while (TempNode->link != NULL) {
    TempNode = TempNode->link;
  }
  TempNode->link = NewNode;
}

void DeleteHead(NODE header) {
  if (header->link == NULL) {
    return;
  }

  NODE temp = header->link;
  header->link = temp->link;
  free(temp);
}

void DeleteEnd(NODE header) {
    if (header->link == NULL) {
      return;
    }

    NODE temp = header;
    while (temp->link->link != NULL) {
      temp = temp->link;
    }

    free(temp->link);
    temp->link = NULL;
}

void Display(NODE header) {
  NODE tempNode = header->link;
  while (tempNode != NULL) {
    printf("%d ", tempNode->value);
    tempNode = tempNode->link;
  }
  printf("\n");
}

int main() {
  NODE header = (NODE)malloc(sizeof(struct node));
  header->link = NULL;

  insertHead(header, 10);
  insertHead(header, 20);
  insertHead(header, 30);

  printf("List after inserting at the head: \n");
  Display(header);

  insertEnd(header, 40);
  insertEnd(header, 50);

  printf("List after inserting at the end: \n");
  Display(header);

  DeleteHead(header);
  printf("List after deleting the head: \n");
  Display(header);

  DeleteEnd(header);
  printf("List after deleting the end: \n");
  Display(header);

  return 0;
}
