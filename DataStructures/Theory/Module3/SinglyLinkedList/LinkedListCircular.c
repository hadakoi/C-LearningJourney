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

void insertHead(NODE *head, int value) {
    NODE newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->link = *head;  // Points to itself for circular list
        return;
    }

    NODE temp = *head;
    while (temp->link != *head) {
        temp = temp->link;
    }

    temp->link = newNode;     // Last node points to new node
    newNode->link = *head;    // New node points to the head
    *head = newNode;          // Update head to new node
}

void insertEnd(NODE *head, int value) {
    NODE newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->link = *head;  // Points to itself for circular list
        return;
    }

    NODE temp = *head;
    while (temp->link != *head) {
        temp = temp->link;
    }

    temp->link = newNode;     // Last node points to new node
    newNode->link = *head;    // New node points back to the head
}

void deleteHead(NODE *head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    NODE last = *head;
    while (last->link != *head) {
        last = last->link;
    }

    if ((*head)->link == *head) {
        free(*head);
        *head = NULL;  // List is now empty
    } else {
        NODE temp = *head;
        *head = (*head)->link;  // Move head to next node
        last->link = *head;     // Last node points to new head
        free(temp);
    }
}

void deleteEnd(NODE *head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    NODE last = *head;

    if (last->link == *head) { // Only one node in the list
        free(*head);
        *head = NULL;  // List is now empty
    } else {
        while (last->link->link != *head) {
            last = last->link;
        }

        // `last` is now the second-last node
        free(last->link);     // Free the last node
        last->link = *head;    // Update second-last node to point to head
    }
}

void display(NODE head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    NODE temp = head;
    printf("%d ", temp->value);  // Print the head node's data first
    temp = temp->link;

    while (temp != head) {       // Continue until we loop back to the head
        printf("%d ", temp->value);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    NODE head = NULL;

    // Insert elements at the head
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);
    printf("List after inserting at the head:\n");
    display(head);

    // Insert elements at the end
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    printf("List after inserting at the end:\n");
    display(head);

    // Delete the head element
    deleteHead(&head);
    printf("List after deleting the head:\n");
    display(head);

    // Delete the end element
    deleteEnd(&head);
    printf("List after deleting the end:\n");
    display(head);

    return 0;
}
