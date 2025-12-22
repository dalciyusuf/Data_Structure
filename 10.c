#include <stdio.h>

#define MAX_SIZE 15

char tree[MAX_SIZE];

void initTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = '\0';
    }
}

void setRoot(char key) {
    if (tree[0] != '\0')
        printf("Kok zaten mevcut.\n");
    else
        tree[0] = key;
}

void setLeft(char key, int parentIndex) {
    if (tree[parentIndex] == '\0') {
        printf("Ebeveyn (Index %d) bulunamadi.\n", parentIndex);
    } else {
        int index = (parentIndex * 2) + 1;
        if (index < MAX_SIZE)
            tree[index] = key;
        else
            printf("Agac kapasitesi dolu.\n");
    }
}

void setRight(char key, int parentIndex) {
    if (tree[parentIndex] == '\0') {
        printf("Ebeveyn (Index %d) bulunamadi.\n", parentIndex);
    } else {
        int index = (parentIndex * 2) + 2;
        if (index < MAX_SIZE)
            tree[index] = key;
        else
            printf("Agac kapasitesi dolu.\n");
    }
}

void printTreeArray() {
    printf("Agac (Dizi Formati): ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] != '\0')
            printf("%c ", tree[i]);
        else
            printf("- ");
    }
    printf("\n");
}

void inOrderTraversal(int index) {
    if (index >= MAX_SIZE || tree[index] == '\0')
        return;

    inOrderTraversal((2 * index) + 1);
    printf("%c ", tree[index]);
    inOrderTraversal((2 * index) + 2);
}

int main() {
    initTree();

    setRoot('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setRight('F', 2);

    printTreeArray();

    printf("In-Order Gezinme: ");
    inOrderTraversal(0);
    printf("\n");

    return 0;
}