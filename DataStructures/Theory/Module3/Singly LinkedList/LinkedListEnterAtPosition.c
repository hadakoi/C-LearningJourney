#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *link;
} *NODE;

NODE NewNode(int item) {
    NODE TempNode = (NODE)malloc(sizeof(struct node));
    TempNode->info = item;
    TempNode->link = NULL; 
    return TempNode; 
}

void InsertAtPosition(NODE *head, int item, int position) {
    NODE newNode = NewNode(item);

    if (position == 0) { 
        newNode->link = *head;
        *head = newNode; 
        return;
    }

    NODE current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->link; 
    }

    if (current != NULL) {
        newNode->link = current->link; 
        current->link = newNode; 
    } 
    else {
        free(newNode); 
        printf("Position is out of bounds. Node not inserted.\n");
    }
}

void DisplayNode(NODE head) {
    NODE current = head; 
    while (current != NULL) { 
        printf("%d\n", current->info); 
        current = current->link; 
    }
}

int main() {
    NODE head = NULL;

    InsertAtPosition(&head, 1, 0); 
    InsertAtPosition(&head, 2, 1); 
    InsertAtPosition(&head, 3, 1);
    InsertAtPosition(&head, 4, 3); 

    printf("Linked List after insertions at specified positions:\n");
    DisplayNode(head); 

    NODE current = head;
    while (current != NULL) {
        NODE next = current->link; 
        free(current); 
        current = next; 
    }

    return 0;
}
