#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

void insertAfter(struct Node* head, int target, int newData) {
    struct Node* temp = head;
    
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    struct Node* newNode = createNode(newData);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (*head_ref == temp) {
        *head_ref = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    displayList(head);

    insertAfter(head, 20, 25);
    displayList(head);

    deleteNode(&head, 25);
    displayList(head);

    deleteNode(&head, 10);
    displayList(head);

    deleteNode(&head, 40);
    displayList(head);

    return 0;
}