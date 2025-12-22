#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    printf("Liste: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(Basa dondu: %d)\n", head->data);
}

void insertEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref;
        return;
    }

    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head_ref;
}

void insertAfter(struct Node* head, int target, int newData) {
    struct Node* temp = head;
    struct Node* newNode;

    if (head == NULL) return;

    do {
        if (temp->data == target) {
            newNode = createNode(newData);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    struct Node *curr = *head_ref, *prev = NULL;

    if (curr->data == key) {
        if (curr->next == *head_ref) {
            *head_ref = NULL;
            free(curr);
            return;
        }
        
        struct Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }

        last->next = curr->next;
        *head_ref = curr->next;
        free(curr);
        return;
    }

    while (curr->next != *head_ref && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    }
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

    return 0;
}