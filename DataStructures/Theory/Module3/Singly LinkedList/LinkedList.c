#include <stdio.h>
#include <stdlib.h>

// Define the NODE structure using typedef
typedef struct node {
    int info;
    struct node *link;
} NODE;

NODE* NewNode(int item){
  NODE *TempNode = (NODE *)malloc(sizeof(NODE));

  TempNode->info = item;
  TempNode->link = NULL;

  return TempNode;

}

void DisplayNode(NODE *head){

  NODE *current = head;

  while(current != NULL){
    printf("%d", current->info);
    current = current->link;
    printf("\n");
  }
}

int main(){
  NODE *head;
  NODE *second;
  NODE *last;

  head = NewNode(1);
  second = NewNode(2);
  last = NewNode(3);

  head->link = second;
  second->link = last;

  printf("Linked List: \n");
  DisplayNode(head);
  return 0;
}