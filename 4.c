#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 


    if (left < size && heap[left] > heap[largest])
        largest = left;

    
    if (right < size && heap[right] > heap[largest])
        largest = right;

    
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        
       
        heapify(largest);
    }
}

void insert(int value) {
    if (size == MAX_SIZE) {
        printf("Heap dolu! Ekleme yapilamaz.\n");
        return;
    }

   
    heap[size] = value;
    int current = size;
    size++;


    while (current != 0 && heap[(current - 1) / 2] < heap[current]) {
        swap(&heap[(current - 1) / 2], &heap[current]);
        current = (current - 1) / 2;
    }
}

void deleteRoot() {
    if (size <= 0) {
        printf("Heap bos! Silinecek oge yok.\n");
        return;
    }

   
    int rootValue = heap[0];
    
    
    heap[0] = heap[size - 1];
    size--;

    
    heapify(0);

    printf("Kok silindi (%d). Yeni yapi duzenlendi.\n", rootValue);
}


void printHeap() {
    printf("Heap Yapisi (Dizi Hali): ");
    for (int i = 0; i < size; ++i)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    printf("--- Max Heap Uygulamasi ---\n");

    insert(10);
    insert(20);
    insert(5);
    insert(30); 
    insert(15);

    printHeap(); 

    printf("\nEn buyuk eleman siliniyor...\n");
    deleteRoot(); 

    printHeap();

    return 0;
}