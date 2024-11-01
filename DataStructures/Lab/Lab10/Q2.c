#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} *NODE;

typedef struct {
    NODE head; // Header node
} CircularDoublyLinkedList;

// Function to create a new node
NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular doubly linked list with a header node
CircularDoublyLinkedList* createList() {
    CircularDoublyLinkedList *list = (CircularDoublyLinkedList *)malloc(sizeof(CircularDoublyLinkedList));
    list->head = createNode(0); // Header node
    list->head->next = list->head;
    list->head->prev = list->head;
    return list;
}

// Function to insert a digit at the end of the list
void insertEnd(CircularDoublyLinkedList *list, int data) {
    NODE newNode = createNode(data);
    NODE last = list->head->prev;
    newNode->next = list->head;
    newNode->prev = last;
    last->next = newNode;
    list->head->prev = newNode;
}

// Function to add two long integers represented as circular doubly linked lists
CircularDoublyLinkedList* addNumbers(CircularDoublyLinkedList *num1, CircularDoublyLinkedList *num2) {
    CircularDoublyLinkedList *result = createList();
    NODE n1 = num1->head->prev; // Start from the last node
    NODE n2 = num2->head->prev; // Start from the last node
    int carry = 0;

    // Add digits until both lists are fully traversed and no carry remains
    while (n1 != num1->head || n2 != num2->head || carry > 0) {
        int digit1 = (n1 != num1->head) ? n1->data : 0;
        int digit2 = (n2 != num2->head) ? n2->data : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        insertEnd(result, sum); // Insert the result digit at the end

        // Move to the previous nodes
        if (n1 != num1->head) n1 = n1->prev;
        if (n2 != num2->head) n2 = n2->prev;
    }
    return result;
}

// Function to display the number represented by the circular doubly linked list
void display(CircularDoublyLinkedList *list) {
    NODE temp = list->head->next;
    while (temp != list->head) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the addition of two long integers
int main() {
    CircularDoublyLinkedList *num1 = createList();
    CircularDoublyLinkedList *num2 = createList();

    // Example numbers: num1 = 5678, num2 = 1234
    insertEnd(num1, 5);
    insertEnd(num1, 6);
    insertEnd(num1, 7);
    insertEnd(num1, 8);

    insertEnd(num2, 1);
    insertEnd(num2, 2);
    insertEnd(num2, 3);
    insertEnd(num2, 4);

    printf("Number 1: ");
    display(num1);

    printf("Number 2: ");
    display(num2);

    CircularDoublyLinkedList *result = addNumbers(num1, num2);

    printf("Sum: ");
    display(result);

    return 0;
}
