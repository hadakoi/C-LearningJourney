#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node *prev;
    struct Node *next;
} *NODE;

NODE createNode(const char *word) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    strncpy(newNode->data, word, sizeof(newNode->data));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(NODE *head, const char *word) {
    NODE newNode = createNode(word);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    NODE temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void reverseList(NODE *head) {
    NODE current = *head;
    NODE temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

void displayList(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;

    insertEnd(&head, "Hello");
    insertEnd(&head, "world");
    insertEnd(&head, "from");
    insertEnd(&head, "ChatGPT");

    printf("Original List:\n");
    displayList(head);

    reverseList(&head);

    printf("Reversed List:\n");
    displayList(head);

    return 0;
}
